//
// Created by Personal on 04/07/2025.
//

#ifndef IFNODE_H
#define IFNODE_H

#include "ast/ASTNode.h"

AST_NODE(IfNode) {
    ASTNodePtr condition;
    ASTNodePtr thenBlock;
    ASTNodePtr elseBlock;  // Può essere ElseNode o un altro IfNode per elif

    public:
    IfNode(ASTNodePtr condition, ASTNodePtr thenBlock, ASTNodePtr elseBlock = nullptr)
        : condition(std::move(condition)),
          thenBlock(std::move(thenBlock)),
          elseBlock(std::move(elseBlock)) {}

    const ASTNodePtr& getCondition() const { return condition; }
    const ASTNodePtr& getThenBlock() const { return thenBlock; }
    const ASTNodePtr& getElseBlock() const { return elseBlock; }
    bool hasElse() const { return elseBlock != nullptr; }
};

#endif //IFNODE_H
