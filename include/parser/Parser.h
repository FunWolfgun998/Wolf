//
// Created by Personal on 10/05/2025.
//
#ifndef MY_PARSER_PARSER_H
#define MY_PARSER_PARSER_H

#include <vector>
#include <memory>
#include <unordered_map>
#include "parser/Token.h"
#include "ast/AST.h"

class Parser {
public:
    explicit Parser(std::vector<Token> tokens);

    ASTNodePtr ParseTokens();

private:
    std::vector<Token> tokens;
    size_t pos = 0;

    // Helper functions
    const Token& currentToken() const;
    const Token& consumeToken();
    bool Is(TypeToken type) const;
    bool IsNext(TypeToken type) const;
    void expect(TypeToken type, const std::string& errorMsg);
    void peek(TypeToken type, const std::string& errorMsg);

    // Parsing methods
    ASTNodePtr parseProgram();
    ASTNodePtr parseBlock();
    ASTNodePtr parseStatement();
    ASTNodePtr parseDeclaration();
    ASTNodePtr parseAssignment();
    ASTNodePtr parseExpression();
    ASTNodePtr parsePrimary();
    ASTNodePtr parseBinaryOp(ASTNodePtr left, int minPrecedence);

    // Utility functions
    bool isTypeToken(TypeToken type) const;
    bool isassaseingm(TypeToken type) const;
    bool isTypeValueToken(TypeToken type) const;
    bool isEndOfStatement() const;
    int getOperatorPrecedence(TypeToken op) const;
    bool isOperatorStart(TypeToken type) const;
    void consumeNewlines();
    bool isAtStatementEnd() const;
};

#endif // MY_PARSER_PARSER_H