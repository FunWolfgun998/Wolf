#ifndef RESOURCES_H
#define RESOURCES_H

#include <memory>
#include <vector>
#include <string>

// Configurazione
#define TAB_VALUE 4

// ======================================================
// Tipi di Token (mantenuto da versione originale)
// ======================================================
enum class TypeToken {
    // Tipi di valore
    Int,
    Float,
    Char,
    String,

    // Valori
    IntValue,
    FloatValue,
    CharValue,
    StringValue,

    // Strutture di controllo
    If,
    Else,
    Elif,
    While,
    For,
    Return,
    Break,
    Continue,
    True,
    False,

    // Funzioni
    Func,

    // Struttura
    Indent,
    Dedent,
    Newline,
    End,

    // Punteggiatura
    Colon,

    // Operatori (mantenuti dalla versione originale)
    OpAssign, OpPlus, OpMinus, OpMultiply, OpDivide, OpModulo,
    OpEqual, OpNotEqual, OpLess, OpLessEqual, OpGreater, OpGreaterEqual,
    OpAnd, OpOr, OpNot,
    OpPlusAssign, OpMinusAssign, OpMultiplyAssign, OpDivideAssign, OpModuloAssign,
    OpShiftLeft, OpShiftRight,

    // Altro
    Comment,
    Identifier,
    Unknown
};

// ======================================================
// Tipi di Nodi AST
// ======================================================
enum class NodeType {
    // Dichiarazioni
    Program,
    VariableDecl,
    VariableInit,
    FunctionDecl,
    
    // Espressioni
    BinaryExpr,
    UnaryExpr,
    Literal,
    Identifier,
    
    // Statement
    Block,
    If,
    For,
    While,
    Return,
    
    // Altri
    Import,
    TypeAnnotation
};

// ======================================================
// Interfaccia base AST (sostituisce NodeAST)
// ======================================================
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual NodeType getType() const = 0;
    virtual std::vector<Token> getTokens() const = 0;
    virtual std::string toString() const = 0;
};

#endif // RESOURCES_H