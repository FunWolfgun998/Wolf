//
// Created by Personal on 13/06/2025.
//
#include "ast/ASTPrinter.h"
#include "ast/nodes/Declarations.h"
#include "ast/nodes/Expressions.h"
#include "ast/nodes/Literals.h"
#include "ast/nodes/Statements.h"

ASTPrinter::ASTPrinter(std::ostream& output) : out(output) {}

void ASTPrinter::printIndent() const {
    for (int i = 0; i < indentLevel; ++i) {
        out << "  ";
    }
}

void ASTPrinter::printWithIndent(const std::string& text) {
    printIndent();
    out << text << "\n";
}

void ASTPrinter::visit(const ProgramNode& node){
    printWithIndent("Program:");
    indentLevel++;
    for (const auto& stmt : node.getStatements()) {
        stmt->accept(*this);
    }
    indentLevel--;
}

void ASTPrinter::visit(const VariableDeclNode& node) {
    printWithIndent("VarDecl: " + node.getVarType() + " " + node.getVarName());
}

void ASTPrinter::visit(const VariableInitNode& node) {
    printWithIndent("VarInit: " + node.getVarType() + " " + node.getVarName() + " =");
    indentLevel++;
    node.getValue()->accept(*this);
    indentLevel--;
}

void ASTPrinter::visit(const BinaryExprNode& node) {
    printWithIndent("BinaryExpr: " + node.getOperator());
    indentLevel++;
    printWithIndent("Left:");
    indentLevel++;
    node.getLeft()->accept(*this);
    indentLevel--;

    printWithIndent("Right:");
    indentLevel++;
    node.getRight()->accept(*this);
    indentLevel--;
    indentLevel--;
}

void ASTPrinter::visit( const IdentifierNode& node) {
    printWithIndent("Identifier: " + node.getName());
}

void ASTPrinter::visit(const LiteralNode& node) {
    printWithIndent("Literal: " + node.getValue() + " (" + node.getLiteralType() + ")");
}
void ASTPrinter::visit(const BlockNode& node) {
    printWithIndent("Block:");
    indentLevel++;
    for (const auto& stmt : node.getStatements()) {
        stmt->accept(*this);
    }
    indentLevel--;
}