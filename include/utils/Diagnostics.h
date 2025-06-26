//
// Created by Personal on 09/06/2025.
//

#ifndef LOG_TOOLS_H
#define LOG_TOOLS_H
inline const char* typeTokenToString(TypeToken type) {
    switch (type) {
        // Type of value
        case TypeToken::Int: return "TypeInt";
        case TypeToken::Float: return "TypeFloat";
        case TypeToken::Char: return "TypeChar";
        case TypeToken::String: return "TypeString";

        // Value
        case TypeToken::IntValue: return "IntValue";
        case TypeToken::FloatValue: return "FloatValue";
        case TypeToken::CharValue: return "CharValue";
        case TypeToken::StringValue: return "StringValue";

        // Logic gates
        case TypeToken::If: return "If";
        case TypeToken::Else: return "Else";
        case TypeToken::Elif: return "Elif";
        case TypeToken::While: return "While";
        case TypeToken::For: return "For";
        case TypeToken::Return: return "Return";
        case TypeToken::Break: return "Break";
        case TypeToken::Continue: return "Continue";
        case TypeToken::True: return "True";
        case TypeToken::False: return "False";

        // Functions
        case TypeToken::Func: return "Func";

        // Structure
        case TypeToken::Indent: return "Indent";
        case TypeToken::Dedent: return "Dedent";
        case TypeToken::Newline: return "Newline";
        case TypeToken::End: return "End";

        // Operators and punctuation
        case TypeToken::OpAssign: return "OpAssign";
        case TypeToken::OpPlus: return "OpPlus";
        case TypeToken::OpMinus: return "OpMinus";
        case TypeToken::OpMultiply: return "OpMultiply";
        case TypeToken::OpDivide: return "OpDivide";
        case TypeToken::OpModulo: return "OpModulo";
        case TypeToken::OpEqual: return "OpEqual";
        case TypeToken::OpNotEqual: return "OpNotEqual";
        case TypeToken::OpLess: return "OpLess";
        case TypeToken::OpLessEqual: return "OpLessEqual";
        case TypeToken::OpGreater: return "OpGreater";
        case TypeToken::OpGreaterEqual: return "OpGreaterEqual";
        case TypeToken::OpAnd: return "OpAnd";
        case TypeToken::OpOr: return "OpOr";
        case TypeToken::OpNot: return "OpNot";
        case TypeToken::OpPlusAssign: return "OpPlusAssign";
        case TypeToken::OpMinusAssign: return "OpMinusAssign";
        case TypeToken::OpMultiplyAssign: return "OpMultiplyAssign";
        case TypeToken::OpDivideAssign: return "OpDivideAssign";
        case TypeToken::OpModuloAssign: return "OpModuloAssign";
        case TypeToken::OpShiftLeft: return "OpShiftLeft";
        case TypeToken::OpShiftRight: return "OpShiftRight";
        case TypeToken::Colon: return "Colon";

        // Other
        case TypeToken::Comment: return "Comment";
        case TypeToken::VarName: return "Identifier";
        case TypeToken::Unknown: return "Unknown";

        default: return "???";
    }
}
#endif //LOG_TOOLS_H
