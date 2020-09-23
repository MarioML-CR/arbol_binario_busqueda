//
// Created by Mario Martinez on 22/09/20.
//

#include "Arbin.h"
/**
 * Método:          Arbin
 * Descripción:     constructor de la clase Arbin (Árbol binario o de búsquda)
 * que inicializa de los parámetros.
 */
Arbin::Arbin() {
    setPeso(0);
    setRaiz(nullptr);
}

Arbin::~Arbin() {}

Nodo *Arbin::getRaiz() const {
    return raiz;
}

void Arbin::setRaiz(Nodo *raiz) {
    Arbin::raiz = raiz;
}

int Arbin::getPeso() const {
    return peso;
}

void Arbin::setPeso(int peso) {
    Arbin::peso = peso;
}
/**
 * Método:          pesoArbin
 * Descripción:     método que permite obtener el peso del árbol binario
 * @return          variable de tipo int que representa el número de
 * elementos que tiene el árbol.
 */
int Arbin::pesoArbin() {
    return getPeso();
}
/**
 * Método:          esVacioArbin
 * Descripción:     Método que permite verificar si el árbol está vacío o no
 * @return          variable de tipo booleana, si es vacia retorna true, y
 * false en caso contrario.
 */
bool Arbin::esVacioArbin() {
    if (getPeso()==0){
        return true;
    } else {
        return false;
    }
}

bool Arbin::insertarElemRecursivo(Nodo *nodo, int pValor) {
    if (nodo == nullptr){
        nodo = new Nodo(pValor);
        if(getPeso()== 0){
            setRaiz(nodo);
        }
        setPeso(getPeso() + 1);
        return true;
    } else if (pValor > nodo->getNum()){
        insertarElemRecursivo(nodo->getIzq(), pValor);
    } else if (pValor < nodo->getNum()) {
        insertarElemRecursivo(nodo->getDer(), pValor);
    } else {
        return false;
    }
}

bool Arbin::insertarElem(int pValor) {
    return insertarElemRecursivo(getRaiz(), pValor);
}