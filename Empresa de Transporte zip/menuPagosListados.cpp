#include <iostream>
#include "menuPagosListados.h"
using namespace std;


MenuPagosListados::MenuPagosListados():Menu("LISTADOS DE PAGOS", 2){}

void MenuPagosListados::mostrarOpciones(){

    cout << "1. Listar pagos" << endl;
    cout << "2. Listar pagos ordenados por monto (DE MENOS A MAS MONTO)" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuPagosListados::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.listarPagos();
            break;
        case 2:
            _manager.listarPagosOrdenadosPorMonto();
            break;
        case 0:
            cout << "Saliendo de listados de pagos..";
            break;
    }

}


