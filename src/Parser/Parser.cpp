#include "parser/Parser.h"

#include <iostream>
#include <set>

#include "ast/nodes/Declarations.h"
#include "ast/nodes/Expressions.h"
#include "ast/nodes/Literals.h"
#include "ast/nodes/Statements.h"
#include "parser/ParseError.h"
#include <stdexcept>

Parser::Parser(std::vector<Token> tokens)
    : tokens(std::move(tokens)), pos(0) {}

ASTNodePtr Parser::parse() {
    return parseProgram();
}

// Helper functions implementation
const Token& Parser::currentToken() const {
    if (pos >= tokens.size()) {
        static Token endToken{TypeToken::End, ""};
        return endToken;
    }
    return tokens[pos];
}

const Token& Parser::consumeToken() {
    return tokens[pos++];
}
//capire perché se consumo mi ritorna come varname int non cv

bool Parser::IsSame(TypeToken type) const {
    return tokens[pos].type == type;
}

void Parser::expect(TypeToken type, const std::string& errorMsg) {
    if (!IsSame(type)) {
        throw std::runtime_error(errorMsg + ". Found: " + std::to_string(static_cast<int>(currentToken().type)));
    }
    consumeToken();
}
void Parser::peek(TypeToken type, const std::string& errorMsg) {
    if (!IsSame(type)) {
        throw std::runtime_error(errorMsg + ". Found: " + std::to_string(static_cast<int>(currentToken().type)));
    }
}

// Main parsing methods
// Modifica a parseProgram()
ASTNodePtr Parser::parseProgram() {
    std::vector<ASTNodePtr> statements;

    while (!IsSame(TypeToken::End)) {

        if (IsSame(TypeToken::Newline)) {
            pos++;
            continue;
        }

        // Create a block base on indentation
        if (IsSame(TypeToken::Indent)) {
            pos++;
            auto block = parseBlock();
            statements.push_back(std::move(block));
            continue;
        }

        statements.push_back(parseStatement());
    }

    return std::make_unique<ProgramNode>(std::move(statements));
}
ASTNodePtr Parser::parseBlock() {
    std::vector<ASTNodePtr> statements;

    while (!IsSame(TypeToken::Dedent) && !IsSame(TypeToken::End)) {
        statements.push_back(parseStatement());
    }

    if (IsSame(TypeToken::Dedent)) {
        consumeToken();
    }

    return std::make_unique<BlockNode>(std::move(statements));
}
ASTNodePtr Parser::parseStatement() {
    consumeNewlines();
    if (isTypeToken(currentToken().type)) {
        return parseDeclaration();
    }
    if (currentToken().type == TypeToken::VarName) {
        peek(TypeToken::OpAssign, "Expected '=' to assign a value to a variable");
        return parseAssaingValue();
    }
    // Aggiungi qui altri tipi di statement...

    throw ParseError("Unexpected token at statement start");
}

ASTNodePtr Parser::parseDeclaration() {
    TypeToken typeToken = consumeToken().type;
    std::string typeStr;

    switch (typeToken) {
        case TypeToken::Int: typeStr = "int"; break;
        case TypeToken::Float: typeStr = "float"; break;
        case TypeToken::Char: typeStr = "char"; break;
        case TypeToken::String: typeStr = "string"; break;
        default: throw std::runtime_error("Expected type specifier");
    }

    peek(TypeToken::VarName, "Expected variable name");
    std::string varName = consumeToken().value;

    // Simple declaration (int x)
    if (isEndOfStatement()) {
        consumeNewlines();
        return std::make_unique<VariableDeclNode>(typeStr, varName);
    }

    // Initialization (int x = 42)
    if (IsSame(TypeToken::OpAssign)) {
        consumeToken(); // Consuma '='
        auto initValue = parseExpression();

        if (!isAtStatementEnd()) {
            throw ParseError("Expected newline after initialization");
        }
        consumeNewlines();

        return std::make_unique<VariableInitNode>(typeStr, varName, std::move(initValue));
    }

    throw std::runtime_error("Invalid variable declaration");
}

ASTNodePtr Parser::parseAssaingValue() {
    std::string VariableName = consumeToken().value;
    peek(TypeToken::OpAssign, "Expected '=' to assign a value to a variable");
    consumeToken();
    auto initValue = parseExpression();

        if (!isAtStatementEnd()) {
            throw ParseError("Expected newline after initialization");
        }
        consumeNewlines();

        return std::make_unique<VariableInitNode>(typeStr, varName, std::move(initValue));
}


ASTNodePtr Parser::parseExpression() {
    auto left = parsePrimary();
    return parseBinaryOp(std::move(left), 0);
}

ASTNodePtr Parser::parsePrimary() {
    if (isTypeValueToken(currentToken().type)) {
        auto token = consumeToken();
        return std::make_unique<LiteralNode>(token.value,
            token.type == TypeToken::IntValue ? "int" :token.type == TypeToken::FloatValue ? "float": token.type == TypeToken::CharValue ? "char" : token.type == TypeToken::StringValue ? "string" :"Error: you can");
    }

    if (IsSame(TypeToken::VarName)) {
        auto token = consumeToken();
        return std::make_unique<IdentifierNode>(token.value);
    }

    if (IsSame(TypeToken::LeftParen)) {
        consumeToken(); // Consume '('
        auto expr = parseExpression();
        expect(TypeToken::RightParen, "Expected ')' after expression");
        return expr;
    }

    throw std::runtime_error("Unexpected token in expression"+currentToken().value);
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

        left = std::make_unique<BinaryExprNode>(opToken.value, std::move(left), std::move(right));
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
bool Parser::isTypeValueToken(TypeToken type) const {
    static const std::set<TypeToken> typeTokens = {
        TypeToken::IntValue, TypeToken::FloatValue,
        TypeToken::CharValue, TypeToken::StringValue
    };
    return typeTokens.count(type) > 0;
}

bool Parser::isEndOfStatement() const {
    return IsSame(TypeToken::Newline) || IsSame(TypeToken::End);
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
// skip all the newlines and comments
void Parser::consumeNewlines() {
    while (IsSame(TypeToken::Newline)|| IsSame(TypeToken::Comment)) {
        consumeToken();
    }
}

// Verifica se siamo alla fine di un'istruzione
bool Parser::isAtStatementEnd() const {
    return IsSame(TypeToken::Newline) || IsSame(TypeToken::End);
}