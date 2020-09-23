//
// Created by Mario Martinez on 22/09/20.
//

#ifndef ARBOL_BINARIO_BUSQUEDA_NODO_H
#define ARBOL_BINARIO_BUSQUEDA_NODO_H


class Nodo {
public:
    Nodo();

    Nodo(int num);

    virtual ~Nodo();

    int getNum() const;

    void setNum(int num);

    Nodo *getIzq() const;


    Nodo *getDer() const;

    void setIzq(Nodo *izq);

    void setDer(Nodo *der);

private:
    int num;
    Nodo *izq;
    Nodo *der;
};


#endif //ARBOL_BINARIO_BUSQUEDA_NODO_H
