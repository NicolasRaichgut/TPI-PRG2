#include <iostream>
#include "menuChoferes.h"
using namespace std;


MenuChoferes::MenuChoferes():Menu("MENU CHOFERES", 3){}

void MenuChoferes::mostrarOpciones(){

    cout << "1. Gestionar choferes" << endl;
    cout << "2. Listados de choferes" << endl;
    cout << "3. Consultas de choferes" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuChoferes::ejecutarOpcion(int opcion){

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
            cout << "Saliendo de menu choferes..";
            break;
    }

}

