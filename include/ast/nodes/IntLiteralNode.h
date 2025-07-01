//
// Created by Personal on 27/06/2025.
//

#ifndef INTLITERALNODE_H
#define INTLITERALNODE_H

#include "ast/ASTNode.h"

AST_NODE(IntLiteralNode){
    public:
    explicit IntLiteralNode(int value): value(value){}
    private:
    int value;
};

#endif //INTLITERALNODE_H
