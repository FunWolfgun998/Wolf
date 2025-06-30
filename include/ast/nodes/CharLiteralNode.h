//
// Created by Personal on 28/06/2025.
//

#ifndef CHARLITERALNODE_H
#define CHARLITERALNODE_H
#include "ast/ASTNode.h"

AST_NODE(CharLiteralNode) {
    char value;
    public:
    CharLiteralNode(char value): value(value){}

};
#endif //CHARLITERALNODE_H