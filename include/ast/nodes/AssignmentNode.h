//
// Created by Personal on 28/06/2025.
//

#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H

#include "ast/ASTNode.h"
AST_NODE(AssignmentNode) {
    ASTNodePtr target;    // L-value (normally IdentifierNode or MemberAccessNode)
    ASTNodePtr value;     // R-value (expression to assign)
    std::string op;       // Operator ("=", "+=", "-=", etc.)

    public:
    AssignmentNode(ASTNodePtr target, std::string op, ASTNodePtr value)
        : target(std::move(target)), op(std::move(op)), value(std::move(value)) {}

    /*
    const ASTNode& getTarget() const { return *target; }
    const std::string& getOperator() const { return op; }
    const ASTNode& getValue() const { return *value; }
    */
};

#endif //ASSIGNMENTNODE_H
