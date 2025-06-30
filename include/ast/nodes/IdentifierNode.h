//
// Created by Personal on 28/06/2025.
//

#ifndef IDENTIFIERNODE_H
#define IDENTIFIERNODE_H

#include "ast/ASTNode.h"
#include <string>

AST_NODE(IdentifierNode) {
    std::string name;

    public:
    IdentifierNode(std::string name) : name(std::move(name)) {}
/*
    const std::string& getName() const { return name; }
*/
};

#endif //IDENTIFIERNODE_H
