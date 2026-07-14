#include <iostream>
#include "menuInformes.h"
using namespace std;

MenuInformes::MenuInformes():Menu("INFORMES", 8){}

void MenuInformes::mostrarOpciones(){

    cout << "1. Cliente que mas gasto" << endl;
    cout << "2. Chofer que mas recaudo" << endl;
    cout << "3. Remis mas utilizado" << endl;
    cout << "4. Metodo de pago mas utilizado" << endl;
    cout << "5. Recaudacion total entre dos fechas" << endl;
    cout << "6. Promedio de calificacion por chofer" << endl;
    cout << "7. Top 5 choferes con mas viajes" << endl;
    cout << "8. Top 5 clientes con mas viajes" << endl;
    cout << "0. Volver" << endl;
    cout << "-------------------------" << endl;

}

void MenuInformes::ejecutarOpcion(int opcion){

    switch(opcion){
        case 1:
            _manager.informeClienteQueMasGasto();
            break;

        case 2:
            _manager.informeChoferQueMasRecaudo();
            break;

        case 3:
            _manager.informeRemisMasUtilizado();
            break;

        case 4:
            _manager.informeMetodoPagoMasUtilizado();
            break;

        case 5:
            _manager.informeRecaudacionTotalEntreFechas();
            break;

        case 6:
            _manager.informePromedioCalificacionPorChofer();
            break;

        case 7:
            _manager.informeTop5ChoferesConMasViajes();
            break;

        case 8:
            _manager.informeTop5ClientesConMasViajes();
            break;

        case 0:
            cout << "Saliendo de informes..";
            break;

    }
    
}

