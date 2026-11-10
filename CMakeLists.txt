cmake_minimum_required(VERSION 4.1)
project(kanban)

set(CMAKE_CXX_STANDARD 17)

add_executable(kanban
        main.cpp
        dominios.cpp
        dominios.h
        entidades.cpp
        entidades.h
        utilitarios.cpp
        utilitarios.h
        interfaces.h
        servico_pessoa.cpp
        servico_pessoa.h
        apresentacao_pessoa.cpp
        apresentacao_pessoa.h
)
