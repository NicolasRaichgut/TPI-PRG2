#include <iostream>
#include <cstring>
#include <cstdlib>
#include "menu.h"
#include "consola.h"
using namespace std;

Menu::Menu(const char* titulo, int cantidadOpciones) {

    strcpy(_titulo, titulo);
    _cantidadOpciones = cantidadOpciones;

}

void Menu::mostrarEncabezado(){

    cout << endl;
    cout << "===================================" << endl;
    cout << _titulo << endl;
    cout << "===================================" << endl;

}

int Menu::seleccionarOpcion(){

    int opcion;

    while(true) {

        cout << "SELECCION: ";
        cin >> opcion;

        if(opcion >= 0 && opcion <= _cantidadOpciones)
            return opcion;

        cout << "Opcion invalida." << endl;
    }

}

void Menu::run(){

    int opcion;
    do{

        system("cls");
        aplicarEstilo();
        mostrarEncabezado();
        mostrarOpciones();
        opcion = seleccionarOpcion();
        ejecutarOpcion(opcion);

    }while(opcion != 0);

}