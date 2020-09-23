//
// Created by Mario Martinez on 22/09/20.
//

#ifndef ARBOL_BINARIO_BUSQUEDA_GESTOR_H
#define ARBOL_BINARIO_BUSQUEDA_GESTOR_H


#include "../bl/Arbin.h"

class Gestor {
public:
    Gestor();

    Arbin *getArbol() const;

    void setArbol(Arbin *arbol);

    bool insertarElem(int); //Inserta un entero en el árbol ordenado.

private:
    Arbin *arbol;
};


#endif //ARBOL_BINARIO_BUSQUEDA_GESTOR_H
