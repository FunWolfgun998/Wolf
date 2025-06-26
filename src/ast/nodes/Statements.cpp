//
// Created by Personal on 13/06/2025.
//
// src/ast/nodes/Statements.cpp
#include "ast/nodes/Statements.h"
#include "ast/ASTVisitor.h"

BlockNode::BlockNode(std::vector<ASTNodePtr> statements)
    : statements(std::move(statements)) {}

NodeType BlockNode::getType() const {
    return NodeType::BLOCK;
}

void BlockNode::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

std::string BlockNode::toString() const {
    return "BlockNode";
}

const std::vector<ASTNodePtr>& BlockNode::getStatements() const {
    return statements;
}