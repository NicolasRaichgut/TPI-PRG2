#include <iostream>
#include "menuChoferesConsultas.h"
using namespace std;


MenuChoferesConsultas::MenuChoferesConsultas():Menu("CONSULTAS DE CHOFERES", 2){}

void MenuChoferesConsultas::mostrarOpciones(){

    cout << "1. Consultar chofer por dni" << endl;
    cout << "2. Consultar choferes por anio de nacimiento" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuChoferesConsultas::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.consultarChoferPorDni();
            break;
        case 2:
            _manager.consultarChoferesPorAnioNacimiento();
            break;
        case 0:
            cout << "Saliendo de consultas de choferes..";
            break;
    }

}


