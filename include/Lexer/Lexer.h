#ifndef MY_PARSER_LEXER_H
#define MY_PARSER_LEXER_H

#define tab_value 4
#include <string>
#include <vector>
#include <cstdint>
#include <stdexcept>
#include <cstring>
#include "Token.h"
#include "StateToken.h"


class Lexer {
public:
    explicit Lexer(std::string input);
    struct LexerError : std::runtime_error {
        using std::runtime_error::runtime_error;
    };
    std::vector<Token> getAllTokens();

private:
    std::string input;
    size_t pos = 0;
    std::vector<int> indentStack;
    std::vector<Token> Tokens;
    StateToken currentState;
    bool atLineStart = true;
    void recoverFromError() {
        // Skip until next valid token start
        while (pos < input.size()) {
            char c = input[pos];
            if (isalpha(c) || isdigit(c) || strchr("_'\".+-*/=<>!&|", c) || c == '\n') {
                break;
            }
            pos++;
        }
        currentState = StateToken::Neutral;
    }

    void emitErrorToken(const std::string& value) {
        Tokens.emplace_back(TypeToken::Unknown, value);
        recoverFromError();
    }

    void CreateToken();


    static TypeToken getKeywordToken(const std::string& str);
    static TypeToken getOperatorToken(const std::string& str);

    bool isOperator() const;
    char currentChar() const;
    char consumeChar() ;

    void fail(size_t start_pos, size_t end_pos) {
        Tokens.emplace_back(TypeToken::Unknown, input.substr(start_pos, end_pos - start_pos));
        currentState = StateToken::Neutral;
    }

    void fail() {
        fail(pos, pos + 1);  // Default to current character
    }
};

#endif // MY_PARSER_LEXER_H