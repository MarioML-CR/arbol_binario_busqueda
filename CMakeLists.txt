cmake_minimum_required(VERSION 3.16)
project(arbol_binario_busqueda)

set(CMAKE_CXX_STANDARD 20)

add_executable(arbol_binario_busqueda arbol/ui/main.cpp arbol/utilitario/Validar.cpp arbol/utilitario/Validar.h arbol/tl/Gestor.cpp arbol/tl/Gestor.h arbol/bl/Nodo.cpp arbol/bl/Nodo.h arbol/bl/Arbin.cpp arbol/bl/Arbin.h)