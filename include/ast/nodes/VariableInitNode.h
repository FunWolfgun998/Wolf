//
// Created by Personal on 28/06/2025.
//

#ifndef VARIABLEINITNODE_H
#define VARIABLEINITNODE_H
#include "ast/ASTNode.h"

AST_NODE(VariableInitNode) {//int = 567
    std::string name;           // Nome della variabile (es. "x")
    std::string type;     // Type es. int, float, char,
    ASTNodePtr value;   // Value
    public:
    VariableInitNode(std::string name,std::string type, ASTNodePtr value)
    : type(std::move(type)),name(std::move(name)),value(std::move(value)){}

    /*
    const std::string& getName() const { return name; }
    const TypeAnnotation& getType() const { return *type; }
    bool isConstant() const { return isConst; }
    */
};
#endif //VARIABLEINITNODE_H
