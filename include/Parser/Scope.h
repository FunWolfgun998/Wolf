//
// Created by cristian on 13/08/25.
//

#ifndef WOLF_SCOPE_H
#define WOLF_SCOPE_H
#include <string>
#include <unordered_map>
#include <optional>

#include "Parser/Symbol.h"
class Scope {
    std::unordered_map<std::string, Symbol> symbols;
public:
    bool declare(const Symbol& sym) {
        if (symbols.find(sym.name) != symbols.end()) {
            return false; // Already declared in this scope
        }
        symbols[sym.name] = sym;
        return true;
    }

    std::optional<Symbol> lookup(const std::string& name) const {
        auto it = symbols.find(name);
        if (it != symbols.end()) {
            return it->second;
        }
        return std::nullopt;
    }
};
#endif //WOLF_SCOPE_H