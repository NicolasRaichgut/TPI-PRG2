#include <iostream>
#include "menuChoferesGestion.h"
using namespace std;


MenuChoferesGestion::MenuChoferesGestion():Menu("GESTION DE CHOFERES", 3){}

void MenuChoferesGestion::mostrarOpciones(){

    cout << "1. Agregar chofer" << endl;
    cout << "2. Modificar chofer" << endl;
    cout << "3. Eliminar chofer" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuChoferesGestion::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.crearChofer();
            break;
        case 2:
            _manager.modificarChofer();
            break;
        case 3:
            _manager.eliminarChofer();
            break;
        case 0:
            cout << "Saliendo de gestion de choferes..";
            break;
    }

}
