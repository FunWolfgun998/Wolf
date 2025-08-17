//
// Created by cristian on 13/08/25.
//

#ifndef WOLF_SYMBOL_H
#define WOLF_SYMBOL_H
#include <string>
#include "Lexer/Token.h"
struct Symbol {
    std::string name;
    TypeToken type;  // The variable type (Int, Float, etc.)
    size_t declarationLine;
    bool isInitialized;
};
#endif //WOLF_SYMBOL_H