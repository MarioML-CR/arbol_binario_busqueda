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

    int pesoArbin(); //Calcula el número de elementos del Arbin

    bool esVacioArbin(); //Retorna si un Arbin es vacío o no

    int buscarMaximo(); //Busca el elemento de mayor valor

    int buscarMinimo(); //Busca el elemento de menor valor

    string esHoja(int); //Dice si un Arbin es hoja o no

private:
    Arbin *arbol;
};


#endif //ARBOL_BINARIO_BUSQUEDA_GESTOR_H
