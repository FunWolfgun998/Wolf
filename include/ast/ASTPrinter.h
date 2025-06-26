//
// Created by Personal on 13/06/2025.
//
#ifndef AST_PRINTER_H
#define AST_PRINTER_H

#include "ASTVisitor.h"
#include <ostream>

class ASTPrinter : public ASTVisitor {
    std::ostream& out;
    int indentLevel = 0;

    void printIndent() const;
    void printWithIndent(const std::string& text);


public:
    explicit ASTPrinter(std::ostream& output);

    // Visitor interface implementation
    void visit(const ProgramNode& node) override;
    void visit(const VariableDeclNode& node) override;
    void visit(const VariableInitNode& node) override;
    void visit(const BinaryExprNode& node) override;
    void visit(const IdentifierNode& node) override;
    void visit(const LiteralNode& node) override;
    void visit(const BlockNode& node) override;
};

#endif // AST_PRINTER_H
