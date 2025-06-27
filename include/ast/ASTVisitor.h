//
// Created by Personal on 13/06/2025.
//
// ASTVisitor.h
#ifndef AST_VISITOR_H
#define AST_VISITOR_H
#include "ASTNode.h"
class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;
    virtual void visit(const BinaryExprNode&) = 0;
};
#endif // AST_VISITOR_H