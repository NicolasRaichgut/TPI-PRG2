#include <iostream>
#include "menuClientesListados.h"
using namespace std;


MenuClientesListados::MenuClientesListados():Menu("LISTADOS DE CLIENTES", 3){}

void MenuClientesListados::mostrarOpciones(){

    cout << "1. Listar clientes" << endl;
    cout << "2. Listar clientes ordenados por nombre (A-Z)" << endl;
    cout << "3. Listar clientes ordenados por fecha de nacimiento (Del mas joven al mas viejo)" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuClientesListados::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.listarClientes();
            break;
        case 2:
            _manager.listarClientesOrdenadosPorNombre();
            break;
        case 3:
            _manager.listarClientesOrdenadosPorFechaNacimiento();
            break;
        case 0:
            cout << "Saliendo de listados de clientes..";
            break;
    }
    
}


