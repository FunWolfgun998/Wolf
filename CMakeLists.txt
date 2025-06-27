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
        include/ast/ASTVisitor.h
        src/ast/nodes/Declarations.cpp
        src/ast/nodes/Expressions.cpp
        src/ast/nodes/Statements.cpp
        test/ast_tests.cpp
        include/parser/Token.h
        src/Parser/Token.cpp
        test/parser_tests.cpp
        src/ast/nodes/Literals.cpp
        include/ast/ASTPrinter.h
        src/ast/ASTPrinter.cpp
        include/parser/ParseError.h
        include/ast/ASTNode.h
        include/ast/nodes/BinaryExprNode.h
        include/ast/nodes/ProgramNode.h
        include/ast/nodes/IntLiteralNode.h
)

# Includi i file header
target_include_directories(Wolf PRIVATE include)
