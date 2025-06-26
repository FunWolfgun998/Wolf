//
// Created by Personal on 13/06/2025.
//
#ifndef MY_PARSER_LITERALS_H
#define MY_PARSER_LITERALS_H

#include "ast/AST.h"

class LiteralNode : public ASTNode {
    std::string value;
    std::string type;
public:
    LiteralNode(std::string value, std::string type);

    NodeType getType() const override;
    void accept(ASTVisitor& visitor) const override;
    std::string toString() const override;

    const std::string& getValue() const;
    const std::string& getLiteralType() const;
};

#endif // MY_PARSER_LITERALS_H