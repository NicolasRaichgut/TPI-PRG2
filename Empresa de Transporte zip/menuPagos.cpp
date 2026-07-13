#include <iostream>
#include "menuPagos.h"
using namespace std;


MenuPagos::MenuPagos():Menu("MENU PAGOS", 3){}

void MenuPagos::mostrarOpciones(){

    cout << "1. Gestionar pagos" << endl;
    cout << "2. Listados de pagos" << endl;
    cout << "3. Consultas de pagos" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuPagos::ejecutarOpcion(int opcion){

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
            cout << "Saliendo de menu pagos..";
            break;
    }

}

