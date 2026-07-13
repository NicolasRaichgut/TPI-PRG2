#include <iostream>
#include "menuPagosGestion.h"
using namespace std;


MenuPagosGestion::MenuPagosGestion():Menu("GESTION DE PAGOS", 1){}

void MenuPagosGestion::mostrarOpciones(){

    cout << "1. Agregar pago" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuPagosGestion::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.crearPago();
            break;
        case 0:
            cout << "Saliendo de gestion de pagos..";
            break;
    }

}
