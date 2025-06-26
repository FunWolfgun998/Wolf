//
// Created by Personal on 13/06/2025.
//
#ifndef WOLF_STATEMENTS_H
#define WOLF_STATEMENTS_H

#include "ast/AST.h"
#include <vector>

class BlockNode : public ASTNode {
    std::vector<ASTNodePtr> statements;
public:
    explicit BlockNode(std::vector<ASTNodePtr> statements);

    NodeType getType() const override;
    void accept(ASTVisitor& visitor) const override;
    std::string toString() const override;

    const std::vector<ASTNodePtr>& getStatements() const;
};

#endif // WOLF_STATEMENTS_H