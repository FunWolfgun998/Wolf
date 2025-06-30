#include "parser/Parser.h"
#include "ast/nodes/AllNodes.h"
#include <set>


#include "parser/ParseError.h"
#include <stdexcept>

Parser::Parser(std::vector<Token> tokens)
    : tokens(std::move(tokens)), pos(0) {}

ASTNodePtr Parser::ParseTokens() {
    std::vector<ASTNodePtr> statements;

    while (!Is(TypeToken::End)) {
        consumeNewlines();
        statements.push_back(parseStatement());
    }

    return std::make_unique<ProgramNode>(std::move(statements));
}
void Parser::consumeNewlines() {
    while (Is(TypeToken::Newline)|| Is(TypeToken::Comment)) {
        consumeToken();
    }
}
/*
ASTNodePtr Parser::parseBlock() {
}
*/
// Helper functions implementation
const Token& Parser::currentToken() const {
    return tokens[pos];
}

const Token& Parser::consumeToken() {
    return tokens[pos++];
}

bool Parser::Is(TypeToken type) const {
    return tokens[pos].type == type;
}
bool Parser::IsNext(TypeToken type) const {
    return tokens[pos+1].type == type;
}
void Parser::expect(TypeToken type, const std::string& errorMsg) {
    if (!Is(type)) {
        throw std::runtime_error(errorMsg + ". Found: " + std::to_string(static_cast<int>(currentToken().type)));
    }
    consumeToken();
}
void Parser::peek(TypeToken type, const std::string& errorMsg) {
    if (!Is(type)) {
        throw std::runtime_error(errorMsg + ". Found: " + std::to_string(static_cast<int>(currentToken().type)));
    }
}

ASTNodePtr Parser::parseStatement() {
    consumeNewlines();
    if (isTypeToken(currentToken().type)) {
        return parseDeclaration();
    }
    if (Is(TypeToken::Identifier)) {
        if(IsNext(TypeToken::OpAssign)) {
            return parseAssignment();
        }
    }
    // Aggiungi qui altri tipi di statement...

    throw ParseError("Unexpected token at statement start");
}

ASTNodePtr Parser::parseDeclaration() {
    std::string typeStr = consumeToken().value;

    peek(TypeToken::Identifier, "Expected variable name");
    std::string Identifier = consumeToken().value;

    // Simple declaration (int x)
    if (isEndOfStatement()) {
        consumeNewlines();
        return std::make_unique<VariableDeclNode>(typeStr, Identifier);
    }

    // Initialization (int x = 42)
    if (Is(TypeToken::OpAssign)) {
        consumeToken();
        auto initValue = parseExpression();

        if (!isEndOfStatement()) {
            throw ParseError("Expected newline after initialization");
        }
        consumeNewlines();
        return std::make_unique<VariableInitNode>(typeStr, Identifier, std::move(initValue));
    }

    throw std::runtime_error("Invalid variable declaration");
}

ASTNodePtr Parser::parseAssignment() {
    std::string Identifier = consumeToken().value;

    if (!isAssignmentOperator(currentToken().type)) {
        ParseError("Expected assignment sign");
    }
    TypeToken typeofsign = consumeToken().type;
        auto initValue = parseExpression();

        if (!isEndOfStatement()) {
            throw ParseError("Expected newline after initialization");
        }
        consumeNewlines();

        return std::make_unique<AssignmentNode>(Identifier,typeofsign, std::move(initValue));
}

ASTNodePtr Parser::parseExpression() {
    auto left = parsePrimary();
    return parseBinaryOp(std::move(left), 0);
}

ASTNodePtr Parser::parsePrimary() {
    if (isTypeValueToken(currentToken().type)) {
        auto token = consumeToken();

        switch(token.type) {
            case TypeToken::IntValue:
                return std::make_unique<IntLiteralNode>(std::stoi(token.value));
            case TypeToken::FloatValue:
                return std::make_unique<FloatLiteralNode>(std::stod(token.value));
            case TypeToken::CharValue:
                return std::make_unique<CharLiteralNode>(token.value.empty() ? '\0' : token.value[0]);
            case TypeToken::StringValue:
                return std::make_unique<StringLiteralNode>(token.value);
            case TypeToken::True:
            case TypeToken::False:
                return std::make_unique<BoolLiteralNode>(token.type == TypeToken::True);
            default:
                throw ParseError("Unsupported literal type");
        }
    }

    if (Is(TypeToken::Identifier)) {
        auto token = consumeToken();
        return std::make_unique<IdentifierNode>(token.value);
    }

    if (Is(TypeToken::LeftParen)) {
        consumeToken(); // Consume '('
        auto expr = parseExpression();
        expect(TypeToken::RightParen, "Expected ')' after expression");
        return expr;
    }

    throw ParseError("Unexpected token in expression: " + currentToken().value);
}

ASTNodePtr Parser::parseBinaryOp(ASTNodePtr left, int minPrecedence) {
    while (true) {
        auto opToken = currentToken();
        if (!isOperatorStart(opToken.type)) break;

        int precedence = getOperatorPrecedence(opToken.type);
        if (precedence < minPrecedence) break;

        consumeToken(); // Consume operator
        auto right = parsePrimary();

        // Handle operator precedence
        while (true) {
            auto nextOp = currentToken();
            if (!isOperatorStart(nextOp.type)) break;

            int nextPrecedence = getOperatorPrecedence(nextOp.type);
            if (nextPrecedence <= precedence) break;

            right = parseBinaryOp(std::move(right), nextPrecedence);
        }

        left = std::make_unique<BinaryExprNode>(std::move(left),opToken.value,  std::move(right));
    }

    return left;
}
// Utility functions implementation
bool Parser::isTypeToken(TypeToken type) const {
    static const std::set<TypeToken> typeTokens = {
        TypeToken::Int, TypeToken::Float,
        TypeToken::Char, TypeToken::String
    };
    return typeTokens.count(type) > 0;
}
// Utility functions implementation
bool Parser::isAssignmentOperator(TypeToken type) const {
    static const std::set<TypeToken> typeTokens = {
        TypeToken::OpAssign, TypeToken::OpDivideAssign,
        TypeToken::OpMinusAssign, TypeToken::OpMultiplyAssign,TypeToken::OpPlusAssign,
    };
    return typeTokens.count(type) > 0;
}
// Utility functions implementation
bool Parser::isTypeValueToken(TypeToken type) const {
    static const std::set<TypeToken> typeTokens = {
        TypeToken::IntValue, TypeToken::FloatValue,
        TypeToken::CharValue, TypeToken::StringValue
    };
    return typeTokens.count(type) > 0;
}

int Parser::getOperatorPrecedence(TypeToken op) const {
    static const std::unordered_map<TypeToken, int> precedence = {
        {TypeToken::OpMultiply, 5},
        {TypeToken::OpDivide, 5},
        {TypeToken::OpPlus, 4},
        {TypeToken::OpMinus, 4},
    };
    return precedence.count(op) ? precedence.at(op) : 0;
}

bool Parser::isOperatorStart(TypeToken type) const {
    static const std::set<TypeToken> operators = {
        TypeToken::OpPlus, TypeToken::OpMinus,
        TypeToken::OpMultiply, TypeToken::OpDivide,
        // ... altri operatori
    };
    return operators.count(type) > 0;
}

bool Parser::isEndOfStatement() const {
    return Is(TypeToken::Newline) || Is(TypeToken::End);
}