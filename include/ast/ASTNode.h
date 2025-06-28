#ifndef ASTNODE_H
#define ASTNODE_H

#include <memory>
#include <variant>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include "ASTVisitor.h"
#define AST_NODE(type) \
class type : public ASTNode<type>


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
using ASTNodePtr = std::unique_ptr<ASTNode<void>>;
//need to create the variant AST node
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
}
//foward declarations
class ProgramNode;
class IntLiteralNode;
class FloatLiteralNode;
class StringLiteralNode;
class BoolLiteralNode;
class NullLiteralNode;
class IdentifierNode;
class BinaryExprNode;
class UnaryExprNode;
class AssignmentNode;
class CompoundAssignmentNode; // +=, -= etc.
class VariableDeclNode;
class VariableInitNode;
class FunctionDeclNode;
class FunctionParamNode;
class ClassDeclNode;
class ClassPropertyNode;
class ClassMethodNode;
class CallExprNode;
class MethodCallNode;
class ArrayAccessNode;
class MemberAccessNode;
class NewExprNode;
class BlockNode;
class IfNode;
class ElseNode;
class ForNode;
class WhileNode;
class DoWhileNode;
class SwitchNode;
class CaseNode;
class ReturnNode;
class BreakNode;
class ContinueNode;
class ThrowNode;
class TryCatchNode;
class ImportNode;
class ExportNode;
class TypeAnnotationNode;
class TemplateDeclNode;
class GenericTypeNode;
class YieldNode;
class AwaitNode;
class CommentNode;
class DirectiveNode;
/*
class TernaryExprNode; //condition ? expr_if_true : expr_if_false
class ArrayLiteralNode;
 */
#endif // ASTNODE_H