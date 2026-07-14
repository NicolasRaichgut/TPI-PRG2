#include <iostream>
#include <cstring>
#include "viajesManager.h"
#include "consola.h"
#include "pagosManager.h"
#include "calificacionesManager.h"
using namespace std;


// GESTION DE VIAJES
void ViajesManager::crearViaje(){

    Viajes viaje;
    string id, dniCliente, dniChofer;

    limpiarPantalla();
    cout << "---- CREANDO VIAJE ----" << endl;

    while(true){

        cout << "Ingrese ID del viaje (5 caracteres)(0 para cancelar): ";
        cin >> id;

        if(id == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(!existeViaje(id.c_str()) && viaje.setId(id))
            break;

        cout << "ID invalido o existente." << endl;

    }

    while(true){

        cout << "Ingrese DNI del cliente (0 para cancelar): ";
        cin >> dniCliente;

        if(dniCliente == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(existeCliente(dniCliente.c_str()) && viaje.setDniCliente(dniCliente))
            break;

        cout << "Cliente inexistente o DNI invalido." << endl;

    }

    while(true){

        cout << "Ingrese DNI del chofer (0 para cancelar): ";
        cin >> dniChofer;

        if(dniChofer == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(existeChofer(dniChofer.c_str()) && viaje.setDniChofer(dniChofer))
            break;

        cout << "Chofer inexistente o DNI invalido." << endl;

    }

    if(!viaje.cargar()){
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    if(_repo.guardar(viaje)){
        cout << "El viaje ha sido creado." << endl;
        system("pause");
    }
    else{
        cout << "Hubo un error en la creacion del viaje." << endl;
        system("pause");
    }

}


// LISTADOS DE VIAJES
void ViajesManager::listarViajes(){

    Viajes viaje;
    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO VIAJES ----" << endl;

    for(int x = 0; x < cantidad; x++){

        viaje = _repo.leer(x);

        if(!viaje.getEliminado()){

            viaje.mostrar();
            if(x != cantidad - 1)
                cout << "-----------------------------" << endl;

        }

    }

    system("pause");
}

void ViajesManager::listarViajesOrdenadosPorFecha(){

    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO VIAJES (DEL MAS RECIENTE AL MAS VIEJO) ----" << endl;

    if(cantidad == -1){
        cout << "No hay viajes registrados." << endl;
        system("pause");
        return;
    }

    Viajes* viajes = new Viajes[cantidad];
    int cantidadActivos = cargarViajesActivos(viajes, cantidad);

    for(int x = 0; x < cantidadActivos - 1; x++){
        for(int y = 0; y < cantidadActivos - 1 - x; y++){
            Fecha fechaActual = viajes[y].getFechaViaje();
            Fecha fechaSiguiente = viajes[y + 1].getFechaViaje();
            bool intercambiar = false;

            if(fechaActual.getAnio() != fechaSiguiente.getAnio())
                intercambiar = fechaActual.getAnio() < fechaSiguiente.getAnio();
            else if(fechaActual.getMes() != fechaSiguiente.getMes())
                intercambiar = fechaActual.getMes() < fechaSiguiente.getMes();
            else if(fechaActual.getDia() != fechaSiguiente.getDia())
                intercambiar = fechaActual.getDia() < fechaSiguiente.getDia();

            if(intercambiar){
                Viajes temp = viajes[y];
                viajes[y] = viajes[y + 1];
                viajes[y + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidadActivos; x++){
        viajes[x].mostrar();
        if(x != cantidadActivos - 1)
            cout << "-----------------------------" << endl;
    }

    delete[] viajes;
    system("pause");
}


// CONSULTAS DE VIAJES
void ViajesManager::consultarViajePorId(){

    Viajes viaje;
    int cantidad = _repo.contarRegistros();
    string id;

    limpiarPantalla();
    cout << "---- CONSULTANDO VIAJE ----" << endl;
    cout << "Ingrese el ID del viaje a consultar: " << endl;
    cin >> id;

    for(int x = 0; x < cantidad; x++){

        viaje = _repo.leer(x);

        if(!viaje.getEliminado() &&
           strcmp(viaje.getId(), id.c_str()) == 0){

            viaje.mostrar();
            system("pause");
            return;

        }

    }

    cout << "No existe un viaje con ese ID." << endl;
    system("pause");

}

void ViajesManager::consultarViajesPorDniCliente(){

    Viajes viaje;
    int cantidad = _repo.contarRegistros();
    string dni;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- CONSULTANDO VIAJES POR DNI DE CLIENTE ----" << endl;

    while(true){

        cout << "Ingrese el DNI del cliente (0 para cancelar): ";
        cin >> dni;

        if(dni == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(viaje.setDniCliente(dni))
            break;

        cout << "DNI invalido." << endl;

    }

    for(int x = 0; x < cantidad; x++){
        viaje = _repo.leer(x);
        if(!viaje.getEliminado() && strcmp(viaje.getDniCliente(), dni.c_str()) == 0){

            if(encontro)
                cout << "-----------------------------" << endl;

            viaje.mostrar();
            encontro = true;

        }
    }

    if(!encontro)
        cout << "No hay viajes registrados para ese cliente." << endl;

    system("pause");

}

void ViajesManager::consultarViajesPorDniChofer(){

    Viajes viaje;
    int cantidad = _repo.contarRegistros();
    string dni;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- CONSULTANDO VIAJES POR DNI DE CHOFER ----" << endl;

    while(true){

        cout << "Ingrese el DNI del chofer (0 para cancelar): ";
        cin >> dni;

        if(dni == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(viaje.setDniChofer(dni))
            break;

        cout << "DNI invalido." << endl;

    }

    for(int x = 0; x < cantidad; x++){
        viaje = _repo.leer(x);
        if(!viaje.getEliminado() && strcmp(viaje.getDniChofer(), dni.c_str()) == 0){

            if(encontro)
                cout << "-----------------------------" << endl;

            viaje.mostrar();
            encontro = true;

        }
    }

    if(!encontro)
        cout << "No hay viajes registrados para ese chofer." << endl;

    system("pause");

}

void ViajesManager::consultarViajesPorMesAnio(){

    Viajes viaje;
    int cantidad = _repo.contarRegistros();
    int mes, anio;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- CONSULTANDO VIAJES POR MES Y ANIO ----" << endl;

    while(true){

        cout << "Ingrese mes (0 para cancelar): ";
        cin >> mes;

        if(mes == 0){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        cout << "Ingrese anio: ";
        cin >> anio;

        Fecha fechaPrueba(1, mes, anio);
        if(viaje.setFechaViaje(fechaPrueba))
            break;

        cout << "Mes o anio invalido." << endl;

    }

    for(int x = 0; x < cantidad; x++){
        viaje = _repo.leer(x);
        Fecha fechaViaje = viaje.getFechaViaje();
        if(!viaje.getEliminado() &&
           fechaViaje.getMes() == mes &&
           fechaViaje.getAnio() == anio){

            if(encontro)
                cout << "-----------------------------" << endl;

            viaje.mostrar();
            encontro = true;

        }
    }

    if(!encontro)
        cout << "No hay viajes registrados en ese mes y anio." << endl;

    system("pause");

}



int ViajesManager::cargarViajesActivos(Viajes* viajes, int cantidadMax){

    Viajes viaje;
    int cantidadActivos = 0;

    for(int x = 0; x < cantidadMax; x++){
        viaje = _repo.leer(x);
        if(!viaje.getEliminado()){
            viajes[cantidadActivos] = viaje;
            cantidadActivos++;
        }
    }

    return cantidadActivos;
}

bool ViajesManager::hayViajes(){

    return _repo.contarRegistros() > 0;

}

bool ViajesManager::existeCliente(const char* dniCliente){

    Clientes cliente;

    int cantidad = _repoClientes.contarRegistros();

    for(int x = 0; x < cantidad; x++){

        cliente = _repoClientes.leer(x);

        if(!cliente.getEliminado() &&
           strcmp(cliente.getDni(), dniCliente) == 0)
            return true;

    }

    return false;

}

bool ViajesManager::existeChofer(const char* dniChofer){

    Choferes chofer;

    int cantidad = _repoChoferes.contarRegistros();

    for(int x = 0; x < cantidad; x++){

        chofer = _repoChoferes.leer(x);

        if(!chofer.getEliminado() &&
           strcmp(chofer.getDni(), dniChofer) == 0)
            return true;

    }

    return false;

}

bool ViajesManager::existeViaje(const char* id){

    Viajes viaje;

    int cantidad = _repo.contarRegistros();

    for(int x = 0; x < cantidad; x++){

        viaje = _repo.leer(x);

        if(!viaje.getEliminado() &&
           strcmp(viaje.getId(), id) == 0)
            return true;

    }

    return false;

}


