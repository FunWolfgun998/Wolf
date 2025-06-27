//
// Created by Personal on 27/06/2025.
//

#ifndef INTLITERALNODE_H
#define INTLITERALNODE_H

#define "ast/ASTNode.h"
#include "ast/ASTNode.h"

AST_NODE(FloatLiteralNode) {
    float value;
    public:
    explicit FloatLiteralNode(float value): value(value){}
    
};

#endif //INTLITERALNODE_H
