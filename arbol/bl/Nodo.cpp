//
// Created by Mario Martinez on 22/09/20.
//

#include "Nodo.h"

Nodo::Nodo() {
    setNum(0);
    setDer(nullptr);
    setIzq(nullptr);
}

Nodo::Nodo(int num) : num(num), der(nullptr), izq(nullptr) {}

Nodo::~Nodo() {

}

int Nodo::getNum() const {
    return num;
}

void Nodo::setNum(int num) {
    Nodo::num = num;
}

Nodo *Nodo::getIzq() const {
    return izq;
}

Nodo *Nodo::getDer() const {
    return der;
}

void Nodo::setIzq(Nodo *izq) {
    Nodo::izq = izq;
}

void Nodo::setDer(Nodo *der) {
    Nodo::der = der;
}

