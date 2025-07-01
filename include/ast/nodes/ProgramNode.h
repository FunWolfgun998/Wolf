//
// Created by Personal on 27/06/2025.
//

#ifndef PROGRAMNODE_H
#define PROGRAMNODE_H

#include "ast/ASTNode.h"
AST_NODE(ProgramNode) {
    std::vector<ASTNodePtr> statements;

    public:
    /*
     explicit is needed to be sure that implicit conversions aren't allowed.
     ProgramNode p = ProgramNode(statements) OK, ProgramNode p = var1 NO ERROR
     */
    explicit ProgramNode(std::vector<ASTNodePtr> statements)
        : statements(std::move(statements)) {}
};

#endif //PROGRAMNODE_H
