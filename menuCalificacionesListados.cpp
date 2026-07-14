#include <iostream>
#include "menuCalificacionesListados.h"
using namespace std;


MenuCalificacionesListados::MenuCalificacionesListados():Menu("LISTADOS DE CALIFICACIONES", 2){}

void MenuCalificacionesListados::mostrarOpciones(){

    cout << "1. Listar calificaciones" << endl;
    cout << "2. Listar calificaciones ordenadas por puntaje (DE MENOS A MAS PUNTAJE)" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuCalificacionesListados::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.listarCalificaciones();
            break;
        case 2:
            _manager.listarCalificacionesOrdenadasPorPuntaje();
            break;
        case 0:
            cout << "Saliendo de listados de calificaciones..";
            break;
    }

}


