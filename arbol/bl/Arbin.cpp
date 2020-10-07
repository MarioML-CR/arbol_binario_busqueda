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
 * Método:          existeElemento
 * Descripción:     Método que verifica si un elemento ya existe en el árbol
 * @param pValor    variable de tipo int que representa el elemento que se debe
 * buscar en el árbol.
 * @return          variable de tipo bool, si existe retorna true, false caso contrario
 */
bool Arbin::existeElemento(int pValor) {
    if (getPeso()==0){
        return false;
    } else {
        Nodo * aux = buscarNodo(getRaiz(), pValor);
        if (aux == nullptr){
            return false;
        } else {
            return true;
        }

    }
}
/**
 * Método:              insertarElemRecursivo
 * Descripción:         Método que permite hacer la inserción de un arbolA binario (ordenado)
 * @param nodo      representa el nodo raiz,
 * @param nodoPadre      representa el nodo hijo
 * @param pValor        representa el valor a insertar, variable de tipo int
 * @param tipo          representa el tipo de hijo, 1 es izquierdo y 2 es derecho.
 */
bool Arbin::insertarElemRecursivo(Nodo *nodo, Nodo *nodoPadre, int pValor, int tipo) {
    if (nodo == nullptr){
        nodo = new Nodo(pValor);
        if(getPeso()== 0){
            setRaiz(nodo);
        } else if (tipo == 1){
            nodoPadre->setIzq(nodo);
        } else if (tipo == 2) {
            nodoPadre->setDer(nodo);
        }
        setPeso(getPeso() + 1);
    } else if (pValor < nodo->getNum()){
        insertarElemRecursivo(nodo->getIzq(), nodo, pValor, 1);
    } else if (pValor > nodo->getNum()) {
        insertarElemRecursivo(nodo->getDer(), nodo, pValor, 2);
    }
    return true;
}
/**
 * Método:              insertarElem
 * Descripción:         Método que permite enviar a insertar el valor al árbol
 * @param pValor        representa el valor a ingresar al árbol
 * @return              varible de tipo bool (true) indicando que se cargó correctamente.
 */
bool Arbin::insertarElem(int pValor) {
    bool existe = existeElemento(pValor);
    if (!existe){
        return insertarElemRecursivo(getRaiz(), new Nodo(), pValor ,0);
    } else {
        return false;
    }

}
/**
 * Método:              buscarMaximo
 * Descripción:         Método que permite buscar el valor máximo en el árbol
 * @return              variable de tipo int que representa el valor máximo del árbol
 */
int Arbin::buscarMaximo() {
    Nodo *max = nodoMaximo(getRaiz());
    if (max == nullptr){
        return -99999;
    } else {
        return max->getNum();
    }
}

/**
 * Método:              nodoMaximo
 * Descripción:         Método recursivo que permite retornar el nodo que contiene el
 * valor máximo en el árbol
 * @param nodo          variable de tipo nodo que representa el nodo raíz
 * @return              variable de tipo int que representa el valor máximo del árbol
 */
Nodo * Arbin::nodoMaximo(Nodo * nodo) {
    if (nodo == nullptr){
        return nullptr;
    } else {
        if (nodo->getDer() != nullptr){
            return nodoMaximo(nodo->getDer());
        } else {
            return nodo;
        }
    }
}
/**
 * Método:              buscarMinimo
 * Descripción:         Método que permite buscar el valor mínimo en el árbol
 * @return              variable de tipo int que representa el valor mínimo del árbol
 */
int Arbin::buscarMinimo() {
    Nodo *min = nodoMinimo(getRaiz());
    if (min == nullptr){
        return -99999;
    } else {
        return min->getNum();
    }
}
/**
 * Método:              nodoMinimo
 * Descripción:         Método recursivo que permite retornar el nodo con el valor mínimo
 * correspondiente al nodo recibido por parámetro.
 * @param nodo          variable de tipo nodo que representa el nodo raíz
 * @return              variable de tipo int que representa el valor mínimo del árbol
 */
Nodo *Arbin::nodoMinimo(Nodo * nodo) {
    if (nodo == nullptr){
        return nullptr;
    } else {
        if (nodo->getIzq() != nullptr){
            return nodoMinimo(nodo->getIzq());
        } else {
            return nodo;
        }
    }
}
/**
 * Método:              buscarNodo
 * Descripción:         Método recursivo que permite retornar el nodo en el cual
 * se ubica el valor recibido como parámetro, o un nodo nulo si es que no hay
 * ningún nodo que contenga este valor.
 * @param pValor        variable de tipo int que representa el valor a buscar
 * @return              variable de tipo nodo que representa el nodo donde se ubica
 * el valor a buscar
 */
