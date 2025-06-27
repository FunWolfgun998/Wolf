//
// Created by Personal on 27/06/2025.
//

#ifndef INTLITERALNODE_H
#define INTLITERALNODE_H

#define "ast/ASTNode.h"
#include "ast/ASTNode.h"

AST_NODE(IntLiteralNode) {
    int value;
    public:
    explicit IntLiteralNode(int value): value(value){}

};

#endif //INTLITERALNODE_H
