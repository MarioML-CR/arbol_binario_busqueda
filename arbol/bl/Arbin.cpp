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
    return insertarElemRecursivo(getRaiz(), new Nodo(), pValor ,0);
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
//Nodo *Arbin::buscarNodoPadre(Nodo * nodo) {
//    Nodo *aux = getRaiz();
//    Nodo *previo;
//    if (aux->getNum() == nodo->getNum()){
//        return nullptr;
//    } else {
//        if (aux->getDer() == nodo){
//            return aux->getDer();
//        } else if (aux->getIzq() == nodo){
//            return aux->getIzq();
//        } else {
//
//        }
//    }
//    return nullptr;
//}
/**
 * Método:              esHoja
 * Descripción:         Método que permite establecer si al valor ingresado
 * es hoja o no, si no existe en el arbol o si no hay datos en el árbol.
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
 * @return              variable de tipo bool (true si lo eliminó, falso caso contrario)
 */
bool Arbin::eliminarElem(int pValor) {
    if (esHoja(getRaiz()->getNum())){
        setPeso(0); // TODO: Eliminar
        setRaiz(nullptr);
        return true;
    } else {
        Nodo *nodoEliminar = buscarNodo(getRaiz(), pValor);
        Nodo *nodoPadreDeEliminar = buscarNodoPadre(pValor);;
        Nodo *nodoSustituir;
        if (nodoEliminar->getDer() != nullptr){
            nodoSustituir = nodoMinimo(nodoEliminar->getDer());
        } else {
            nodoSustituir = nodoMaximo(nodoEliminar->getIzq());
        }
        Nodo *nodoPadreSustituir = buscarNodoPadre(nodoSustituir->getNum());
        if (nodoEliminar == getRaiz()){
            if (esHoja(nodoSustituir->getNum())){
                getRaiz()->setNum(nodoSustituir->getNum());
                if (nodoPadreSustituir->getDer() == nodoSustituir){
                    nodoPadreSustituir->setDer(nullptr);
                } else {
                    nodoPadreSustituir->setIzq(nullptr);
                }
            } else {
                getRaiz()->setNum(nodoSustituir->getNum());
                if (getRaiz()->getDer() != nullptr){
                    getRaiz()->setDer(nodoSustituir->getDer());
                } else {
                    getRaiz()->setIzq(nodoSustituir->getDer());
                }
            }
            setPeso(getPeso() - 1);
            delete nodoEliminar;
            return true;
        } else if (esHoja(nodoEliminar->getNum())) { // es hoja
            if (nodoPadreDeEliminar->getDer()->getNum() == nodoEliminar->getNum()){
                nodoPadreDeEliminar->setDer(nullptr);
            } else if (nodoPadreDeEliminar->getIzq()->getNum() == nodoEliminar->getNum()){
                nodoPadreDeEliminar->setIzq(nullptr);
            }
            setPeso(getPeso() - 1);
            delete nodoEliminar;
            return true;
        } else if (esHoja(nodoSustituir->getNum())){
            if (nodoPadreDeEliminar->getIzq() == nodoEliminar){
                nodoPadreSustituir->setIzq(nullptr);
            } else {
                nodoPadreSustituir->setDer(nullptr);
            }
            nodoPadreDeEliminar->setNum(nodoSustituir->getNum());
            setPeso(getPeso() - 1);
            delete nodoEliminar;
            return true;
        } else {
            if(nodoPadreDeEliminar->getDer() == nodoEliminar){
                nodoPadreDeEliminar->getDer()->setNum(nodoSustituir->getNum());
            } else {
                nodoPadreDeEliminar->getIzq()->setNum(nodoSustituir->getNum());
            }
            nodoPadreSustituir->getIzq()->setNum(nodoSustituir->getDer()->getNum());
            nodoSustituir->setDer(nullptr);
            setPeso(getPeso() - 1);
//            delete nodoEliminar;
            return true;
        }
    }

//    Nodo *sustituir =
//    return eliminarNodoXDer(buscarNodo(getRaiz(), pValor));
}
bool Arbin::eliminarNodoXDer(Nodo * nodo) {
    Nodo *nodoPadreElim;
    if (nodo == getRaiz() && esHoja(nodo->getNum())){ // Solo hay un elemento en el árbol
        setPeso(0); // TODO: Eliminar
        setRaiz(nullptr);
        delete nodo;
        return true;
    } else if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr){ // hay varios elementos y el elemento a elimnar es hoja
//        nodoPadreElim = buscarNodoPadre(nodo->getNum());
        setPeso(getPeso() - 1);
        delete nodo;
//        if (nodoPadreElim->getIzq() == nodo){
//            nodoPadreElim->setIzq(nullptr);
//            delete nodo;
//        } else if (nodoPadreElim->getDer() == nodo){
//            nodoPadreElim->setDer(nullptr);
//            delete nodo;
//        }

        return true;
    } else { // hay varios elementos y el elemento a eliminar no es hoja ** Método por derecha
        if(nodo->getIzq() != nullptr && nodo->getDer() == nullptr) { // el elemento a eliminar tiene un hijo izq
            Nodo *padre = buscarNodoPadre(nodo->getNum());
//            nodoPadreElim->setIzq(nodo->getIzq());
            Nodo *mayor = nodoMaximo(nodo->getIzq());
            nodoPadreElim = buscarNodoPadre(mayor->getNum());
            padre->setIzq(nodo->getIzq());
            nodo->setNum(mayor->getNum());
//            mayor->setNum(-99999);
            eliminarNodoXDer(mayor);
        } else { // el elemento a eliminar tiene dos hijos
            Nodo *menor = nodoMinimo(nodo->getDer());
            nodoPadreElim = buscarNodoPadre(menor->getNum());
            nodo->setNum(menor->getNum());
//            menor->setNum(-99999);
            eliminarNodoXDer(menor);
        }
//        setPeso(getPeso() - 1);
//        delete nodo;
//        return true;
    }
}