Nodo *Arbin::buscarNodo(Nodo * nodo, int pValor) {
    if (nodo == nullptr){
        return nullptr;
    } else {
        if (nodo->getNum() == pValor){
            return nodo;
        } else if (nodo->getNum() > pValor) {
            return buscarNodo(nodo->getIzq(), pValor);
        } else {
            return buscarNodo(nodo->getDer(), pValor);
        }
    }
}

/**
 * Método:              buscarNodoPadre
 * Descripción:         Método que permite mostrar (retornar) el nodo padre
 * del nodo en el cual se ubica el valor recibido como parámetro.
 * @param pValor        variable de tipo int que representa el valor a buscar
 * @return              variable de tipo nodo que representa el nodo padre del nodo
 * donde se ubica el valor a buscar
 */
Nodo *Arbin::buscarNodoPadre(int pValor) {
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
 * Método:              esHoja
 * Descripción:         Método que permite establecer si al valor ingresado
 * es hoja o no, si no existe en el arbolA o si no hay datos en el árbol.
 * @param pValor        valor que representa el valor a buscar en el árbol.
 * @return              variable de tipo string con el resultado de la búsqueda.
 */
bool Arbin::esHoja(int pValor) {
    if (getRaiz() == nullptr){
        return false;
    } else {
//        Nodo *nodo = buscarNodo(pValor);
        Nodo *nodo = buscarNodo(getRaiz(), pValor);
        if (nodo == nullptr){
            return false;
        } else if (nodo->getDer() == nullptr && nodo->getIzq() == nullptr){
            return true;
        } else {
            return false;
        }
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
    Nodo *inicial = buscarNodo(getRaiz(), pValorInicial);
    Nodo *final = buscarNodo(getRaiz(), pValorFinal);
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
/**
 * Método:              preOrden
 * Descripción:         Método recursivo que permite mostrar el recorrido
 * del árbol en pre-orden.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string Arbin::preOrden() {
    return preOrdenRecursivo(getRaiz());
}
/**
 * Método:              preOrdenRecursivo
 * Descripción:         Método recursivo (privado) que permite recorrer el
 * árbol siguiendo el esquema: se recorre la raíz, en pre-orden el subárbol
 * izquierdo, y en preorden el subárbol derecho.
 * @param nodo          varible de tipo nodo que representa la raíz
 * del árbol.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string Arbin::preOrdenRecursivo(Nodo *nodo) {
    string preorden;
    if (nodo != nullptr){
        preorden = to_string(nodo->getNum()) + " - ";
        preorden += preOrdenRecursivo(nodo->getIzq());
        preorden += preOrdenRecursivo(nodo->getDer());
    }
    return preorden;
}
/**
 * Método:              inOrden
 * Descripción:         Método recursivo que permite mostrar el recorrido
 * del árbol in-orden.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string Arbin::inOrden() {
    return inOrdenRecursivo(getRaiz());
}
/**
 * Método:              inOrdenRecursivo
 * Descripción:         Método recursivo (privado) que permite recorrer el
 * árbol siguiendo la secuencia se recorre en in-orden el subárbol izquierdo,
 * se recorre la raíz, y se recore en in-orden el subárbol derecho.
 * @param nodo          varible de tipo nodo que representa la raíz
 * del árbol.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string Arbin::inOrdenRecursivo(Nodo *nodo) {
    string inOrden;
    if (nodo != nullptr){
        inOrden = inOrdenRecursivo(nodo->getIzq());
        inOrden += to_string(nodo->getNum()) + " - ";
        inOrden += inOrdenRecursivo(nodo->getDer());
    }
    return inOrden;
}
/**
 * Método:              postOrden
 * Descripción:         Método que permite mostrar el recorrido del
 * árbol en post-orden (izquierda - derecha - raíz)
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string Arbin::postOrden() {
    return postOrdenRecursivo(getRaiz());
}
/**
 * Método:              postOrdenRecursivo
 * Descripción:         Método recursivo (privado) que permite recorrer el árbol
 * siguiendo la secuencia recorre en post-orden el subárbol izquierdo,
 * se recorre en post-orden el subárbol derecha, se recorre la raíz.
 * @param nodo          varible de tipo nodo que representa la raíz
 * del árbol.
 * @return              variable de tipo string que represneta el recorrido
 * del árbol
 */
string Arbin::postOrdenRecursivo(Nodo *nodo) {
    string postOrden;
    if (nodo != nullptr){
        postOrden = postOrdenRecursivo(nodo->getIzq());
        postOrden += postOrdenRecursivo(nodo->getDer());
        postOrden += to_string(nodo->getNum()) + " - ";
    }
    return postOrden;
}
/**
 * Método:              eliminarElem
 * Descripción:         Método que permite eliminar un elemento del árbol
 * @param pValor        variable de tipo int que representa el valor a eliminar
 * @param tipo          variable de tipo int que representa la forma de eliminar en caso
 * que el nodo a eliminar tenga dos hijos; si es 0 elimina por la izquierda, y si es 1
 * elimina por la derecha.
 * @return              variable de tipo bool (true si lo eliminó, falso caso contrario)
 */
bool Arbin::eliminarElem(int pValor, int tipo) {
    Nodo * b = buscarNodo(getRaiz(), pValor);; // nodo del elemento a eliminar
    if (b == nullptr){
        return false;
    } else {
        Nodo * a = buscarNodoPadre(pValor); // nodo padre del elemento a eliminar
        Nodo * c = b->getIzq(); // nodo izquierdo del elemento a eliminar
        Nodo * d = b->getDer(); // nodo derecho del elemento a eliminar
        if (b->getIzq() != nullptr & b->getDer() != nullptr){ // tiene dos hojas
            if (tipo == 0){ // elimina por la izquierda
                eliminarNodoPorIzq(a,b,c,d);
            } else { // elimina por la derecha
                eliminarNodoPorDer(a,b,c,d);
            }
        } else if (b->getIzq() != nullptr & b->getDer() == nullptr ||
                   b->getIzq() == nullptr & b->getDer() != nullptr){ // tiene una hoja, izquierda o derecha caso 4 y 5
            if (b == getRaiz()){
                setRaiz(c);
            } else {
                if (a->getIzq() == b){
                    a->setIzq(d);
                } else {
                    a->setDer(c);
                }
            }
        } else { // es hoja caso 6
            if (b == getRaiz()){ // es raíz
                setRaiz(nullptr);
            } else { // no es raíz
                if (a->getIzq() == b){ // el nodo a eliminar corresponde a la rama izquierda del padre a eliminar
                    a->setIzq(nullptr);
                } else { // el nodo a eliminar corresponde a la rama derecha del padre a eliminar
                    a->setDer(nullptr);
                }
            }
        }
        setPeso(getPeso() - 1);
        delete b;
        return true;
    }
}
/**
 * Método:              eliminarNodoPorDer
 * Descripción:         Método que permite eliminar un nodo que tiene dos hijos y la
 * eliminación es por la derecha.
 * @param a             variable de tipo Nodo que representa el nodo padre del elemento a eliminar
 * @param b             variable de tipo Nodo que representa el nodo a eliminar
 * @param c             variable de tipo Nodo que representa el nodo izquierdo del elemento a eliminar
 * @param d             variable de tipo Nodo que representa el nodo derecho del elemento a eliminar
 */
void Arbin::eliminarNodoPorDer(Nodo * a, Nodo * b, Nodo * c, Nodo * d) {
    Nodo * f = nodoMinimo(d); // nodo mínimo por la derecha
    Nodo * e = buscarNodoPadre(f->getNum()); // nodo padre del nodo mínimo
    Nodo * g = f->getDer(); // nodo derecho del nodo mínimo
    if (b == getRaiz()){
        setRaiz(f);
    } else {
        if (a->getIzq() == b){ // el nodo a eliminar corresponde a la rama izquierda del padre a eliminar
            a->setIzq(f);
        } else { // el nodo a eliminar corresponde a la rama derecha del padre a eliminar
            a->setDer(f);
        }
    }
    f->setIzq(c);
    if (b == e && d == f){ // caso 1
        f->setDer(g);
    } else { // caso 2
        f->setDer(d);
        e->setIzq(g);
    }
}
/**
 * Método:              eliminarNodoPorIzq
 * Descripción:         Método que permite eliminar un nodo que tiene dos hijos y la
 * eliminación es por la izquierda.
 * @param a             variable de tipo Nodo que representa el nodo padre del elemento a eliminar
 * @param b             variable de tipo Nodo que representa el nodo a eliminar
 * @param c             variable de tipo Nodo que representa el nodo izquierdo del elemento a eliminar
 * @param d             variable de tipo Nodo que representa el nodo derecho del elemento a eliminar
 */
void Arbin::eliminarNodoPorIzq(Nodo * a, Nodo * b, Nodo * c, Nodo * d) {
    Nodo * f = nodoMaximo(c); // nodo máximo por la izquierda
    Nodo * e = buscarNodoPadre(f->getNum()); // nodo padre del nodo máximo
    Nodo * g = f->getIzq(); // nodo izquierdo del nodo máximo
    if (b == getRaiz()){
        setRaiz(f);
    } else {
        if (a->getIzq() == b){ // el nodo a eliminar corresponde a la rama izquierda del padre a eliminar
            a->setIzq(f);
        } else { // el nodo a eliminar corresponde a la rama derecha del padre a eliminar
            a->setDer(f);
        }
    }
    f->setDer(d);
    if (b == e && c == f){ // caso 1
        f->setIzq(g);
    }
    else { // caso 2 y caso 3
        f->setIzq(c);
        e->setDer(g);
    }
}
/**
 * Método:              esLleno
 * Descripción:         Método que permite verificar si un árbol está lleno; es decir, que
 * todos los nodos tienen dos hijos o ninguno, y sus hojas están al mismo nivel. El árbol
 * lleno necesariamente debe estar completo.
 * @return              variable de tipo bool (true si está lleno, falso caso contrario)
 */
bool Arbin::esLleno() {
    int hojas = numHojasRecursivo(getRaiz());
    int nivel = nivelRecursivo(getRaiz());
    if (pow(2, nivel) == hojas){
        return true;
    } else {
        return false;
    }
}
/**
 * Método:              esCompleto
 * Descripción:         Método que permite verificar si un árbol está completo; lo que
 * se alcanza si y solo si no existe un nodo con solo un hijo. Un árbol completo puede
 * estar lleno, pero un árbol compleno no implica que debe estar lleno.
 * @return              variable de tipo bool (true si es completo, falso caso contrario)
 */
bool Arbin::esCompleto() {
    int completo = esCompletoRecursivo(getRaiz());
    if (completo > 0){
        return false;
    } else {
        return true;
    }
}
/**
 * Método:              esCompletoRecursivo
 * Descripción:         Método recursivo que cuenta el número de nodos que tienen un solo
 * hijo.
 * @param nodo          variable de tipo Nodo que representa al árbol que se va a analizar
 * @return              variable de tipo int que representa el número de nodos que tienen
 * un sólo hijo
 */
int Arbin::esCompletoRecursivo(Nodo * nodo) {
    if (nodo == nullptr){
        return 0;
    } else {
        if (nodo->getDer() != nullptr && nodo->getIzq() == nullptr ||
                nodo->getDer() == nullptr && nodo->getIzq() != nullptr){
            return 1;
        } else {
            return esCompletoRecursivo(nodo->getIzq()) + esCompletoRecursivo(nodo->getDer());
        }
    }
}


bool Arbin::sonArbolesIguales(Nodo * nodo) {
    string arbolAInOrden = inOrdenRecursivo(getRaiz());
    string arbolBInOrden = inOrdenRecursivo(nodo);
    string arbolAInPreorden = preOrdenRecursivo(getRaiz());
    string arbolBInPreorden = preOrdenRecursivo(nodo);
    string arbolAInPosOrden = postOrdenRecursivo(getRaiz());
    string arbolBInPostOrden = postOrdenRecursivo(nodo);
    int inOrden = arbolAInOrden.compare(arbolBInOrden);
    int preOrden = arbolAInPreorden.compare(arbolBInPreorden);
    int postOrden = arbolAInPosOrden.compare(arbolBInPostOrden);
    if (inOrden == 0 && preOrden == 0 && postOrden == 0){
        return true;
    } else {
        return false;
    }
}

bool Arbin::sonArbolesSemejantes(Nodo * nodo) {
    string arbolAInOrden = inOrdenRecursivo(getRaiz());
    string arbolBInOrden = inOrdenRecursivo(nodo);
    int inOrden = arbolAInOrden.compare(arbolBInOrden);
    if (inOrden == 0){
        return true;
    } else {
        return false;
    }
}

bool Arbin::sonArbolesIsomorfos(Nodo * nodo) {
    int isomorfo = sonArbolesIsomorfosRecursivo(getRaiz(), nodo);
    if (isomorfo == 0){
        return true;
    } else {
        return false;
    }
}

int Arbin::sonArbolesIsomorfosRecursivo(Nodo * nodoA, Nodo * nodoB) {
    if (nodoA == nullptr || nodoB == nullptr){
        return 0;
    } else {
        if (nodoA->getDer() != nodoB->getDer() ||
            nodoA->getIzq() != nodoB->getIzq()) {
            return 1;
        } else {
            return sonArbolesIsomorfosRecursivo(nodoA->getIzq(), nodoB->getIzq()) +
                   sonArbolesIsomorfosRecursivo(nodoA->getDer(), nodoB->getDer());
        }
    }
}























