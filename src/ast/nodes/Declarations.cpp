//
// Created by Personal on 13/06/2025.
//
#include "ast/nodes/Declarations.h"
#include "ast/ASTVisitor.h"

// VariableDeclNode implementation
VariableDeclNode::VariableDeclNode(std::string type, std::string name)
    : type(std::move(type)), name(std::move(name)) {}

NodeType VariableDeclNode::getType() const {
    return NodeType::VARIABLE_DECL;
}

void VariableDeclNode::accept(ASTVisitor& visitor) const {
    visitor.visit(*this);
}
std::string VariableDeclNode::toString() const {
    return type + " " + name + ";";
}

const std::string& VariableInitNode::getVarType() const { return type; }
const std::string& VariableInitNode::getVarName() const { return name; }
const ASTNode* VariableInitNode::getValue() const { return value.get(); }