#include <iostream>
#include "menuClientesGestion.h"
using namespace std;


MenuClientesGestion::MenuClientesGestion():Menu("GESTION DE CLIENTES", 3){}

void MenuClientesGestion::mostrarOpciones(){

    cout << "1. Agregar cliente" << endl;
    cout << "2. Modificar cliente" << endl;
    cout << "3. Eliminar cliente" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuClientesGestion::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.crearCliente();
            break;
        case 2:
            _manager.modificarCliente();
            break;
        case 3:
            _manager.eliminarCliente();
            break;
        case 0:
            cout << "Saliendo de gestion de clientes..";
            break;
    }

}
