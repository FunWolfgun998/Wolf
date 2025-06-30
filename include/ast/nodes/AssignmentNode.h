//
// Created by Personal on 28/06/2025.
//

#ifndef ASSIGNMENTNODE_H
#define ASSIGNMENTNODE_H

#include "ast/ASTNode.h"
AST_NODE(AssignmentNode) {
    std::string target;    // L-value (normally IdentifierNode or MemberAccessNode)
    ASTNodePtr value;     // R-value (expression to assign)
    TypeToken op;       // Operator ("=", "+=", "-=", etc.)

    public:
    AssignmentNode(std::string target, TypeToken op, ASTNodePtr value)
        : target(std::move(target)), op(op), value(std::move(value)) {}

    /*
    const ASTNode& getTarget() const { return *target; }
    const std::string& getOperator() const { return op; }
    const ASTNode& getValue() const { return *value; }
    */
};

#endif //ASSIGNMENTNODE_H
