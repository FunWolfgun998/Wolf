#include <iostream>
#include <fstream>
#include <sstream>
#include "parser/Lexer.h"
#include "parser/Parser.h"
#include "ast/ASTPrinter.h"

// Funzione per leggere il contenuto di un file
std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    try {
        // 1. Leggi il file di input
        std::string filePath = "input.wlf";  // Percorso relativo alla cartella di esecuzione
        std::string sourceCode = readFile(filePath);

        std::cout << "=== Source Code ===" << std::endl;
        std::cout << sourceCode << std::endl;

        // 2. Lexing
        Lexer lexer(sourceCode);
        auto tokens = lexer.getAllTokens();

        std::cout << "\n=== Tokens ===" << std::endl;
        for (const auto& token : tokens) {
            std::cout << "Type: " << static_cast<int>(token.type)
                      << ", Value: '" << token.value << "'" << std::endl;
        }
        std::cout << "Done Token";
        // 3. Parsing
        Parser parser(tokens);
        auto ast = parser.parse();

        // 4. Stampa l'AST
        std::cout << "\n=== Abstract Syntax Tree ===" << std::endl;
        ASTPrinter printer(std::cout);
        ast->accept(printer);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}