//
// Created by Mario Martinez on 22/09/20.
//

#include "Gestor.h"

Gestor::Gestor() {
    arbol = new Arbin();
}

Arbin *Gestor::getArbol() const {
    return arbol;
}

void Gestor::setArbol(Arbin *arbol) {
    Gestor::arbol = arbol;
}

bool Gestor::insertarElem(int pValor) {
    return arbol->insertarElem(pValor);
}
