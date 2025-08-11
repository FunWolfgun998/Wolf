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
    Number,
    FloatNumber,
    CharValue,
    StringValue,

    // Functions
    Func,

    // Structure
    Indentation,
    Newline,
    End,
    LeftParen,
    RightParen,

    //Punctuation
    Colon,

    Op,


    // Other
    SigleLineComment,
    MultiLineComment,
    Identifier,
    Unknown,
    Neutral
};

#endif //STATETOKEN_H
