//
// Created by Personal on 29/06/2025.
//
#include "ast/ASTNode.h"
#include "ast/ASTVisitor.h"

// Explicit template instantiations
template class ASTNode<ProgramNode>;
template class ASTNode<IntLiteralNode>;
template class ASTNode<FloatLiteralNode>;
template class ASTNode<StringLiteralNode>;
template class ASTNode<BoolLiteralNode>;
template class ASTNode<NullLiteralNode>;
template class ASTNode<IdentifierNode>;
template class ASTNode<BinaryExprNode>;
template class ASTNode<UnaryExprNode>;
template class ASTNode<AssignmentNode>;
template class ASTNode<VariableDeclNode>;
template class ASTNode<CompoundAssignmentNode>;
template class ASTNode<VariableInitNode>;
template class ASTNode<FunctionDeclNode>;
template class ASTNode<FunctionParamNode>;
template class ASTNode<ClassDeclNode>;
template class ASTNode<ClassPropertyNode>;
template class ASTNode<ClassMethodNode>;
template class ASTNode<CallExprNode>;
template class ASTNode<MethodCallNode>;
template class ASTNode<ArrayAccessNode>;
template class ASTNode<MemberAccessNode>;
template class ASTNode<NewExprNode>;
template class ASTNode<BlockNode>;
template class ASTNode<IfNode>;
template class ASTNode<ElseNode>;
template class ASTNode<ForNode>;
template class ASTNode<WhileNode>;
template class ASTNode<DoWhileNode>;
template class ASTNode<SwitchNode>;
template class ASTNode<CaseNode>;
template class ASTNode<ReturnNode>;
template class ASTNode<BreakNode>;
template class ASTNode<ContinueNode>;
template class ASTNode<ThrowNode>;
template class ASTNode<TryCatchNode>;
template class ASTNode<ImportNode>;
template class ASTNode<ExportNode>;
template class ASTNode<TypeAnnotationNode>;
template class ASTNode<TemplateDeclNode>;
template class ASTNode<GenericTypeNode>;
template class ASTNode<YieldNode>;
template class ASTNode<AwaitNode>;
template class ASTNode<CommentNode>;
template class ASTNode<DirectiveNode>;