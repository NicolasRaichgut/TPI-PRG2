#include <iostream>
#include "menuClientesConsultas.h"
using namespace std;


MenuClientesConsultas::MenuClientesConsultas():Menu("CONSULTAS DE CLIENTES", 2){}

void MenuClientesConsultas::mostrarOpciones(){

    cout << "1. Consultar cliente por dni" << endl;
    cout << "2. Consultar clientes por anio de nacimiento" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuClientesConsultas::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.consultarClientePorDni();
            break;
        case 2:
            _manager.consultarClientesPorAnioNacimiento();
            break;
        case 0:
            cout << "Saliendo de consultas de clientes..";
            break;
    }

}


