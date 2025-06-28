//
// Created by Personal on 13/06/2025.
//
#ifndef MY_PARSER_TOKEN_H
#define MY_PARSER_TOKEN_H
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
    Unknown
};

struct Token {
    TypeToken type;
    std::string value;
    size_t line;    // Aggiungi questo
    size_t column;  // Aggiungi questo

    // Costruttore
    Token(TypeToken t, std::string val, size_t ln = 0, size_t col = 0)
        : type(t), value(std::move(val)), line(ln), column(col) {}
};
#endif // MY_PARSER_TOKEN_H



