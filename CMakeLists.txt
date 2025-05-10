cmake_minimum_required(VERSION 3.31)
project(Wolf)

set(CMAKE_CXX_STANDARD 20)

# Aggiungi tutti i file sorgente
add_executable(Wolf
        src/main.cpp
        src/lexer.cpp
        src/parser.cpp
        src/ast.cpp
        src/compiler.cpp

        include/parser.h
        include/lexer.h
        include/ast.h
        include/compiler.h
)

# Includi i file header
target_include_directories(Wolf PRIVATE include)
