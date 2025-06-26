//
// Created by Personal on 13/06/2025.
//
#include "ast/nodes/Literals.h"
#include "ast/ASTVisitor.h"

LiteralNode::LiteralNode(std::string value, std::string type)
    : value(std::move(value)), type(std::move(type)) {}

NodeType LiteralNode::getType() const {
    return NodeType::LITERAL;
}

void LiteralNode::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}

std::string LiteralNode::toString() const {
    return value;
}

const std::string& LiteralNode::getValue() const { return value; }
const std::string& LiteralNode::getLiteralType() const { return type; }