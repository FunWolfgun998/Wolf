#ifndef ASTNODE_H
#define ASTNODE_H

#include <memory>
#include <variant>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

class ASTVisitor;

class ASTNodeBase {
public:
    virtual ~ASTNodeBase() = default;
    virtual void accept(ASTVisitor& visitor) const = 0;
};

template <typename Derived>
class ASTNode : public ASTNodeBase {
public:

};

using ASTNodePtr = std::unique_ptr<ASTNodeBase>;

// First forward declare all node types
#define FORWARD_DECLARE(type) class type;
FORWARD_DECLARE(ProgramNode)
FORWARD_DECLARE(IntLiteralNode)
FORWARD_DECLARE(FloatLiteralNode)
FORWARD_DECLARE(StringLiteralNode)
FORWARD_DECLARE(BoolLiteralNode)
FORWARD_DECLARE(NullLiteralNode)
FORWARD_DECLARE(IdentifierNode)
FORWARD_DECLARE(BinaryExprNode)
FORWARD_DECLARE(UnaryExprNode)
FORWARD_DECLARE(AssignmentNode)
FORWARD_DECLARE(VariableDeclNode)
FORWARD_DECLARE(CompoundAssignmentNode)
FORWARD_DECLARE(VariableInitNode)
FORWARD_DECLARE(FunctionDeclNode)
FORWARD_DECLARE(FunctionParamNode)
FORWARD_DECLARE(ClassDeclNode)
FORWARD_DECLARE(ClassPropertyNode)
FORWARD_DECLARE(ClassMethodNode)
FORWARD_DECLARE(CallExprNode)
FORWARD_DECLARE(MethodCallNode)
FORWARD_DECLARE(ArrayAccessNode)
FORWARD_DECLARE(MemberAccessNode)
FORWARD_DECLARE(NewExprNode)
FORWARD_DECLARE(BlockNode)
FORWARD_DECLARE(IfNode)
FORWARD_DECLARE(ElseNode)
FORWARD_DECLARE(ForNode)
FORWARD_DECLARE(WhileNode)
FORWARD_DECLARE(DoWhileNode)
FORWARD_DECLARE(SwitchNode)
FORWARD_DECLARE(CaseNode)
FORWARD_DECLARE(ReturnNode)
FORWARD_DECLARE(BreakNode)
FORWARD_DECLARE(ContinueNode)
FORWARD_DECLARE(ThrowNode)
FORWARD_DECLARE(TryCatchNode)
FORWARD_DECLARE(ImportNode)
FORWARD_DECLARE(ExportNode)
FORWARD_DECLARE(TypeAnnotationNode)
FORWARD_DECLARE(TemplateDeclNode)
FORWARD_DECLARE(GenericTypeNode)
FORWARD_DECLARE(YieldNode)
FORWARD_DECLARE(AwaitNode)
FORWARD_DECLARE(CommentNode)
FORWARD_DECLARE(DirectiveNode)
#undef FORWARD_DECLARE

// Define unique_ptr aliases
#define DEFINE_PTR(type) using type##Ptr = std::unique_ptr<type>;
DEFINE_PTR(ProgramNode)
DEFINE_PTR(IntLiteralNode)
DEFINE_PTR(FloatLiteralNode)
DEFINE_PTR(StringLiteralNode)
DEFINE_PTR(BoolLiteralNode)
DEFINE_PTR(NullLiteralNode)
DEFINE_PTR(IdentifierNode)
DEFINE_PTR(BinaryExprNode)
DEFINE_PTR(UnaryExprNode)
DEFINE_PTR(AssignmentNode)
DEFINE_PTR(VariableDeclNode)
DEFINE_PTR(CompoundAssignmentNode)
DEFINE_PTR(VariableInitNode)
DEFINE_PTR(FunctionDeclNode)
DEFINE_PTR(FunctionParamNode)
DEFINE_PTR(ClassDeclNode)
DEFINE_PTR(ClassPropertyNode)
DEFINE_PTR(ClassMethodNode)
DEFINE_PTR(CallExprNode)
DEFINE_PTR(MethodCallNode)
DEFINE_PTR(ArrayAccessNode)
DEFINE_PTR(MemberAccessNode)
DEFINE_PTR(NewExprNode)
DEFINE_PTR(BlockNode)
DEFINE_PTR(IfNode)
DEFINE_PTR(ElseNode)
DEFINE_PTR(ForNode)
DEFINE_PTR(WhileNode)
DEFINE_PTR(DoWhileNode)
DEFINE_PTR(SwitchNode)
DEFINE_PTR(CaseNode)
DEFINE_PTR(ReturnNode)
DEFINE_PTR(BreakNode)
DEFINE_PTR(ContinueNode)
DEFINE_PTR(ThrowNode)
DEFINE_PTR(TryCatchNode)
DEFINE_PTR(ImportNode)
DEFINE_PTR(ExportNode)
DEFINE_PTR(TypeAnnotationNode)
DEFINE_PTR(TemplateDeclNode)
DEFINE_PTR(GenericTypeNode)
DEFINE_PTR(YieldNode)
DEFINE_PTR(AwaitNode)
DEFINE_PTR(CommentNode)
DEFINE_PTR(DirectiveNode)
#undef DEFINE_PTR

// Variant type for AST nodes
using ASTNodeVariant = std::variant<
    ProgramNode*,
    IntLiteralNode*,
    FloatLiteralNode*,
    StringLiteralNode*,
    BoolLiteralNode*,
    NullLiteralNode*,
    IdentifierNode*,
    BinaryExprNode*,
    UnaryExprNode*,
    AssignmentNode*,
    VariableDeclNode*,
    CompoundAssignmentNode*,
    VariableInitNode*,
    FunctionDeclNode*,
    FunctionParamNode*,
    ClassDeclNode*,
    ClassPropertyNode*,
    ClassMethodNode*,
    CallExprNode*,
    MethodCallNode*,
    ArrayAccessNode*,
    MemberAccessNode*,
    NewExprNode*,
    BlockNode*,
    IfNode*,
    ElseNode*,
    ForNode*,
    WhileNode*,
    DoWhileNode*,
    SwitchNode*,
    CaseNode*,
    ReturnNode*,
    BreakNode*,
    ContinueNode*,
    ThrowNode*,
    TryCatchNode*,
    ImportNode*,
    ExportNode*,
    TypeAnnotationNode*,
    TemplateDeclNode*,
    GenericTypeNode*,
    YieldNode*,
    AwaitNode*,
    CommentNode*,
    DirectiveNode*
>;

namespace AST {
    template <typename T, typename... Args>
    ASTNodePtr make_node(Args&&... args) {
        static_assert(std::is_base_of_v<ASTNode<T>, T>,
            "Type must inherit from ASTNode");
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template <typename T, typename... Args>
    ASTNodeVariant make_variant_node(Args&&... args) {
        static_assert(std::is_base_of_v<ASTNode<T>, T>,
            "Type must inherit from ASTNode");
        return new T(std::forward<Args>(args)...);
    }
}

// Macro for defining AST node classes (to be used in their own headers)
#define AST_NODE(type) \
class type : public ASTNode<type>

#endif // ASTNODE_H