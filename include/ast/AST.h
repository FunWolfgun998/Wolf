#ifndef AST_H
#define AST_H

#include "ASTNode.h"

// ======================================================
// Additional utilities and forward declarations
// ======================================================
enum class NodeType {
    PROGRAM,
    VARIABLE_DECL,
    // ... (tutti i tipi di nodo)
};

// Helper per nodi che necessitano di NodeType
template <typename Derived, NodeType Type>
class TypedASTNode : public ASTNode<Derived> {
public:
    NodeType getType() const { return Type; }
};

#endif // AST_H