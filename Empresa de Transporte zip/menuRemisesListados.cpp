#include <iostream>
#include "menuRemisesListados.h"
using namespace std;


MenuRemisesListados::MenuRemisesListados():Menu("LISTADOS DE REMISES", 3){}

void MenuRemisesListados::mostrarOpciones(){

    cout << "1. Listar remises" << endl;
    cout << "2. Listar remises ordenados por fecha de lanzamiento (DEL MAS NUEVO AL MAS VIEJO)" << endl;
    cout << "3. Listar remises ordenados por capacidad de pasajeros (DE MENOS A MAS CAPACIDAD)" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuRemisesListados::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.listarRemises();
            break;
        case 2:
            _manager.listarRemisesOrdenadosPorFechaLanzamiento();
            break;
        case 3:
            _manager.listarRemisesOrdenadosPorCapacidad();
            break;
        case 0:
            cout << "Saliendo de listados de remises..";
            break;
    }

}


