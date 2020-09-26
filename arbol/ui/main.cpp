#include <iostream>
#include "../tl/Gestor.h"
#include "../utilitario/Validar.h"

/**
 * Nombre del programa: Árbol binario de búsquda
 * Descripción: Programa que contiene la estructura básica de un árbol binario,
 * que recibe números enteros y permite mostrarlos en preorden (RID: raíz -
 * izquierda - derecha), in-orden (IRD: izquierda - raíz - derecha) y en post-orden
 * (IDR: izquierda - derecha - raíz)
 * Fecha de creación: 2020-09-22
 * Autores:
 *      Francisco Sandoval Cordero
 *      Juan Hidalgo González
 *      Mario Martínez Lanuza
 * Modificación: 2020-09-23
 */

using namespace std;
void menu();
void procesarMenu(int &, bool &);
int ingresarNum(string);
void esVacioArbin();
void pesoArbin();
void agregarAArbin();
void buscarMaximo();
void buscarMinimo();
void esHoja();
void nivel();
void altura();
void numHojas();
Gestor gestor;
Validar validar;

int main() {
    menu();
    return 0;
}
void menu() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú principal\n\nElija una opción\n" <<
             "01 Agregar datos al árbol\n" <<
             "02 Verificar si el árbol tiene elementos\n" <<
             "03 Peso del árbol\n" <<
             "04 Número menor del árbol\n" <<
             "05 Número mayor del árbol\n" <<
             "06 Verificar si valor es hoja\n" <<
             "07 Nivel del arbol\n" <<
             "08 Altura del árbol\n" <<
             "09 Número de hojas del árbol\n" <<
             "12 Salir\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenu(opcion, salir);
    } while (!salir);
}
void procesarMenu(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            agregarAArbin();
            break;
        case 2:
            esVacioArbin();
            break;
        case 3:
            pesoArbin();
            break;
        case 4:
            buscarMinimo();
            break;
        case 5:
            buscarMaximo();
            break;
        case 6:
            esHoja();
            break;
        case 7:
            nivel();
            break;
        case 8:
            altura();
            break;
        case 9:
            numHojas();
            break;
        case 12:
            salir = true;
            break;
        default:
            cout << "Opción inválida\n";
    }
}
int ingresarNum(string msg){
    int num;
    string valor;
    do {
        cout << msg << endl;
        cin >> valor;
        num = validar.ingresarInt(valor);
        if (num == -1){
            cout << "El valor ingresado es incorrecto\nVuelva a intentarlo\n";
        }
    } while (num == -1);
    return num;
}
void agregarAArbin() {
    string msg = "Ingrese la cantidad de números que desea cargar al árbol\n";
    int ciclos = ingresarNum(msg);
    for (int i = 0; i < ciclos; ++i) {
        msg = "ingrese el valor " + to_string(i + 1);
        bool carga = gestor.insertarElem(ingresarNum(msg));
        if (carga) {
            cout << "El valor ingresado se cargó correctamente\n";
        } else {
            cout << "Se produjo un error en la carga...\n";
        }
    }
    cout << "Los valores ingresados en el arbol binario se cargaron satisfactoriamente\n";
}
void esVacioArbin(){
    if (gestor.esVacioArbin()) {
        cout << "El árbol está vacío\n";
    } else {
        cout << "El árbol tiene elementos\n";
    }
}
void pesoArbin(){
    cout << "El peso del árbol es " << gestor.pesoArbin() << endl;
}
void buscarMinimo(){
    if (!gestor.esVacioArbin()) {
        cout << "El valor mínimo del árbol es " << gestor.buscarMinimo() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol\n";
    }
}
void buscarMaximo(){
    if (!gestor.esVacioArbin()) {
        cout << "El valor máximo del árbol es " << gestor.buscarMaximo() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol\n";
    }
}
void esHoja(){
    string msg = "ingrese el valor\n";
    string esHoja = gestor.esHoja(ingresarNum(msg));
    if (!gestor.esVacioArbin()) {
        cout << esHoja;
    } else {
        cout << "Aún no se ha ingresado datos al árbol\n";
    }
}
void nivel(){
    if (!gestor.esVacioArbin()) {
        cout << "El nivel del árboles es " << gestor.nivel() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol\n";
    }
}
void altura(){
    if (!gestor.esVacioArbin()) {
        cout << "La altura del árboles es " << gestor.altura() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol\n";
    }
}
void numHojas(){
    if (!gestor.esVacioArbin()) {
        cout << "El número de hojas del árbol es " << gestor.numHojas() << endl;
    } else {
        cout << "Aún no se ha ingresado datos al árbol\n";
    }
}