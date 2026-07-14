#include <iostream>
#include <cstring>
#include <cstdio>
#include "informesManager.h"
#include "consola.h"
using namespace std;


bool InformesManager::buscarClientePorDni(const char* dni, Clientes& cliente){

    int cantidad = _repoClientes.contarRegistros();

    for(int x = 0; x < cantidad; x++){
        cliente = _repoClientes.leer(x);
        if(!cliente.getEliminado() && strcmp(cliente.getDni(), dni) == 0)
            return true;
    }
    return false;

}

bool InformesManager::buscarChoferPorDni(const char* dni, Choferes& chofer){

    int cantidad = _repoChoferes.contarRegistros();

    for(int x = 0; x < cantidad; x++){
        chofer = _repoChoferes.leer(x);
        if(!chofer.getEliminado() && strcmp(chofer.getDni(), dni) == 0)
            return true;
    }
    return false;

}

bool InformesManager::buscarViajeActivoPorId(const char* id, Viajes& viaje){

    int cantidad = _repoViajes.contarRegistros();

    for(int x = 0; x < cantidad; x++){
        viaje = _repoViajes.leer(x);
        if(!viaje.getEliminado() && strcmp(viaje.getId(), id) == 0)
            return true;
    }
    return false;

}

int InformesManager::fechaAEntero(Fecha fecha){
    return fecha.getAnio() * 10000 + fecha.getMes() * 100 + fecha.getDia();
}

bool InformesManager::fechaEnRango(Fecha fecha, Fecha desde, Fecha hasta){

    int f = fechaAEntero(fecha);
    int d = fechaAEntero(desde);
    int h = fechaAEntero(hasta);
    return f >= d && f <= h;

}

const char* InformesManager::nombreMetodoPago(int metodo){

    switch(metodo){
        case 1:
            return "Efectivo";

        case 2:
            return "Tarjeta";

        case 3:
            return "Transferencia";

        default:
            return "Desconocido";
    }

}


// INFORMES
void InformesManager::informeClienteQueMasGasto(){

    Clientes cliente;
    Pagos pago;
    Viajes viaje;

    int cantidadPagos = _repoPagos.contarRegistros();
    int cantidadClientes = _repoClientes.contarRegistros();

    char dniMax[9];
    float montoMax = 0;
    int viajesMax = 0;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- INFORME: CLIENTE QUE MAS GASTO ----" << endl;

    for(int x = 0; x < cantidadClientes; x++){

        cliente = _repoClientes.leer(x);
        if(cliente.getEliminado())
            continue;

        float montoTotal = 0;
        int cantidadViajes = 0;

        for(int y = 0; y < cantidadPagos; y++){

            pago = _repoPagos.leer(y);
            if(pago.getEliminado())
                continue;

            if(!buscarViajeActivoPorId(pago.getIdViaje(), viaje))
                continue;

            if(strcmp(viaje.getDniCliente(), cliente.getDni()) != 0)
                continue;

            montoTotal += pago.getMonto();

        }

        for(int y = 0; y < _repoViajes.contarRegistros(); y++){

            viaje = _repoViajes.leer(y);
            if(!viaje.getEliminado() && strcmp(viaje.getDniCliente(), cliente.getDni()) == 0)
                cantidadViajes++;

        }

        if(montoTotal > montoMax){
            strcpy(dniMax, cliente.getDni());
            montoMax = montoTotal;
            viajesMax = cantidadViajes;
            encontro = true;
        }

    }

    if(!encontro){
        cout << "No hay datos de gastos registrados." << endl;
        system("pause");
        return;
    }

    if(buscarClientePorDni(dniMax, cliente)){

        cout << "Nombre: " << cliente.getNombre() << " " << cliente.getApellido() << endl;
        cout << "DNI: " << cliente.getDni() << endl;
        cout << "Total gastado: $" << montoMax << endl;
        cout << "Cantidad de viajes: " << viajesMax << endl;

    }

    system("pause");

}

