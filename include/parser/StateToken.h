//
// Created by Crys on 09/07/2025.
//

#ifndef STATETOKEN_H
#define STATETOKEN_H
enum class StateToken {
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
    LeftParen,
    RightParen,

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
    Identifier,
    Unknown,
    Neutral
};

#endif //STATETOKEN_H
