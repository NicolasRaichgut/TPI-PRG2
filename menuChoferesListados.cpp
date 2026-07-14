#include <iostream>
#include "menuChoferesListados.h"
using namespace std;


MenuChoferesListados::MenuChoferesListados():Menu("LISTADOS DE CHOFERES", 3){}

void MenuChoferesListados::mostrarOpciones(){

    cout << "1. Listar choferes" << endl;
    cout << "2. Listar choferes ordenados por nombre (A-Z)" << endl;
    cout << "3. Listar choferes ordenados por fecha de nacimiento (Del mas joven al mas viejo)" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuChoferesListados::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.listarChoferes();
            break;
        case 2:
            _manager.listarChoferesOrdenadosPorNombre();
            break;
        case 3:
            _manager.listarChoferesOrdenadosPorFechaNacimiento();
            break;
        case 0:
            cout << "Saliendo de listados de choferes..";
            break;
    }

}


