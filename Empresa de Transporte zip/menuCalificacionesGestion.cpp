#include <iostream>
#include "menuCalificacionesGestion.h"
using namespace std;


MenuCalificacionesGestion::MenuCalificacionesGestion():Menu("GESTION DE CALIFICACIONES", 1){}

void MenuCalificacionesGestion::mostrarOpciones(){

    cout << "1. Agregar calificacion" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuCalificacionesGestion::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.crearCalificacion();
            break;
        case 0:
            cout << "Saliendo de gestion de calificaciones..";
            break;
    }

}
