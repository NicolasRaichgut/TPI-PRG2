#include <iostream>
#include "menuViajesConsultas.h"
using namespace std;


MenuViajesConsultas::MenuViajesConsultas():Menu("CONSULTAS DE VIAJES", 4){}

void MenuViajesConsultas::mostrarOpciones(){

    cout << "1. Consultar viaje por id" << endl;
    cout << "2. Consultar viajes por dni de cliente" << endl;
    cout << "3. Consultar viajes por dni de chofer" << endl;
    cout << "4. Consultar viajes por mes y anio" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuViajesConsultas::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.consultarViajePorId();
            break;
        case 2:
            _manager.consultarViajesPorDniCliente();
            break;
        case 3:
            _manager.consultarViajesPorDniChofer();
            break;
        case 4:
            _manager.consultarViajesPorMesAnio();
            break;
        case 0:
            cout << "Saliendo de consultas de viajes..";
            break;
    }

}


