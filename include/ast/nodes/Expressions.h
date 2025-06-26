//
// Created by Personal on 13/06/2025.
//
#ifndef MY_PARSER_EXPRESSIONS_H
#define MY_PARSER_EXPRESSIONS_H

#include "ast/AST.h"

class BinaryExprNode : public ASTNode {
    std::string op;
    ASTNodePtr left;
    ASTNodePtr right;
public:
    BinaryExprNode(std::string op, ASTNodePtr left, ASTNodePtr right);

    NodeType getType() const override;
    void accept(ASTVisitor& visitor) const override;
    std::string toString() const override;

    const std::string& getOperator() const;
    const ASTNode* getLeft() const;
    const ASTNode* getRight() const;
};

class IdentifierNode : public ASTNode {
    std::string name;
public:
    explicit IdentifierNode(std::string name);

    NodeType getType() const override;
    void accept(ASTVisitor& visitor) const override;
    std::string toString() const override;

    const std::string& getName() const;
};

#endif // MY_PARSER_EXPRESSIONS_H