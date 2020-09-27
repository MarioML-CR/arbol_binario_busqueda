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

    int nivel(); //Calcula del nivel de un Arbin

    int altura(); // calcula la altura del árbol.

    int numHojas(); //Calcula el número de hojas de un Arbin

    string camino(int, int); // Calcula el camino entre dos elementos del Arbin

    string preOrden(); // Imprime el Arbin de forma RID (raíz - izquierda - derecha)

    string inOrden(); // Imprime el Arbin de forma IRD (izquierda - raíz - derecha)

private:
    Arbin *arbol;
};


#endif //ARBOL_BINARIO_BUSQUEDA_GESTOR_H
