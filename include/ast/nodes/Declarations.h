//
// Created by Personal on 13/06/2025.
//
#ifndef MY_PARSER_DECLARATIONS_H
#define MY_PARSER_DECLARATIONS_H

#include "ast/AST.h"

class VariableDeclNode : public ASTNode {
    std::string type;
    std::string name;
public:
    VariableDeclNode(std::string type, std::string name);

    NodeType getType() const override;
    void accept(ASTVisitor& visitor) const override;
    std::string toString() const override;

    const std::string& getVarType() const;
    const std::string& getVarName() const;
};

class VariableInitNode : public ASTNode {
    std::string type;
    std::string name;
    ASTNodePtr value;
public:
    VariableInitNode(std::string type, std::string name, ASTNodePtr value);

    NodeType getType() const override;
    void accept(ASTVisitor& visitor) const override;
    std::string toString() const override;

    const std::string& getVarType() const;
    const std::string& getVarName() const;
    const ASTNode* getValue() const;
};

#endif // MY_PARSER_DECLARATIONS_H