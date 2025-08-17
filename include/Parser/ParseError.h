//
// Created by Personal on 13/06/2025.
//
#ifndef MY_PARSER_PARSEERROR_H
#define MY_PARSER_PARSEERROR_H

#include <stdexcept>
#include <string>
#include "../Lexer/Token.h"

class ParseError : public std::runtime_error {
    size_t line;
    size_t column;
    TypeToken tokenType;

public:
    // Costruttore base
    explicit ParseError(const std::string& msg)
        : std::runtime_error(msg), line(0), column(0), tokenType(TypeToken::Unknown) {}

    // Costruttore con dettagli aggiuntivi
    ParseError(const std::string& msg, const Token& token)
        : std::runtime_error(msg + " at line " + std::to_string(token.line) +
                           ", column " + std::to_string(token.column)),
          line(token.line),
          column(token.column),
          tokenType(token.type) {}

    // Metodi accessori
    size_t getLine() const { return line; }
    size_t getColumn() const { return column; }
    TypeToken getTokenType() const { return tokenType; }
};

#endif // MY_PARSER_PARSEERROR_H