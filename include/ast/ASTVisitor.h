//
// Created by Personal on 13/06/2025.
//
// ASTVisitor.h
#ifndef AST_VISITOR_H
#define AST_VISITOR_H

// Forward declarations of all node types
class ProgramNode;
class VariableDeclNode;
class VariableInitNode;
class BinaryExprNode;
class IdentifierNode;
class LiteralNode;
class BlockNode;

class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;

    // Visit methods for all node types
    virtual void visit(const ProgramNode& node) = 0;
    virtual void visit(const VariableDeclNode& node) = 0;
    virtual void visit(const VariableInitNode& node) = 0;
    virtual void visit(const BinaryExprNode& node) = 0;
    virtual void visit(const IdentifierNode& node) = 0;
    virtual void visit(const LiteralNode& node) = 0;
    virtual void visit(const BlockNode& node) = 0;
};

#endif // AST_VISITOR_H