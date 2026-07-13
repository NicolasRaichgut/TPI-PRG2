#include <iostream>
#include "menuPagosConsultas.h"
using namespace std;


MenuPagosConsultas::MenuPagosConsultas():Menu("CONSULTAS DE PAGOS", 2){}

void MenuPagosConsultas::mostrarOpciones(){

    cout << "1. Consultar pago por id" << endl;
    cout << "2. Consultar pagos por metodo de pago" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuPagosConsultas::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.consultarPagoPorId();
            break;
        case 2:
            _manager.consultarPagosPorMetodoPago();
            break;
        case 0:
            cout << "Saliendo de consultas de pagos..";
            break;
    }

}


