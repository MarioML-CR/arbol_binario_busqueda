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

bool Gestor::insertarElem(int pValor) {
    return arbol->insertarElem(pValor);
}

int Gestor::pesoArbin() {
    return arbol->getPeso();
}

bool Gestor::esVacioArbin() {
    return arbol->esVacioArbin();
}

void Gestor::setArbol(Arbin *arbol) {
    Gestor::arbol = arbol;
}

int Gestor::buscarMaximo() {
    return arbol->buscarMaximo();
}

int Gestor::buscarMinimo() {
    return arbol->buscarMinimo();
}

string Gestor::esHoja(int pValor) {
    return arbol->esHoja(pValor);
}

int Gestor::nivel() {
    return arbol->nivel();
}

int Gestor::altura() {
    return arbol->altura();
}

int Gestor::numHojas() {
    return arbol->numHojas();
}




