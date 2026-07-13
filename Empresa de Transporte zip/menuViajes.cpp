#include <iostream>
#include "menuViajes.h"
using namespace std;

MenuViajes::MenuViajes():Menu("MENU VIAJES", 3){}

void MenuViajes::mostrarOpciones(){

    cout << "1. Gestionar viajes" << endl;
    cout << "2. Listados de viajes" << endl;
    cout << "3. Consultas de viajes" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuViajes::ejecutarOpcion(int opcion){

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
            cout << "Saliendo de menu viajes..";
            break;
    }

}

