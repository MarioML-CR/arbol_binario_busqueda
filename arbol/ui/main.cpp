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
void agregarAArbin();
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
             "01 Agregar datos\n" <<
             "02 Trasladar datos\n" <<
             "03 Salir\n";
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
//            menuTrasladar();
            break;
        case 3:
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
        gestor.insertarElem(ingresarNum(msg));
    }
    cout << "Los valores ingresados a la COLA se cargaron satisfactoriamente\n";
}