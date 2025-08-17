//
// Created by Crys on 09/07/2025.
//

#ifndef STATETOKEN_H
#define STATETOKEN_H
enum class StateToken {
    //All states are in the same order of the switch in the lexer
    Neutral,
    Indentation,
    Op,
    Identifier,
    Number,
    SigleLineComment,
    MultiLineComment,
    Char,
    String,
};

#endif //STATETOKEN_H
