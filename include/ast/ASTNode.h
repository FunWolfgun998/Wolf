#ifndef ASTNODE_H
#define ASTNODE_H

#include <memory>
#include <variant>
#include <string>
#include <type_traits>

// Forward declaration
class ASTVisitor;

// ======================================================
// CRTP Base Class
// ======================================================
template <typename Derived>
class ASTNode {
public:
    virtual ~ASTNode() = default;

    void accept(ASTVisitor& visitor) const {
        visitor.visit(static_cast<const Derived&>(*this));
    }
};

// Smart pointer type
using ASTNodePtr = std::unique_ptr<ASTNode<void>>;

// ======================================================
// Node Type Variant
// ======================================================
// Forward declarations di tutti i tipi di nodo
class IntLiteralNode;
class FloatLiteralNode;
// ... (tutti gli altri nodi concreti)

using ASTNodeVariant = std::variant<
    IntLiteralNode,
    FloatLiteralNode
    // ... (tutti gli altri nodi concreti)
>;

// ======================================================
// Node Factory Utilities
// ======================================================
namespace AST {
    template <typename T, typename... Args>
    ASTNodePtr make_node(Args&&... args) {
        static_assert(std::is_base_of_v<ASTNode<T>, T>,
            "Type must inherit from ASTNode");
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template <typename T>
    const T* get_if(const ASTNodeVariant& v) {
        return std::get_if<T>(&v);
    }
}

// ======================================================
// Macro per Dichiarazione Nodi
// ======================================================
#define DECLARE_AST_NODE(type) \
    class type : public ASTNodeBase<type>

#endif // ASTNODE_H