//
// Created by Personal on 28/06/2025.
//

#ifndef STRINGLITERALNODE_H
#define STRINGLITERALNODE_H

#include "ast/ASTNode.h"

AST_NODE(StringLiteralNode) {
    std::string value;
    public:
    explicit StringLiteralNode(std::string value): value(std::move(value)){}

};

#endif //STRINGLITERALNODE_H
