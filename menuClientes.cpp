#include <iostream>
#include "menuClientes.h"
#include <cstdio>
using namespace std;


MenuClientes::MenuClientes():Menu("MENU CLIENTES", 3){}


void MenuClientes::mostrarOpciones(){

    cout << "1. Gestionar clientes" << endl;
    cout << "2. Listados de clientes" << endl;
    cout << "3. Consultas de clientes" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuClientes::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _menuGestion.run();
            break;
        case 2:
            _menuListados.run();
            break;
        case 3:
            _menuConsultas.run();
            break;
        case 0:
            cout << "Saliendo de menu clientes..";
            break;
    }

}
