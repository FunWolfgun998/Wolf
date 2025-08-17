//
// Created by Personal on 10/05/2025.
//
#ifndef MY_PARSER_PARSER_H
#define MY_PARSER_PARSER_H

#include <vector>
#include <memory>
#include "../Lexer/Token.h"
#include "../../include/AST/AST.h"
#include "Parser/Scope.h"
class Parser {
public:
    explicit Parser(std::vector<Token> tokens);
    ASTNodePtr parse();

private:
    // Token management
    const Token& currentToken() const;
    const Token& consumeToken();
    const Token& expectToken(TypeToken type, const std::string& context = "");
    bool matchToken(TypeToken type) const;
    bool lookAhead(size_t n, TypeToken type) const;

    // Error handling
    [[noreturn]] void error(const std::string& msg);
    std::string currentContext() const;

    // Scope management
    void enterScope();
    void exitScope();
    bool declareSymbol(const Symbol& sym);
    std::optional<Symbol> lookupSymbol(const std::string& name) const;

    // Node creation
    template <typename NodeT, typename... Args>
    ASTNodePtr makeNode(Args&&... args);

    // Expression parsing
    ASTNodePtr parseExpression(int minPrecedence = 0);
    ASTNodePtr parseUnaryExpression();
    ASTNodePtr parsePrimaryExpression();
    ASTNodePtr parsePostfixExpression(ASTNodePtr primary);

    // Statement parsing
    ASTNodePtr parseStatement();
    ASTNodePtr parseDeclaration();
    ASTNodePtr parseAssignment();
    ASTNodePtr parseIf();
    ASTNodePtr parseWhile();
    ASTNodePtr parseFor();
    ASTNodePtr parseBlock();

    // Utilities
    bool isTypeToken(TypeToken type) const;
    bool isLiteralToken(TypeToken type) const;
    int getPrecedence(TypeToken op) const;
    bool isRightAssociative(TypeToken op) const;

    // State
    std::vector<Token>::const_iterator current;
    std::vector<Token>::const_iterator end;
    std::vector<Scope> scopes;
    bool debugMode = false;
};

// Implementation would follow the same structure with clear separation
// of concerns and consistent error handling
#endif // MY_PARSER_PARSER_H