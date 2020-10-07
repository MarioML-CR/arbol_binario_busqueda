//
// Created by Mario Martinez on 22/09/20.
//

#ifndef ARBOL_BINARIO_BUSQUEDA_GESTOR_H
#define ARBOL_BINARIO_BUSQUEDA_GESTOR_H


#include "../bl/Arbin.h"

class Gestor {
public:
    Gestor();

    Arbin *getArbolA() const;

    void setArbolA(Arbin *arbol);

    Arbin *getArbolB() const;

    void setArbolB(Arbin *arbolB);

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

    string postOrden(); // Imprime el Arbin de forma IDR (izquierda - derecha - raíz)

    string eliminarElemIzq(int); //Elimina un elemento del Arbin por la izq

    string eliminarElemDer(int); //Elimina un elemento del Arbin por la der

    string esLleno(); //Retorna si un Arbin es completo o no

    string esCompleto(); // Retorna si un Arbin es completo o no

    bool insertarElemB(int); //Inserta un entero en el árbol ordenado.

    string sonArbolesIguales(); // Verifica si dos árboles son iguales

    string sonArbolesSemejantes(); // Verifica si dos árboles son semejantes

    string sonArbolesIsomorfos(); // Verifica si dos árboles son isomorfos

private:
    Arbin *arbolA;

    Arbin *arbolB;
};


#endif //ARBOL_BINARIO_BUSQUEDA_GESTOR_H
