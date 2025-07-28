#include "parser/Lexer.h"

#include <iostream>

#include "parser/Token.h"
#include "parser/StateToken.h"

Lexer::Lexer(std::string input)
    : input{std::move(input)},
    pos{0},
    indentStack{0},
    Tokens{},
    currentState{StateToken::Neutral},
    atLineStart{true}
{}
std::vector<Token> Lexer::getAllTokens() {
    while (pos < input.size()) {
        CreateToken();
    }
    return Tokens;
}
void Lexer::CreateToken() {
    switch (currentState) {
        case StateToken::Neutral: {
            if (pos >= input.size()) {
                //End of File
                Tokens.emplace_back(TypeToken::End, "EOF");
                return;
            }
            if(currentChar()== '\n') {
                Tokens.emplace_back(TypeToken::Newline, "\\n");
                currentState = StateToken::Indentation;
                consumeChar();
                break;
            }
            if (currentChar()== '+') {
                currentState = StateToken::OpPlus;
                consumeChar();
                break;
            }
            if (currentChar()== '-') {
                currentState = StateToken::OpMinus;
                consumeChar();
                break;
            }
            if (currentChar()== '*') {
                currentState = StateToken::OpMultiply;
                consumeChar();
                break;
            }
            if(currentChar() == '/') {
                currentState = StateToken::OpDivide;
                consumeChar();
                break;
            }
            if (std::isalpha(currentChar()) || currentChar() == '_') {
                currentState = StateToken::Identifier;
                break;
            }
            if (currentChar() == '=') {}

        }
        case StateToken::Indentation: {
            int count = 0;
            while (pos < input.size()) {
                char c = input[pos++];
                if (c == ' ') count++;
                else if (c == '\t') count += tab_value;
                else break;
            }
            int indent = count / tab_value;
            int lastIndent = indentStack.back();
            atLineStart=false;
            if (indent == lastIndent) {
                currentState = StateToken::Neutral;
                break;
            }
            if (indent > lastIndent) {
                while (lastIndent < indent) {
                    lastIndent++;
                    indentStack.push_back(lastIndent);
                    Tokens.emplace_back(TypeToken::Indent,  std::to_string(lastIndent));
                }
                currentState = StateToken::Neutral;
                break;
            }
            if (indent < lastIndent) {
                while (!indentStack.empty() && indentStack.back() > indent) {
                    indentStack.pop_back();
                    Tokens.emplace_back(TypeToken::Dedent,  std::to_string(indentStack.back()));
                }
                currentState = StateToken::Neutral;
                break;
            }
        }
        case StateToken::OpPlus: {
            if (currentChar() == '=') {
                Tokens.emplace_back(TypeToken::OpPlusAssign, "+=");
                consumeChar();
                currentState = StateToken::Neutral;
                break;
            }
            Tokens.emplace_back(TypeToken::OpPlus, "+");
            currentState = StateToken::Neutral;
            break;
        }
        case StateToken::OpMinus: {
            if (currentChar() == '=') {
                Tokens.emplace_back(TypeToken::OpMinusAssign, "-=");
                consumeChar();
                currentState = StateToken::Neutral;
                break;
            }
            Tokens.emplace_back(TypeToken::OpMinus, "-");
            currentState = StateToken::Neutral;
            break;
        }
        case StateToken::OpMultiply: {
            if (currentChar() == '=') {
                Tokens.emplace_back(TypeToken::OpMultiplyAssign, "*=");
                consumeChar();
                currentState = StateToken::Neutral;
                break;
            }
            Tokens.emplace_back(TypeToken::OpMultiply, "*");
            currentState = StateToken::Neutral;
            break;
        }
        case StateToken::OpDivide: {
            if(currentChar() == '/') {
                currentState = StateToken::SigleLineComment;
                consumeChar();
                break;
            }
            if (currentChar() == '*') {
                currentState = StateToken::MultiLineComment;
                consumeChar();
                break;
            }
            if (currentChar() == '=') {
                Tokens.emplace_back(TypeToken::OpDivideAssign, "/=");
                currentState = StateToken::Neutral;
                consumeChar();
                break;
            }
            Tokens.emplace_back(TypeToken::OpDivide, "/");
            currentState = StateToken::Neutral;
            break;
        }
        case StateToken::Identifier: {
            size_t start = pos;
            while (pos < input.size() && std::isalnum(input[pos]) || input[pos] == '_') {
                consumeChar();
            }
            std::string word = input.substr(start, pos - start);
            auto it = keywords.find(word);
            if (it != keywords.end()) {
                Tokens.emplace_back(it->second, word);
            } else {
                Tokens.emplace_back(TypeToken::Identifier, word);
            }
        }
        case StateToken::SigleLineComment: {
            size_t start = pos;
            while (pos < input.size() && input[pos] != '\n') {
                consumeChar();
            }
            std::string comment = input.substr(start, pos - start);
            Tokens.emplace_back(TypeToken::Comment, comment);

            currentState = StateToken::Neutral;
            break;
        }
        case StateToken::MultiLineComment: {
            const size_t start = pos;
            while (pos + 1 < input.size()) {
                if (input[pos] == '*' && input[pos + 1] == '/') {
                    Tokens.emplace_back(TypeToken::Comment, input.substr(start, pos - start));
                    currentState = StateToken::Neutral;
                    pos += 2;
                    return;
                }
                consumeChar();
            }

            Tokens.emplace_back(TypeToken::Comment, input.substr(start, pos - start));
            currentState = StateToken::Neutral;
            break;
        }
        default:
            break;
    }
}


