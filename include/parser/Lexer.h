#ifndef MY_PARSER_LEXER_H
#define MY_PARSER_LEXER_H

#define tab_value 4
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include "parser/Token.h"
#include "parser/StateToken.h"


class Lexer {
public:
    explicit Lexer(std::string input);

    std::vector<Token> getAllTokens();
    Token getToken();

private:
    std::string input;
    size_t pos = 0;
    std::queue<Token> pendingTokens;
    std::vector<int> indentStack;
    std::vector<Token> Tokens;
    StateToken currentState;

    bool atLineStart = true;
    static const std::unordered_map<std::string, TypeToken> keywords;

    void skipWhitespace();
    void setIndentation();
    void consumeWhitespace();
    void CreateToken();
    void Opdivide();
    int countIndentation();

    Token getNumber();
    Token getChar();
    Token getString();
    Token getComment();
    Token getIdentifierOrKeyword();
    Token getOperator();
    Token getCompoundOperator(char first);
    Token createIndentToken(int level) const;
    Token createDedentToken(int level) const;

    bool isOperatorStart(char c) const;
    bool isEOF() const;
    char advance();
    char currentChar() const;
    char peek() const;
    char consumeChar() ;
};

#endif // MY_PARSER_LEXER_H