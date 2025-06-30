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
        test/ast_tests.cpp
        include/parser/Token.h
        src/Parser/Token.cpp
        test/parser_tests.cpp
        include/ast/ASTPrinter.h
        src/ast/ASTPrinter.cpp
        include/parser/ParseError.h
        include/ast/ASTNode.h
        include/ast/nodes/BinaryExprNode.h
        include/ast/nodes/ProgramNode.h
        include/ast/nodes/IntLiteralNode.h
        include/ast/nodes/StringLiteralNode.h
        include/ast/nodes/BootLiteralNode.h
        include/ast/nodes/NullLiteralNode.h
        include/ast/nodes/IdentifierNode.h
        include/ast/nodes/AssignmentNode.h
        include/ast/nodes/UnaryExprNode.h
        include/ast/nodes/VariableDeclNode.h
        include/ast/nodes/AllNodes.h
        include/ast/nodes/VariableInitNode.h
        include/ast/nodes/CharLiteralNode.h
        src/ast/ASTNode.cpp
)

# Includi i file header
target_include_directories(Wolf PRIVATE include)
