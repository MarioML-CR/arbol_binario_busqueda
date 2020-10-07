//
// Created by Mario Martinez on 22/09/20.
//

#include "Gestor.h"

Gestor::Gestor() {
    arbolA = new Arbin();
    arbolB = new Arbin();
}

Arbin *Gestor::getArbolA() const {
    return arbolA;
}
void Gestor::setArbolA(Arbin *arbol) {
    Gestor::arbolA = arbol;
}

bool Gestor::insertarElem(int pValor) {
    return getArbolA()->insertarElem(pValor);
}

int Gestor::pesoArbin() {
    return getArbolA()->getPeso();
}

bool Gestor::esVacioArbin() {
    return getArbolA()->esVacioArbin();
}


int Gestor::buscarMaximo() {
    return getArbolA()->buscarMaximo();
}

int Gestor::buscarMinimo() {
    return getArbolA()->buscarMinimo();
}

string Gestor::esHoja(int pValor) {
    if (getArbolA()->esHoja(pValor)){
        return "El valor ingresado es hoja";
    } else {
        return "El valor ingresado no es hoja";
    }
}

int Gestor::nivel() {
    return getArbolA()->nivel();
}

int Gestor::altura() {
    return getArbolA()->altura();
}

int Gestor::numHojas() {
    return getArbolA()->numHojas();
}

string Gestor::camino(int inicio, int final) {
    string camino = getArbolA()->camino(inicio, final);
    if(camino.substr(camino.length()-1, camino.length()-1) == " "){
        camino = "No hay camino entre los valores ingresados\n";
    }
    return camino;
}

string Gestor::preOrden() {
    string preorden = getArbolA()->preOrden();
    preorden = preorden.substr(0, preorden.length() - 3);
    return preorden;
}

string Gestor::inOrden() {
    string inOrden = getArbolA()->inOrden();
    inOrden = inOrden.substr(0, inOrden.length() - 3);
    return inOrden;
}

string Gestor::postOrden() {
    string postOrden = getArbolA()->postOrden();
    postOrden = postOrden.substr(0, postOrden.length() - 3);
    return postOrden;
}

string Gestor::eliminarElemIzq(int pValor) {
    bool resultado = getArbolA()->eliminarElem(pValor, 0);
    if (resultado){
        return "El elemento se eliminó satisfactoriamente\n";
    } else {
        return "El elemento No fue eliminado\n";
    }
}

string Gestor::eliminarElemDer(int pValor) {
    bool resultado = getArbolA()->eliminarElem(pValor, 1);
    if (resultado){
        return "El elemento se eliminó satisfactoriamente\n";
    } else {
        return "El elemento No fue eliminado\n";
    }
}

string Gestor::esLleno() {
    bool esLleno = getArbolA()->esLleno();
    if (esLleno){
        return "El árbol está lleno\n";
    } else {
        return "El árbol no está lleno\n";
    }
}
string Gestor::esCompleto() {
    bool completo = getArbolA()->esCompleto();
    if (completo){
        return "El árbol está completo\n";
    } else {
        return "El árbol no está completo\n";
    }
}
Arbin *Gestor::getArbolB() const {
    return arbolB;
}

void Gestor::setArbolB(Arbin *arbolB) {
    Gestor::arbolB = arbolB;
}

bool Gestor::insertarElemB(int pValor) {
    return getArbolB()->insertarElem(pValor);
}

string Gestor::sonArbolesIguales() {
    bool iguales = getArbolA()->sonArbolesIguales(getArbolB()->getRaiz());
    if (iguales){
        return "Son iguales\n";
    } else {
        return "No son iguales\n";
    }
}
string Gestor::sonArbolesSemejantes() {
    bool semejantes = getArbolA()->sonArbolesSemejantes(getArbolB()->getRaiz());
    if (semejantes){
        return "Son semejantes\n";
    } else {
        return "No son semejantes\n";
    }
}

string Gestor::sonArbolesIsomorfos() {
    bool semejantes = getArbolA()->sonArbolesIsomorfos(getArbolB()->getRaiz());
    if (semejantes){
        return "Son isomorfos\n";
    } else {
        return "No son isomorfos\n";
    }
}