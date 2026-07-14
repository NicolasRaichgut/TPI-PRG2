#include <iostream>
#include "menuCalificacionesConsultas.h"
using namespace std;


MenuCalificacionesConsultas::MenuCalificacionesConsultas():Menu("CONSULTAS DE CALIFICACIONES", 1){}

void MenuCalificacionesConsultas::mostrarOpciones(){

    cout << "1. Consultar calificacion por id" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuCalificacionesConsultas::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.consultarCalificacionPorId();
            break;
        case 0:
            cout << "Saliendo de consultas de calificaciones..";
            break;
    }

}


