#include <iostream>
#include "menuRemisesGestion.h"
using namespace std;


MenuRemisesGestion::MenuRemisesGestion():Menu("GESTION DE REMISES", 2){}

void MenuRemisesGestion::mostrarOpciones(){

    cout << "1. Agregar remis" << endl;
    cout << "2. Eliminar remis" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuRemisesGestion::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.crearRemis();
            break;
        case 2:
            _manager.eliminarRemis();
            break;
        case 0:
            cout << "Saliendo de gestion de remises..";
            break;
    }

}
