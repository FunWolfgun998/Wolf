//
// Created by Personal on 28/06/2025.
//

#ifndef VARIABLEDECLNODE_H
#define VARIABLEDECLNODE_H
#include "ast/ASTNode.h"

AST_NODE(VariableDeclNode) {
    std::string name;           // Nome della variabile (es. "x")
    ASTNodePtr type;     // Type es. int, float, char,

    public:
    VariableDeclNode(std::string name,ASTNodePtr type)
    : name(std::move(name)),type(std::move(type)){}

    /*
    const std::string& getName() const { return name; }
    const TypeAnnotation& getType() const { return *type; }
    bool isConstant() const { return isConst; }
    */
};
#endif //VARIABLEDECLNODE_H
