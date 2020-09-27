//
// Created by Mario Martinez on 22/09/20.
//

#include <iostream>
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
/**
 * Método:              insertarElemRecursivo
 * Descripción:         Método que permite hacer la inserción de un arbol binario (ordenado)
 * @param nodoRaiz      representa el nodo raiz,
 * @param nodoHijo      representa el nodo hijo
 * @param pValor        representa el valor a insertar, variable de tipo int
 * @param tipo          representa el tipo de hijo, 1 es izquierdo y 2 es derecho.
 */
void Arbin::insertarElemRecursivo(Nodo *nodoRaiz, Nodo *nodoHijo, int pValor, int tipo) {
    if (nodoRaiz == nullptr){
        nodoRaiz = new Nodo(pValor);
        if(getPeso()== 0){
            setRaiz(nodoRaiz);
        } else if (tipo == 1){
            nodoHijo->setIzq(nodoRaiz);
        } else if (tipo == 2) {
            nodoHijo->setDer(nodoRaiz);
        }
        setPeso(getPeso() + 1);
//        return true;
    } else if (pValor < nodoRaiz->getNum()){
        insertarElemRecursivo(nodoRaiz->getIzq(), nodoRaiz, pValor, 1);
    } else if (pValor > nodoRaiz->getNum()) {
        insertarElemRecursivo(nodoRaiz->getDer(), nodoRaiz, pValor, 2);
    }
}
/**
 * Método:              insertarElem
 * Descripción:         Método que permite enviar a insertar el valor al árbol
 * @param pValor        representa el valor a ingresar al árbol
 * @return              varible de tipo bool (true) indicando que se cargó correctamente.
 */
bool Arbin::insertarElem(int pValor) {
    insertarElemRecursivo(getRaiz(), new Nodo(), pValor ,0);
    return true;
}
/**
 * Método:              buscarMaximo
 * Descripción:         Método que permite buscar el valor máximo en el árbol
 * @return              variable de tipo int que representa el valor máximo del árbol
 */
int Arbin::buscarMaximo() {
    if (getRaiz() == nullptr){
        return NULL;
    } else {
        Nodo *aux = getRaiz();
        do {
            aux = aux->getDer();
        } while (aux->getDer() != nullptr);
        return aux->getNum();
    }
}
/**
 * Método:              buscarMinimo
 * Descripción:         Método que permite buscar el valor mínimo en el árbol
 * @return              variable de tipo int que representa el valor mínimo del árbol
 */
int Arbin::buscarMinimo() {
    if (getRaiz() == nullptr){
        return NULL;
    } else {
        Nodo *aux = getRaiz();
        do {
            aux = aux->getIzq();
        } while (aux->getIzq() != nullptr);
        return aux->getNum();
    }
}
/**
 * Método:              esHoja
 * Descripción:         Método que permite establecer si al valor ingresado
 * es hoja o no, si no existe en el arbol o si no hay datos en el árbol.
 * @param pValor        valor que representa el valor a buscar en el árbol.
 * @return              variable de tipo string con el resultado de la búsqueda.
 */
string Arbin::esHoja(int pValor) {
    if (getRaiz() == nullptr){
        return "\"Aún no se ha ingresado datos al árbol\\n";
    } else {
        Nodo *nodo = buscarNodo(pValor);
        if (nodo == nullptr){
            return "El valor ingresado no se encuentra en el árbol\n";
        } else if (nodo->getDer() == nullptr && nodo->getIzq() == nullptr){
            return "El valor ingresado es hoja\n";
        } else {
            return "El valor ingresado no hoja\n";
        }
    }
}
/**
 * Método:              buscarNodo
 * Descripción:         Método que permite mostrar (retornar) el nodo en el cual
 * se ubica el valor recibido como parámetro, o un nodo nulo si es que no hay
 * ningún nodo que contenga este valor.
 * @param pValor
 * @return
 */
Nodo *Arbin::buscarNodo(int pValor) {
    Nodo *aux = getRaiz();
    do {
        if (aux->getNum() == pValor){
            break;
        } else if(aux->getNum() > pValor){
            aux = aux->getIzq();
        } else if (aux->getNum() < pValor){
            aux = aux->getDer();
        } else {
            aux = nullptr;
        }
    } while (aux != nullptr);
    return aux;
}
Nodo *Arbin::buscarNodoPrevio(int pValor) {
    Nodo *aux = getRaiz();
    Nodo *previo;
    if (aux->getNum() == pValor){
        return nullptr;
    } else {
        do {
            if (aux->getNum() == pValor){
                break;
            }
            previo = aux;
            if (aux->getNum() > pValor) {
                aux = aux->getIzq();
            } else if (aux->getNum() < pValor){
                aux = aux->getDer();
            } else {
                previo = nullptr;
            }
        } while (aux != nullptr);
        return previo;
    }
}
/**
 * Método:              nivel
 * Descripción:         Método que permite obtener el nivel del árbol a travéz
 * del método privado recursivo.
 * @return              variable de tipo int que representa el nivel del árbol.
 */
