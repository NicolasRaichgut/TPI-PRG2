#include <iostream>
#include <cstring>
#include <cstdio>
#include "pagosManager.h"
#include "consola.h"
#include "viajesArchivo.h"
using namespace std;


// GESTION DE PAGOS
void PagosManager::crearPago(){

    Pagos pago;
    string id, idViaje;

    limpiarPantalla();
    cout << "---- CREANDO PAGO ----" << endl;

    while(true){

        cout << "Ingrese ID del pago (5 caracteres)(0 para cancelar): ";
        cin >> id;

        if(id == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(!existePago(id.c_str()) && pago.setId(id))
            break;

        cout << "ID invalido o existente." << endl;

    }

    while(true){

        cout << "Ingrese ID del viaje (5 caracteres)(0 para cancelar): ";
        cin >> idViaje;

        if(idViaje == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(existeViaje(idViaje.c_str()) && pago.setIdViaje(idViaje))
            break;

        cout << "ID de viaje invalido o inexistente." << endl;

    }

    if(!pago.cargar()){
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    if(_repo.guardar(pago)){
        cout << "El pago ha sido creado." << endl;
        system("pause");
    }
    else{
        cout << "Hubo un error en la creacion del pago." << endl;
        system("pause");
    }

}


// LISTADOS DE PAGOS
void PagosManager::listarPagos(){

    Pagos pago;
    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO PAGOS ----" << endl;

    for(int x = 0; x < cantidad; x++){

        pago = _repo.leer(x);

        if(!pago.getEliminado()){

            pago.mostrar();

            if(x != cantidad - 1)
                cout << "-----------------------------" << endl;

        }

    }

    system("pause");
}

void PagosManager::listarPagosOrdenadosPorMonto(){
    
    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO PAGOS (DE MENOS A MAS MONTO) ----" << endl;

    if(cantidad == -1){
        cout << "No hay pagos registrados." << endl;
        system("pause");
        return;
    }

    Pagos* pagos = new Pagos[cantidad];
    int cantidadActivos = cargarPagosActivos(pagos, cantidad);
    
    for(int x = 0; x < cantidadActivos - 1; x++){
        for(int y = 0; y < cantidadActivos - 1 - x; y++){
            if(pagos[y].getMonto() > pagos[y + 1].getMonto()){
                Pagos temp = pagos[y];
                pagos[y] = pagos[y + 1];
                pagos[y + 1] = temp;
            }
        }
    }
    
    for(int x = 0; x < cantidadActivos; x++){
        pagos[x].mostrar();
        if(x != cantidadActivos - 1)
        cout << "-----------------------------" << endl;
    }

    delete[] pagos;
    system("pause");

}


// CONSULTAS DE PAGOS
void PagosManager::consultarPagosPorMetodoPago(){

    Pagos pago;
    int cantidad = _repo.contarRegistros();
    int metodoPago;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- CONSULTANDO PAGOS POR METODO ----" << endl;
    cout << "1 - Efectivo" << endl;
    cout << "2 - Tarjeta" << endl;
    cout << "3 - Transferencia" << endl;
    cout << "Ingrese el metodo de pago a consultar: " << endl;
    cin >> metodoPago;

    if(metodoPago < 1 || metodoPago > 3){
        cout << "Metodo de pago invalido." << endl;
        system("pause");
        return;
    }

    for(int x = 0; x < cantidad; x++){

        pago = _repo.leer(x);

        if(!pago.getEliminado() && pago.getMetodoPago() == metodoPago){

            if(encontro)
                cout << "-----------------------------" << endl;

            pago.mostrar();
            encontro = true;

        }

    }

    if(!encontro)
        cout << "No hay pagos con ese metodo." << endl;

    system("pause");
}

void PagosManager::consultarPagoPorId(){

    Pagos pago;
    int cantidad = _repo.contarRegistros();
    string id;

    limpiarPantalla();
    cout << "---- CONSULTANDO PAGO ----" << endl;
    cout << "Ingrese el ID del pago a consultar: " << endl;
    cin >> id;

    for(int x = 0; x < cantidad; x++){

        pago = _repo.leer(x);

        if(!pago.getEliminado() &&
           strcmp(pago.getId(), id.c_str()) == 0){

            pago.mostrar();
            system("pause");
            return;

        }

    }

    cout << "No existe un pago con ese ID." << endl;
    system("pause");

}



int PagosManager::cargarPagosActivos(Pagos* pagos, int cantidadMax){

    Pagos pago;
    int cantidadActivos = 0;

    for(int x = 0; x < cantidadMax; x++){
        pago = _repo.leer(x);
        if(!pago.getEliminado()){
            pagos[cantidadActivos] = pago;
            cantidadActivos++;
        }
    }

    return cantidadActivos;
}

bool PagosManager::hayPagos(){

    return _repo.contarRegistros() > 0;

}

bool PagosManager::existePago(const char* id){

    Pagos pago;
    int cantidad = _repo.contarRegistros();

    for(int x = 0; x < cantidad; x++){

        pago = _repo.leer(x);

        if(!pago.getEliminado() &&
           strcmp(pago.getId(), id) == 0)
            return true;

    }

    return false;

}

bool PagosManager::existeViaje(const char* idViaje){

    ViajesArchivo repoViajes;
    Viajes viaje;

    int cantidad = repoViajes.contarRegistros();

    for(int x = 0; x < cantidad; x++){

        viaje = repoViajes.leer(x);

        if(!viaje.getEliminado() &&
           strcmp(viaje.getId(), idViaje) == 0)
            return true;

    }

    return false;

}
