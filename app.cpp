#include <iostream>
#include "app.h"
using namespace std;


App::App():Menu("SISTEMA DE LA EMPRESA DE TRANSPORTE", 7){}

void App::mostrarOpciones(){

    cout << "1. CLIENTES" << endl;
    cout << "2. CHOFERES" << endl;
    cout << "3. VIAJES" << endl;
    cout << "4. REMISES" << endl;
    cout << "5. PAGOS" << endl;
    cout << "6. CALIFICACIONES" << endl;
    cout << "7. INFORMES" << endl;
    cout << "0. Salir" << endl;
    cout << "-------------------------" << endl;

}

void App::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _menuClientes.run();
            break;
        case 2:
            _menuChoferes.run();
            break;
        case 3:
            _menuViajes.run();
            break;
        case 4:
            _menuRemises.run();
            break;
        case 5:
            _menuPagos.run();
            break;
        case 6:
            _menuCalificaciones.run();
            break;
        case 7:
            _menuInformes.run();
            break;
        case 0:
            cout << "Saliendo del sistema..";
            break;
    }

}