void InformesManager::informeChoferQueMasRecaudo(){

    Choferes chofer;
    Pagos pago;
    Viajes viaje;

    int cantidadPagos = _repoPagos.contarRegistros();
    int cantidadChoferes = _repoChoferes.contarRegistros();

    char dniMax[9];
    float montoMax = 0;
    int viajesMax = 0;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- INFORME: CHOFER QUE MAS RECAUDO ----" << endl;

    for(int x = 0; x < cantidadChoferes; x++){

        chofer = _repoChoferes.leer(x);
        if(chofer.getEliminado())
            continue;

        float montoTotal = 0;
        int cantidadViajes = 0;

        for(int y = 0; y < cantidadPagos; y++){

            pago = _repoPagos.leer(y);
            if(pago.getEliminado())
                continue;

            if(!buscarViajeActivoPorId(pago.getIdViaje(), viaje))
                continue;

            if(strcmp(viaje.getDniChofer(), chofer.getDni()) != 0)
                continue;

            montoTotal += pago.getMonto();

        }

        for(int y = 0; y < _repoViajes.contarRegistros(); y++){

            viaje = _repoViajes.leer(y);
            if(!viaje.getEliminado() && strcmp(viaje.getDniChofer(), chofer.getDni()) == 0)
                cantidadViajes++;

        }

        if(montoTotal > montoMax){
            strcpy(dniMax, chofer.getDni());
            montoMax = montoTotal;
            viajesMax = cantidadViajes;
            encontro = true;
        }

    }

    if(!encontro){
        cout << "No hay datos de recaudacion registrados." << endl;
        system("pause");
        return;
    }

    if(buscarChoferPorDni(dniMax, chofer)){
        cout << "Nombre: " << chofer.getNombre() << " " << chofer.getApellido() << endl;
        cout << "DNI: " << chofer.getDni() << endl;
        cout << "Total recaudado: $" << montoMax << endl;
        cout << "Cantidad de viajes: " << viajesMax << endl;
    }
    system("pause");

}

void InformesManager::informeRemisMasUtilizado(){

    Remises remis;
    Viajes viaje;

    int cantidadRemises = _repoRemises.contarRegistros();
    int cantidadViajes = _repoViajes.contarRegistros();

    char patenteMax[10];
    int viajesMax = 0;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- INFORME: REMIS MAS UTILIZADO ----" << endl;

    for(int x = 0; x < cantidadRemises; x++){

        remis = _repoRemises.leer(x);
        if(remis.getEliminado())
            continue;

        int cantidad = 0;

        for(int y = 0; y < cantidadViajes; y++){

            viaje = _repoViajes.leer(y);
            if(!viaje.getEliminado() && strcmp(viaje.getDniChofer(), remis.getDniChofer()) == 0)
                cantidad++;

        }

        if(cantidad > viajesMax){
            strcpy(patenteMax, remis.getPatente());
            viajesMax = cantidad;
            encontro = true;
        }

    }

    if(!encontro){
        cout << "No hay datos de utilizacion de remises." << endl;
        system("pause");
        return;
    }

    for(int x = 0; x < cantidadRemises; x++){

        remis = _repoRemises.leer(x);
        if(!remis.getEliminado() && strcmp(remis.getPatente(), patenteMax) == 0){
            cout << "Patente: " << remis.getPatente() << endl;
            cout << "Marca: " << remis.getMarca() << endl;
            cout << "Modelo: " << remis.getModelo() << endl;
            cout << "DNI chofer: " << remis.getDniChofer() << endl;
            cout << "Cantidad de viajes: " << viajesMax << endl;
            break;
        }

    }
    system("pause");

}

void InformesManager::informeMetodoPagoMasUtilizado(){

    Pagos pago;
    int cantidad = _repoPagos.contarRegistros();

    int conteo[4] = {0, 0, 0, 0};
    int metodoMax = 0;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- INFORME: METODO DE PAGO MAS UTILIZADO ----" << endl;

    for(int x = 0; x < cantidad; x++){

        pago = _repoPagos.leer(x);
        if(!pago.getEliminado()){
            conteo[pago.getMetodoPago()]++;
            encontro = true;
        }

    }

    if(!encontro){
        cout << "No hay pagos registrados." << endl;
        system("pause");
        return;
    }

    for(int x = 1; x <= 3; x++){
        if(conteo[x] > conteo[metodoMax])
            metodoMax = x;
    }

    if(conteo[metodoMax] == 0){
        cout << "No hay pagos registrados." << endl;
        system("pause");
        return;
    }

    cout << "Metodo de pago: " << nombreMetodoPago(metodoMax) << endl;
    cout << "Cantidad de pagos: " << conteo[metodoMax] << endl;

    system("pause");

}

