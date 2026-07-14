#include <iostream>
#include "menuViajesListados.h"
using namespace std;


MenuViajesListados::MenuViajesListados():Menu("LISTADOS DE VIAJES", 2){}

void MenuViajesListados::mostrarOpciones(){

    cout << "1. Listar viajes" << endl;
    cout << "2. Listar viajes ordenados por fecha (Del mas reciente al mas viejo)" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuViajesListados::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.listarViajes();
            break;
        case 2:
            _manager.listarViajesOrdenadosPorFecha();
            break;
        case 0:
            cout << "Saliendo de listados de viajes..";
            break;
    }

}


