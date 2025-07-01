//
// Created by Personal on 13/06/2025.
//
#ifndef AST_VISITOR_H
#define AST_VISITOR_H

// Include all necessary forward declarations
#include "ASTNode.h"
class ProgramNode;
class IntLiteralNode;
class FloatLiteralNode;
class StringLiteralNode;
class CharLiteralNode;
class BoolLiteralNode;
class NullLiteralNode;
class IdentifierNode;
class BinaryExprNode;
class UnaryExprNode;
class AssignmentNode;
class VariableDeclNode;
class CompoundAssignmentNode;
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

class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;
    virtual void visit(const ProgramNode&) = 0;
    virtual void visit(const IntLiteralNode&) = 0;
    virtual void visit(const FloatLiteralNode&) = 0;
    virtual void visit(const StringLiteralNode&) = 0;
    virtual void visit(const CharLiteralNode&) = 0;
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