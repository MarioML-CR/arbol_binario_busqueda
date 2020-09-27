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

string Gestor::camino(int inicio, int final) {
    string camino = arbol->camino(inicio, final);
    if(camino.substr(camino.length()-1, camino.length()-1) == " "){
        camino = "No hay camino entre los valores ingresados\n";
    }
    return camino;
}

string Gestor::preOrden() {
    string preorden = arbol->preOrden();
    preorden = preorden.substr(0, preorden.length() - 3);
    return preorden;
}

string Gestor::inOrden() {
    string inOrden = arbol->inOrden();
    inOrden = inOrden.substr(0, inOrden.length() - 3);
    return inOrden;
}




