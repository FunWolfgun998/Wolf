//
// Created by Personal on 13/06/2025.
//
#include "ast/nodes/Expressions.h"
#include "ast/ASTVisitor.h"

// BinaryExprNode implementation
BinaryExprNode::BinaryExprNode(std::string op, ASTNodePtr left, ASTNodePtr right)
    : op(std::move(op)), left(std::move(left)), right(std::move(right)) {}

NodeType BinaryExprNode::getType() const {
    return NodeType::BINARY_EXPR;
}

void BinaryExprNode::accept(ASTVisitor& visitor) const{
    visitor.visit(*this);
}

std::string BinaryExprNode::toString() const {
    return "(" + left->toString() + " " + op + " " + right->toString() + ")";
}

const std::string& BinaryExprNode::getOperator() const { return op; }
const ASTNode* BinaryExprNode::getLeft() const { return left.get(); }
const ASTNode* BinaryExprNode::getRight() const { return right.get(); }

// IdentifierNode implementation
IdentifierNode::IdentifierNode(std::string name)
    : name(std::move(name)) {}

NodeType IdentifierNode::getType() const {
    return NodeType::IDENTIFIER;
}

void IdentifierNode::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}





#include "ast/ASTNode.h"
#include "ast/ASTVisitor.h"

// BinaryExprNode implementation
void BinaryExprNode::acceptImpl(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

std::string BinaryExprNode::toString() const {
    return "(" + left->toString() + " " + op + " " + right->toString() + ")";
}

// IdentifierNode implementation
void IdentifierNode::acceptImpl(ASTVisitor& visitor) const {
    visitor.visit(*this);
}


std::string IdentifierNode::toString() const {
    return name;
}

const std::string& IdentifierNode::getName() const { return name; }