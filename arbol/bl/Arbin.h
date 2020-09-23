//
// Created by Mario Martinez on 22/09/20.
//

#ifndef ARBOL_BINARIO_BUSQUEDA_ARBIN_H
#define ARBOL_BINARIO_BUSQUEDA_ARBIN_H
#include <string>
using namespace std;

#include "Nodo.h"

class Arbin {
public:
    Arbin();

    virtual ~Arbin();

    Nodo *getRaiz() const;

    void setRaiz(Nodo *raiz);

    int getPeso() const;

    void setPeso(int peso);

    int pesoArbin(); //Calcula el número de elementos del Arbin

    bool esVacioArbin(); //Retorna si un Arbin es vacío o no

    bool insertarElem(int); //Inserta un entero en el árbol ordenado.

    bool eliminarElem(int); //Elimina un elemento del Arbin.

    bool esHoja(int); //Dice si un Arbin es hoja o no

    int numHojas(); //Calcula el número de hojas de un Arbin

    bool hayCamino(int, int); //Dice si hay camino entre dos elementos del Arbin

    int altura(); //Calcula la altura de un Arbin

    bool esCompleto(); //Retorna si un Arbin es completo o no

    bool igualesArbin(); //Dice si dos Arbin son iguales o no.

    string imprimirArbin(); //Imprime el arbol binario

    int buscarMaximo(); //Busca el elemento de mayor valor

    int buscarMinimo(); //Busca el elemento de menor valor

private:
    Nodo *raiz;
    int peso;

    bool insertarElemRecursivo(Nodo* , int); //Inserta un entero en el árbol ordenado.

    string imprimirArbinRecursivo(); //Imprime el arbol binario
};


#endif //ARBOL_BINARIO_BUSQUEDA_ARBIN_H
