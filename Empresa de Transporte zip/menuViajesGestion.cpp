#include <iostream>
#include "menuViajesGestion.h"
using namespace std;


MenuViajesGestion::MenuViajesGestion():Menu("GESTION DE VIAJES", 1){}

void MenuViajesGestion::mostrarOpciones(){

    cout << "1. Agregar viaje" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuViajesGestion::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.crearViaje();
            break;
        case 0:
            cout << "Saliendo de gestion de viajes..";
            break;
    }

}