bool Arbin::eliminarIzq(Nodo *nodo, int pValor) {
//    Nodo *nodoEliminar = buscarNodo(pValor);
//    if (nodoEliminar != nullptr){
//        Nodo *nodoPadreElim = buscarNodoPadre(pValor);
//        if (nodoEliminar == getRaiz() && esHoja(pValor)){ // Solo hay un elemento en el árbol
//            setPeso(0); // TODO: Eliminar
//            setRaiz(nullptr);
//            delete nodoEliminar;
//            return true;
//        } else if (esHoja(pValor)){ // hay varios elementos y el elemento a elimnar es hoja
//            if (nodoPadreElim->getIzq() == nodoEliminar){
//                nodoPadreElim->setIzq(nullptr);
//                delete nodoEliminar;
//            } else if (nodoPadreElim->getDer() == nodoEliminar){
//                nodoPadreElim->setDer(nullptr);
//                delete nodoEliminar;
//            }
//            setPeso(getPeso() - 1);
//            return true;
//        } else { // hay varios elementos y el elemento a eliminar no es hoja
//            if(nodoEliminar->getIzq() != nullptr && nodoEliminar->getDer() == nullptr) { // el elemento a eliminar tiene un hijo izq
//                nodoPadreElim->setIzq(nodoEliminar->getIzq());
//            } else if (nodoEliminar->getIzq() == nullptr && nodoEliminar->getDer() != nullptr) { // el elemento a eliminar tiene un hijo derecho
//                nodoPadreElim->setDer(nodoEliminar->getDer());
//            } else { // el elemento a eliminar tiene dos hijos
////                int valorASustituir = nodoMaximo(nodoEliminar);
//                nodoEliminar->setNum(valorASustituir);
//                Nodo *nodoSustituir = buscarNodo(valorASustituir);
//                if (nodoSustituir)
//
//                    Nodo *nodoPadreSust = buscarNodoPadre(valorASustituir);
//            }
//            setPeso(getPeso() - 1);
//            delete nodoEliminar;
            return true;
//        }
//    }
}
Nodo *Arbin::unirArbin(Nodo *nodoIzq, Nodo *nodoDer) {
    if (nodoIzq == nullptr) {
        return nodoDer;
    }
    if (nodoDer == nullptr){
        return nodoIzq;
    }
    Nodo *aux = unirArbin(nodoIzq->getDer(), nodoDer->getIzq());
    Nodo *tmp1 = nodoIzq->getDer();
    tmp1 = aux;
    Nodo *tmp2 = nodoDer->getIzq();
    tmp2 = nodoIzq;
    return nodoDer;
}