char Lexer::currentChar() const{
return input[pos];
}
char Lexer::consumeChar(){
    return input[pos++];
}

// const std::unordered_map<std::string, TypeToken> Lexer::keywords = {
//     {"int", TypeToken::Int},
//     {"float", TypeToken::Float},
//     {"char", TypeToken::Char},
//     {"string", TypeToken::String},
//     {"if", TypeToken::If},
//     {"else", TypeToken::Else},
//     {"elif", TypeToken::Elif},
//     {"while", TypeToken::While},
//     {"for", TypeToken::For},
//     {"return", TypeToken::Return},
//     {"break", TypeToken::Break},
//     {"continue", TypeToken::Continue},
//     {"func", TypeToken::Func},
//     {"true", TypeToken::True},
//     {"false", TypeToken::False},
// };
//
// Lexer::Lexer(std::string input)
//     : input(std::move(input)), pos(0), indentStack({0}), atLineStart(true) {}
//
// std::vector<Token> Lexer::getAllTokens() {
//     std::vector<Token> tokens;
//     while (true) {
//         Token token = getToken();
//         tokens.push_back(token);
//         if (token.type == TypeToken::End) {
//             break;
//         }
//     }
//     return tokens;
// }
//
// Token Lexer::getToken() {
//     if (!pendingTokens.empty()) {
//         Token t = pendingTokens.front();
//         pendingTokens.pop();
//         return t;
//     }
//
//     if (pos >= input.size()) {
//         if (indentStack.size() > 1) {
//             indentStack.pop_back();
//             return Token{TypeToken::Dedent, ""};
//         }
//         return Token{TypeToken::End, ""};
//     }
//
//     if (input[pos] == '\n') {
//         pos++;
//         atLineStart = true;
//         return Token{TypeToken::Newline, "\\n"};
//     }
//
//     if (atLineStart) {
//         setIndentation();
//         atLineStart = false;
//
//         if (!pendingTokens.empty()) {
//             Token t = pendingTokens.front();
//             pendingTokens.pop();
//             return t;
//         }
//     }
//     while (pos < input.size() && input[pos] == ' ') {
//         pos++; // ignores spaces
//     }
//     char current = input[pos];
//     if (pos + 1 < input.size() && input[pos] == '/' && (input[pos + 1] == '/' || input[pos + 1] == '*')) {
//         return getComment();
//     }
//     if (isOperatorStart(current)) return getOperator();
//     if (isdigit(current)) return getNumber();
//     if (current == '\'') return getChar();
//     if (current == '"') return getString();
//     if (std::isalpha(current) || current == '_') return getIdentifierOrKeyword();
//
//     pos++;
//     return Token{TypeToken::Unknown, std::string(1, current)};
// }
//
// int Lexer::countIndentation() {
//     int count = 0;
//     size_t tempPos = pos;
//     while (tempPos < input.size()) {
//         char c = input[tempPos];
//         if (c == ' ') count++;
//         else if (c == '\t') count += tab_value;
//         else break;
//         tempPos++;
//     }
//     int indentLevel = count / tab_value;
//     return indentLevel;
// }
//
// void Lexer::setIndentation() {
//     int indent = countIndentation();
//     int lastIndent = indentStack.back();
//
//     int toConsume = indent * tab_value;
//     int consumed = 0;
//     while (consumed < toConsume && pos < input.size()) {
//         if (input[pos] == ' ') consumed++;
//         else if (input[pos] == '\t') consumed += tab_value;
//         else break;
//         pos++;
//     }
//     if (indent == lastIndent) return;
//     if (indent > lastIndent) {
//         while (lastIndent < indent) {
//             lastIndent++;
//             indentStack.push_back(lastIndent);
//             pendingTokens.push(Token{TypeToken::Indent,  std::to_string(indent)});
//         }
//         return;
//     }
//     while (!indentStack.empty() && indentStack.back() > indent) {
//         indentStack.pop_back();
//         pendingTokens.push(Token{TypeToken::Dedent,  std::to_string(indent)});
//     }
// }
//
// Token Lexer::getNumber() {
//     size_t start = pos;
//     bool hasDot = false;
//     bool hasExponent = false;
//     bool foundDigit = false;
//
//     while (pos < input.size()) {
//         char c = input[pos];
//
//         if (isdigit(c)) {
//             foundDigit = true;
//             pos++;
//         }
//         else if (c == '.' && !hasDot && !hasExponent) {
//             hasDot = true;
//             pos++;
//
//             if (pos >= input.size() || !isdigit(input[pos])) {
//                 return Token{TypeToken::Unknown, input.substr(start, pos - start)};
//             }
//         }
//         else if ((c == 'e' || c == 'E') && !hasExponent && foundDigit) {
//             hasExponent = true;
//             pos++;
//
//             if (input[pos] == '+' || input[pos] == '-') {
//                 pos++;
//             }
//
//             if (pos >= input.size() || !isdigit(input[pos])) {
//                 return Token{TypeToken::Unknown, input.substr(start, pos - start)};
//             }
//         }
//         else {
//             break;
//         }
//     }
//
//     std::string number = input.substr(start, pos - start);
//
//     if (!foundDigit) {
//         return Token{TypeToken::Unknown, number};
//     }
//
//     if (hasDot || hasExponent) {
//         return Token{TypeToken::FloatValue, number};
//     } else {
//         return Token{TypeToken::IntValue, number};
//     }
// }
//
// Token Lexer::getChar() {
//     if (input[pos] != '\'') {
//         return Token{TypeToken::Unknown, std::string(1, input[pos++])};
//     }
//
//     size_t start = pos;
//     pos++; // Salta l'apice iniziale
//
//     if (pos >= input.size()) {
//         return Token{TypeToken::Unknown, "'"}; // Non chiuso
//     }
//
//     char c;
//     if (input[pos] == '\\') {
//         pos++; // Salta la barra
//         if (pos >= input.size()) return Token{TypeToken::Unknown, "'\\"};
//
//         switch (input[pos]) {
//             case 'n': c = '\n'; break;
//             case 't': c = '\t'; break;
//             case '\\': c = '\\'; break;
//             case '\'': c = '\''; break;
//             default:
//                 return Token{TypeToken::Unknown, "'\\" + std::string(1, input[pos++])};
//         }
//         pos++; // Salta il carattere dopo
//         } else {
//         c = input[pos++];
//     }
//
//     if (pos >= input.size() || input[pos] != '\'') {
//         return Token{TypeToken::Unknown, input.substr(start, pos - start)};
//     }
//
//     pos++; // Salta l’apice finale
//
//     return Token{TypeToken::CharValue, std::string(1, c)};
// }
//
// Token Lexer::getString() {
//     if (input[pos] != '"') {
//         return Token{TypeToken::Unknown, std::string(1, input[pos++])};
//     }
//
//     size_t start = pos;
//     pos++; // Salta il carattere iniziale "
//
//     std::string result;
//
//     while (pos < input.size()) {
//         char c = input[pos];
//
//         if (c == '"') {
//             pos++;
//             return Token{TypeToken::StringValue, result};
//         }
//
//         if (c == '\\') {
//             pos++; // Salta la barra
//
//             if (pos >= input.size()) {
//                 return Token{TypeToken::Unknown, input.substr(start, pos - start)};
//             }
//
//             char esc = input[pos++];
//             switch (esc) {
//                 case 'n': result += '\n'; break;
//                 case 't': result += '\t'; break;
//                 case 'r': result += '\r'; break;
//                 case '"': result += '"'; break;
//                 case '\\': result += '\\'; break;
//                 default:
//                     // Escape sconosciuto: mantieni \ e il carattere
//                     result += '\\';
//                     result += esc;
//                     break;
//             }
//         } else {
//             result += c;
//             pos++;
//         }
//     }
//     return Token{TypeToken::Unknown, input.substr(start, pos - start)};
// }
//
// Token Lexer::getComment() {
//     if (input[pos] == '/' && pos + 1 < input.size()) {
//         if (input[pos + 1] == '/') {
//             /* Sigle line comment - stops at \n (new line)*/
//             size_t start = pos;
//             pos += 2;
//             while (pos < input.size() && input[pos] != '\n') {
//                 pos++;
//             }
//             std::string comment = input.substr(start, pos - start);
//             return Token{TypeToken::Comment, comment};
//         }
//         else if (input[pos + 1] == '*') {
//             /* Multi line comment - it stops only if is end or find -> */
//             size_t start = pos;
//             pos += 2;
//
//             while (pos + 1 < input.size()) {
//                 if (input[pos] == '*' && input[pos + 1] == '/') {
//                     pos += 2;
//                     std::string comment = input.substr(start, pos - start);
//                     return Token{TypeToken::Comment, comment};
//                 }
//                 pos++;
//             }
//             pos++;
//             std::string comment = input.substr(start, pos - start);
//             return Token{TypeToken::Comment, comment};
//         }
//     }
//     return Token{TypeToken::Unknown, std::string(1, input[pos++])};
// }
//
// Token Lexer::getIdentifierOrKeyword() {
//     size_t start = pos;
//     while (pos < input.size() && (std::isalnum(input[pos]) || input[pos] == '_')) {
//         pos++;
//     }
//
//     std::string word = input.substr(start, pos - start);
//
//     auto it = keywords.find(word);
//     if (it != keywords.end()) {
//         return Token{it->second, word};
//     } else {
//         return Token{TypeToken::Identifier, word};
//     }
// }
//
// bool Lexer::isOperatorStart(char c) const {
//     static const std::string operatorChars = "=+-*/%&|<>!~^():!";
//     return operatorChars.find(c) != std::string::npos;
// }
//
// Token Lexer::getCompoundOperator(char first) {
//     char second = (pos < input.size()) ? input[pos] : '\0';
//     std::string twoCharOp = std::string(1, first) + second;
//
//     static const std::unordered_map<std::string, TypeToken> compoundOps = {
//         {"==", TypeToken::OpEqual},
//         {"!=", TypeToken::OpNotEqual},
//         {"<=", TypeToken::OpLessEqual},
//         {">=", TypeToken::OpGreaterEqual},
//         {"&&", TypeToken::OpAnd},
//         {"||", TypeToken::OpOr},
//         {"+=", TypeToken::OpPlusAssign},
//         {"-=", TypeToken::OpMinusAssign},
//         {"*=", TypeToken::OpMultiplyAssign},
//         {"/=", TypeToken::OpDivideAssign},
//         {"%=", TypeToken::OpModuloAssign},
//         {"<<", TypeToken::OpShiftLeft},
//         {">>", TypeToken::OpShiftRight}
//     };
//
//     auto it = compoundOps.find(twoCharOp);
//     if (it != compoundOps.end()) {
//         pos++;
//         return Token{it->second, twoCharOp};
//     }
//
//     return Token{TypeToken::Unknown, std::string(1, first)};
// }
//
// Token Lexer::getOperator() {
//     char first = input[pos++];
//
//     if (pos < input.size()) {
//         Token compound = getCompoundOperator(first);
//         if (compound.type != TypeToken::Unknown) {
//             return compound;
//         }
//     }
//
//     // Gestione operatori singoli
//     static const std::unordered_map<char, TypeToken> singleOps = {
//         {'=', TypeToken::OpAssign},
//         {'+', TypeToken::OpPlus},
//         {'-', TypeToken::OpMinus},
//         {'*', TypeToken::OpMultiply},
//         {'/', TypeToken::OpDivide},
//         {'%', TypeToken::OpModulo},
//         {'<', TypeToken::OpLess},
//         {'>', TypeToken::OpGreater},
//         {'(', TypeToken::LeftParen},
//         {')', TypeToken::RightParen},
//         {':', TypeToken::Colon},
//         {'!', TypeToken::OpNot},
//
//
//     };
//
//     auto it = singleOps.find(first);
//     if (it != singleOps.end()) {
//         return Token{it->second, std::string(1, first)};
//     }
//
//     return Token{TypeToken::Unknown, std::string(1, first)};
// }
//
// void Lexer::skipWhitespace() {
//     while (pos < input.size() && input[pos] == ' ') {
//         pos++;
//     }
// }
