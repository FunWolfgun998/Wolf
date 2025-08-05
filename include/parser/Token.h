//
// Created by Personal on 13/06/2025.
//
#ifndef MY_PARSER_TOKEN_H
#define MY_PARSER_TOKEN_H
enum class TypeToken {
    // Type (4)
    Int,        // 0
    Float,      // 1
    Char,       // 2
    String,     // 3

    // Type of value (4)
    IntValue,   // 4
    FloatValue, // 5
    CharValue,  // 6
    StringValue,// 7

    // Logic gates (10)
    If,         // 8
    Else,       // 9
    Elif,       // 10
    While,      // 11
    For,        // 12
    Return,     // 13
    Break,      // 14
    Continue,   // 15
    True,       // 16
    False,      // 17

    // Functions (1)
    Func,       // 18

    // Structure (6)
    Indent,     // 19
    Dedent,     // 20
    Newline,    // 21
    End,        // 22
    LeftParen,  // 23
    RightParen, // 24

    // Punctuation (1)
    Colon,      // 25

    // Basic operators (7)
    OpAssign,   // 26 ( = )
    OpPlus,     // 27 ( + )
    OpMinus,    // 28 ( - )
    OpMultiply, // 29 ( * )
    OpDivide,   // 30 ( / )
    OpModulo,   // 31 ( % )
    OpXor,        // 32 ( ^ )

    // Comparison operators (6)
    OpEqual,    // 33 ( == )
    OpNotEqual, // 34 ( != )
    OpLess,     // 35 ( < )
    OpLessEqual,// 36 ( <= )
    OpGreater,  // 37 ( > )
    OpGreaterEqual, // 38 ( >= )

    // Logical operators (3)
    OpAnd,      // 39 ( && )
    OpOr,       // 40 ( || )
    OpNot,      // 41 ( ! )

    // Compound operators (7)
    OpPlusAssign,   // 42 ( += )
    OpMinusAssign,  // 43 ( -= )
    OpMultiplyAssign, // 44 ( *= )
    OpDivideAssign, // 45 ( /= )
    OpModuloAssign, // 46 ( %= )
    OpShiftLeft,    // 47 ( << )
    OpShiftRight,   // 48 ( >> )

    // Other (3)
    Comment,    // 49
    Identifier, // 50
    Unknown     // 51
};

struct Token {
    TypeToken type;
    std::string value;
    size_t line;
    size_t column;

    Token(TypeToken t, std::string val, size_t ln = 0, size_t col = 0)
        : type(t), value(std::move(val)), line(ln), column(col) {}
};
#endif // MY_PARSER_TOKEN_H