int Arbin::nivel() {
    return nivelRecursivo(getRaiz());
}
/**
 * Método:              nivelRecursivo
 * Descripción:         Método que permite recorrer el árbol de forma recursiva
 * para obtener el nivel del árbol.
 * @param nodo          varible de tipo Nodo que respresenta cada nivel.
 * @return              variable de tipo int que representa el nivel del árbol.
 */
int Arbin::nivelRecursivo(Nodo * nodo) {
    int a, b;
    if (nodo == nullptr){
        return -1;
    } else {
        a = nivelRecursivo(nodo->getIzq());
        b = nivelRecursivo(nodo->getDer());
        if (a > b){
            return a + 1;
        } else {
            return b + 1;
        }
    }
}
/**
 * Método:              altura
 * Descripción:         Método que permite establecer la altura el árbol
 * @return              variable de tipo int que representa la altura del árbol
 */
int Arbin::altura() {
    return nivel() + 1;
}
/**
 * Método:              numHojas
 * Descripción:         Método que permite establecer el número de hojas del árbol
 * @return              variable de tipo int que representa el número hojas del árbol
 */
int Arbin::numHojas() {
    return numHojasRecursivo(getRaiz());
}
/**
 * Método:              numHojasRecursivo
 * Descripción:         Método recursivo que permite establecer el número de hojas del
 * árbol.
 * @param nodo          varible de tipo nodo que representa la raíz del árbol
 * @return              variable de tipo int que representa el número hojas del árbol
 */
int Arbin::numHojasRecursivo(Nodo * nodo) {
    if (nodo == nullptr){
        return 0;
    } else {
        if (nodo->getDer() == nullptr && nodo->getIzq() == nullptr){
            return 1;
        } else {
            return numHojasRecursivo(nodo->getIzq()) + numHojasRecursivo(nodo->getDer());
        }
    }
}
/**
 * Método:              camino
 * Descripción:         Método que permite generar el camino del árbol entre dos de sus puntos
 * @param pValorInicial variable de tipo int que representa el valor del nodo inicial a partir
 * del cual se establecerá el camino.
 * @param pValorFinal   variable de tipo int que representa el valor del nodo final a partir
 * del cual se establecerá el camino.
 * @return              variable de tipo string que representa el camino del árbol.
 */
string Arbin::camino(int pValorInicial, int pValorFinal) {
    Nodo *inicial = buscarNodo(pValorInicial);
    Nodo *final = buscarNodo(pValorFinal);
    if (inicial == nullptr || final == nullptr){
        return "Al menos uno de los valores ingresados no existe en el árbol";
    } else if(pValorInicial == pValorFinal) {
        return "No hay camino entre los valores ingresados";
    }
    else {
        return caminoRecursivo(inicial, pValorFinal);
    }

}
/**
 * Método:              caminoRecursivo
 * Descripción:         Método recursivo que permite establecer el camino entre el valor
 * que contiene el nodo inicial y el valor final recibido como parámetro
 * @param nodo          varible de tipo nodo que representa al nodo que contiene el valor
 * inicial
 * @param pValorFinal   variable de tipo int que representa el valor final del camino.
 * @return              variable de tipo string que representa el camino del árbol.
 */
string Arbin::caminoRecursivo(Nodo *nodo, int pValorFinal) {
    string camino;
    if (getRaiz() == nullptr){
        camino = "El árbol está vacío";
    } else if (nodo == nullptr){
        return "";
    } else if (nodo->getNum() == pValorFinal){
        camino = to_string(nodo->getNum());
    }
    else {
        if (nodo->getNum() > pValorFinal){
            Nodo *aux = nodo->getIzq();
            camino = to_string(nodo->getNum()) + " - " + caminoRecursivo(aux, pValorFinal);
        } else if (nodo->getNum() < pValorFinal){
            Nodo *aux = nodo->getDer();
            camino = to_string(nodo->getNum()) + " - " + caminoRecursivo(aux, pValorFinal);
        }
    }
    return camino;
}