void InformesManager::informeRecaudacionTotalEntreFechas(){

    Pagos pago;
    int cantidad = _repoPagos.contarRegistros();

    int dia, mes, anio;
    Fecha fechaDesde, fechaHasta;
    float total = 0;
    int cantidadPagos = 0;

    limpiarPantalla();
    cout << "---- INFORME: RECAUDACION TOTAL ENTRE FECHAS ----" << endl;

    while(true){
        cout << "Ingrese fecha desde - dia (0 para cancelar): ";
        cin >> dia;

        if(dia == 0){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        cout << "Ingrese mes: ";
        cin >> mes;

        cout << "Ingrese anio: ";
        cin >> anio;

        fechaDesde = Fecha(dia, mes, anio);

        if(pago.setFechaPago(fechaDesde))
            break;

        cout << "Fecha invalida." << endl;
    }

    while(true){
        cout << "Ingrese fecha hasta - dia (0 para cancelar): ";
        cin >> dia;

        if(dia == 0){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }
        cout << "Ingrese mes: ";
        cin >> mes;
        cout << "Ingrese anio: ";
        cin >> anio;

        fechaHasta = Fecha(dia, mes, anio);
        if(pago.setFechaPago(fechaHasta))
            break;

        cout << "Fecha invalida." << endl;
    }

    if(fechaAEntero(fechaDesde) > fechaAEntero(fechaHasta)){
        cout << "La fecha desde no puede ser posterior a la fecha hasta." << endl;
        system("pause");
        return;
    }

    for(int x = 0; x < cantidad; x++){

        pago = _repoPagos.leer(x);
        if(pago.getEliminado())
            continue;

        if(fechaEnRango(pago.getFechaPago(), fechaDesde, fechaHasta)){
            total += pago.getMonto();
            cantidadPagos++;
        }

    }

    cout << "Periodo: ";
    fechaDesde.mostrar();
    cout << " - ";
    fechaHasta.mostrar();
    cout << endl;
    cout << "Cantidad de pagos: " << cantidadPagos << endl;
    cout << "Recaudacion total: $" << total << endl;

    if(cantidadPagos == 0)
        cout << "No hay pagos en el periodo indicado." << endl;

    system("pause");

}

void InformesManager::informePromedioCalificacionPorChofer(){

    Choferes chofer;
    Calificaciones calificacion;
    Viajes viaje;

    int cantidadChoferes = _repoChoferes.contarRegistros();
    int cantidadCalificaciones = _repoCalificaciones.contarRegistros();

    bool encontro = false;

    limpiarPantalla();
    cout << "---- INFORME: PROMEDIO DE CALIFICACION POR CHOFER ----" << endl;

    for(int x = 0; x < cantidadChoferes; x++){

        chofer = _repoChoferes.leer(x);
        if(chofer.getEliminado())
            continue;

        int sumaPuntajes = 0;
        int cantidad = 0;

        for(int y = 0; y < cantidadCalificaciones; y++){

            calificacion = _repoCalificaciones.leer(y);
            if(calificacion.getEliminado())
                continue;

            if(!buscarViajeActivoPorId(calificacion.getIdViaje(), viaje))
                continue;

            if(strcmp(viaje.getDniChofer(), chofer.getDni()) != 0)
                continue;

            sumaPuntajes += calificacion.getPuntaje();
            cantidad++;

        }

        if(cantidad > 0){
            if(encontro)
                cout << "-----------------------------" << endl;

            cout << chofer.getNombre() << " " << chofer.getApellido() << endl;
            cout << "DNI: " << chofer.getDni() << endl;
            cout << "Promedio: " << (float)sumaPuntajes / cantidad << endl;
            cout << "Calificaciones recibidas: " << cantidad << endl;
            encontro = true;
        }

    }

    if(!encontro)
        cout << "No hay calificaciones registradas para choferes." << endl;

    system("pause");

}

void InformesManager::informeTop5ChoferesConMasViajes(){

    Choferes chofer;
    Viajes viaje;

    int cantidadViajes = _repoViajes.contarRegistros();

    limpiarPantalla();
    cout << "---- INFORME: TOP 5 CHOFERES CON MAS VIAJES ----" << endl;

    if(cantidadViajes == -1 || cantidadViajes == 0){
        cout << "No hay viajes registrados." << endl;
        system("pause");
        return;
    }

    char (*dnis)[9] = new char[cantidadViajes][9];
    int* conteos = new int[cantidadViajes];
    int cantidadUnicos = 0;

    for(int x = 0; x < cantidadViajes; x++){

        viaje = _repoViajes.leer(x);
        if(viaje.getEliminado())
            continue;

        bool existe = false;

        for(int y = 0; y < cantidadUnicos; y++){

            if(strcmp(dnis[y], viaje.getDniChofer()) == 0){
                conteos[y]++;
                existe = true;
                break;
            }

        }

        if(!existe){
            strcpy(dnis[cantidadUnicos], viaje.getDniChofer());
            conteos[cantidadUnicos] = 1;
            cantidadUnicos++;
        }

    }

    if(cantidadUnicos == 0){
        cout << "No hay viajes registrados." << endl;
        delete[] dnis;
        delete[] conteos;
        system("pause");
        return;
    }

    for(int x = 0; x < cantidadUnicos - 1; x++){

        for(int y = 0; y < cantidadUnicos - 1 - x; y++){

            if(conteos[y] < conteos[y + 1]){
                int tempConteo = conteos[y];
                conteos[y] = conteos[y + 1];
                conteos[y + 1] = tempConteo;

                char tempDni[9];
                strcpy(tempDni, dnis[y]);
                strcpy(dnis[y], dnis[y + 1]);
                strcpy(dnis[y + 1], tempDni);
            }

        }

    }

    int limite = cantidadUnicos < 5 ? cantidadUnicos : 5;

    for(int x = 0; x < limite; x++){

        if(x > 0)
            cout << "-----------------------------" << endl;

        cout << x + 1 << ". ";
        if(buscarChoferPorDni(dnis[x], chofer))
            cout << chofer.getNombre() << " " << chofer.getApellido() << endl;
        else
            cout << "Chofer no encontrado" << endl;

        cout << "DNI: " << dnis[x] << endl;
        cout << "Cantidad de viajes: " << conteos[x] << endl;

    }

    delete[] dnis;
    delete[] conteos;
    system("pause");

}

void InformesManager::informeTop5ClientesConMasViajes(){

    Clientes cliente;
    Viajes viaje;

    int cantidadViajes = _repoViajes.contarRegistros();

    limpiarPantalla();
    cout << "---- INFORME: TOP 5 CLIENTES CON MAS VIAJES ----" << endl;

    if(cantidadViajes == -1 || cantidadViajes == 0){
        cout << "No hay viajes registrados." << endl;
        system("pause");
        return;
    }

    char (*dnis)[9] = new char[cantidadViajes][9];
    int* conteos = new int[cantidadViajes];
    int cantidadUnicos = 0;

    for(int x = 0; x < cantidadViajes; x++){

        viaje = _repoViajes.leer(x);
        if(viaje.getEliminado())
            continue;

        bool existe = false;

        for(int y = 0; y < cantidadUnicos; y++){

            if(strcmp(dnis[y], viaje.getDniCliente()) == 0){
                conteos[y]++;
                existe = true;
                break;
            }

        }

        if(!existe){
            strcpy(dnis[cantidadUnicos], viaje.getDniCliente());
            conteos[cantidadUnicos] = 1;
            cantidadUnicos++;
        }

    }

    if(cantidadUnicos == 0){
        cout << "No hay viajes registrados." << endl;
        delete[] dnis;
        delete[] conteos;
        system("pause");
        return;
    }

    for(int x = 0; x < cantidadUnicos - 1; x++){

        for(int y = 0; y < cantidadUnicos - 1 - x; y++){

            if(conteos[y] < conteos[y + 1]){
                int tempConteo = conteos[y];
                conteos[y] = conteos[y + 1];
                conteos[y + 1] = tempConteo;

                char tempDni[9];

                strcpy(tempDni, dnis[y]);
                strcpy(dnis[y], dnis[y + 1]);
                strcpy(dnis[y + 1], tempDni);
            }

        }

    }

    int limite = cantidadUnicos < 5 ? cantidadUnicos : 5;

    for(int x = 0; x < limite; x++){

        if(x > 0)
            cout << "-----------------------------" << endl;

        cout << x + 1 << ". ";

        if(buscarClientePorDni(dnis[x], cliente))
            cout << cliente.getNombre() << " " << cliente.getApellido() << endl;

        else
            cout << "Cliente no encontrado" << endl;

        cout << "DNI: " << dnis[x] << endl;
        cout << "Cantidad de viajes: " << conteos[x] << endl;

    }

    delete[] dnis;
    delete[] conteos;
    system("pause");

}

