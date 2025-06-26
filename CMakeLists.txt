cmake_minimum_required(VERSION 3.31)
project(Wolf)

set(CMAKE_CXX_STANDARD 20)

# Aggiungi tutti i file sorgente
add_executable(Wolf
        src/main.cpp
        src/Parser/Lexer.cpp
        src/Parser/Parser.cpp

        include/parser/parser.h
        include/parser/Lexer.h
        include/ast/ast.h
        include/utils/Diagnostics.h
        include/utils/resources.h
        include/ast/nodes/Declarations.h
        include/ast/nodes/Expressions.h
        include/ast/nodes/Statements.h
        include/ast/ASTVisitor.h
        src/ast/nodes/Declarations.cpp
        src/ast/nodes/Expressions.cpp
        src/ast/nodes/Statements.cpp
        test/ast_tests.cpp
        include/parser/Token.h
        src/Parser/Token.cpp
        test/parser_tests.cpp
        include/ast/nodes/Literals.h
        src/ast/nodes/Literals.cpp
        include/ast/ASTPrinter.h
        src/ast/ASTPrinter.cpp
        include/parser/ParseError.h
        include/ast/ASTNode.h
)

# Includi i file header
target_include_directories(Wolf PRIVATE include)
