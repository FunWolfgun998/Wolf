//
// Created by Personal on 11/06/2025.
//

#ifndef RESOURCES_H
#define RESOURCES_H

#define tab_value 4

enum class TypeToken {
    // Type of value
    Int,
    Float,
    Char,
    String,

    // Value
    IntValue,
    FloatValue,
    CharValue,
    StringValue,

    // Logic gates
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

    // Functions
    Func,

    // Structure
    Indent,
    Dedent,
    Newline,
    End,

    //Punctuation
    Colon,

    // Basic operators
    OpAssign,       // =
    OpPlus,         // +
    OpMinus,        // -
    OpMultiply,     // *
    OpDivide,       // /
    OpModulo,       // %

    // Comparison operators
    OpEqual,        // ==
    OpNotEqual,     // !=
    OpLess,         // <
    OpLessEqual,    // <=
    OpGreater,      // >
    OpGreaterEqual, // >=

    // Logical operators
    OpAnd,          // &&
    OpOr,           // ||
    OpNot,          // !

    // Compound operators
    OpPlusAssign,   // +=
    OpMinusAssign,  // -=
    OpMultiplyAssign, // *=
    OpDivideAssign, // /=
    OpModuloAssign, // %=
    OpShiftLeft,// <<
    OpShiftRight,// >>

    // Other
    Comment,
    VarName,
    Unknown
};
enum class TypeParser {
    IntInitialization,
    IntDeclaration,
    FloatInitialization,
    FloatDeclaration,
    CharInitialization,
    CharDeclaration,
    StringInitialization,
    StringDeclaration,
    Endprogram,
    Unknown
};
struct Token {
    TypeToken type;
    std::string value;
};
struct NodeAST {

    TypeParser type;
    Token value; // leaf value
    std::vector<Token> leafs; // branch value

    // Constructor of the leaf note
    NodeAST(TypeParser type, Token value) : type(type), value(value) {}

    // Constructor of the branch note
    NodeAST(TypeParser type, std::vector<Token> leafs) : type(type), leafs(std::move(leafs)) {}
};
#endif