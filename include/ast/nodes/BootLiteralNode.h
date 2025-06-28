//
// Created by Personal on 28/06/2025.
//

#ifndef BOOTLITERALNODE_H
#define BOOTLITERALNODE_H


#include "ast/ASTNode.h"

AST_NODE(BoolLiteralNode) {
    bool value;
    public:
    explicit IntLiteralNode(bool value): value(value){}

};
#endif //BOOTLITERALNODE_H
