//
// Created by Personal on 13/06/2025.
//
#ifndef AST_VISITOR_H
#define AST_VISITOR_H

// Include all necessary forward declarations
#include "ASTNode.h"
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
class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;

    // Visitor methods for all AST node types
    virtual void visit(const ProgramNode&) = 0;
    virtual void visit(const IntLiteralNode&) = 0;
    virtual void visit(const FloatLiteralNode&) = 0;
    virtual void visit(const StringLiteralNode&) = 0;
    virtual void visit(const BoolLiteralNode&) = 0;
    virtual void visit(const NullLiteralNode&) = 0;
    virtual void visit(const IdentifierNode&) = 0;
    virtual void visit(const BinaryExprNode&) = 0;
    virtual void visit(const UnaryExprNode&) = 0;
    virtual void visit(const AssignmentNode&) = 0;
    virtual void visit(const VariableDeclNode&) = 0;
    virtual void visit(const CompoundAssignmentNode&) = 0;
    virtual void visit(const VariableInitNode&) = 0;
    virtual void visit(const FunctionDeclNode&) = 0;
    virtual void visit(const FunctionParamNode&) = 0;
    virtual void visit(const ClassDeclNode&) = 0;
    virtual void visit(const ClassPropertyNode&) = 0;
    virtual void visit(const ClassMethodNode&) = 0;
    virtual void visit(const CallExprNode&) = 0;
    virtual void visit(const MethodCallNode&) = 0;
    virtual void visit(const ArrayAccessNode&) = 0;
    virtual void visit(const MemberAccessNode&) = 0;
    virtual void visit(const NewExprNode&) = 0;
    virtual void visit(const BlockNode&) = 0;
    virtual void visit(const IfNode&) = 0;
    virtual void visit(const ElseNode&) = 0;
    virtual void visit(const ForNode&) = 0;
    virtual void visit(const WhileNode&) = 0;
    virtual void visit(const DoWhileNode&) = 0;
    virtual void visit(const SwitchNode&) = 0;
    virtual void visit(const CaseNode&) = 0;
    virtual void visit(const ReturnNode&) = 0;
    virtual void visit(const BreakNode&) = 0;
    virtual void visit(const ContinueNode&) = 0;
    virtual void visit(const ThrowNode&) = 0;
    virtual void visit(const TryCatchNode&) = 0;
    virtual void visit(const ImportNode&) = 0;
    virtual void visit(const ExportNode&) = 0;
    virtual void visit(const TypeAnnotationNode&) = 0;
    virtual void visit(const TemplateDeclNode&) = 0;
    virtual void visit(const GenericTypeNode&) = 0;
    virtual void visit(const YieldNode&) = 0;
    virtual void visit(const AwaitNode&) = 0;
    virtual void visit(const CommentNode&) = 0;
    virtual void visit(const DirectiveNode&) = 0;
};

#endif // AST_VISITOR_H