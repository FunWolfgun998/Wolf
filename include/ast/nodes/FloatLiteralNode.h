//
// Created by Personal on 27/06/2025.
//

#ifndef FLOATLITERALNODE_H
#define FLOATLITERALNODE_H
#include "ast/ASTNode.h"

AST_NODE(FloatLiteralNode) {
    float value;
    public:
    FloatLiteralNode(float value): value(value){}
    
};

#endif //FLOATLITERALNODE_H
