#include <iostream>
#include "menuRemises.h"
using namespace std;


MenuRemises::MenuRemises():Menu("MENU REMISES", 3){}

void MenuRemises::mostrarOpciones(){

    cout << "1. Gestionar remises" << endl;
    cout << "2. Listados de remises" << endl;
    cout << "3. Consultas de remises" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuRemises::ejecutarOpcion(int opcion){

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
            cout << "Saliendo de menu remises..";
            break;
    }

}

