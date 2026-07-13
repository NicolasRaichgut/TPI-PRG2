#include <iostream>
#include "menuCalificaciones.h"
using namespace std;


MenuCalificaciones::MenuCalificaciones():Menu("MENU CALIFICACIONES", 3){}

void MenuCalificaciones::mostrarOpciones(){

    cout << "1. Gestionar calificaciones" << endl;
    cout << "2. Listados de calificaciones" << endl;
    cout << "3. Consultas de calificaciones" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuCalificaciones::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _menuGestion.run();
            break;
        case 2:
            _menuListados.run();
            break;
        case 3:
            _menuConsultas.run();
            break;
        case 0:
            cout << "Saliendo de menu calificaciones..";
            break;
    }

}

