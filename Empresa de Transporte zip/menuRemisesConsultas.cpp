#include <iostream>
#include "menuRemisesConsultas.h"
using namespace std;


MenuRemisesConsultas::MenuRemisesConsultas():Menu("CONSULTAS DE REMISES", 2){}

void MenuRemisesConsultas::mostrarOpciones(){

    cout << "1. Consultar remis por patente" << endl;
    cout << "2. Consultar remis de un chofer" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuRemisesConsultas::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.consultarRemisPorPatente();
            break;
        case 2:
            _manager.consultarRemisPorDniChofer();
            break;
        case 0:
            cout << "Saliendo de consultas de remises..";
            break;
    }

}


