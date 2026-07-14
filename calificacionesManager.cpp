#include <iostream>
#include <cstring>
#include <cstdio>
#include "calificacionesManager.h"
#include "consola.h"
#include "viajesArchivo.h"
using namespace std;


// GESTION DE CALIFICACIONES
void CalificacionesManager::crearCalificacion(){

    Calificaciones calificacion;
    string id, idViaje;

    limpiarPantalla();
    cout << "---- CREANDO CALIFICACION ----" << endl;

    while(true){

        cout << "Ingrese ID de la calificacion (5 caracteres)(0 para cancelar): ";
        cin >> id;

        if(id == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(!existeCalificacion(id.c_str()) && calificacion.setId(id))
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

        if(existeViaje(idViaje.c_str()) && calificacion.setIdViaje(idViaje))
            break;

        cout << "ID de viaje invalido o inexistente." << endl;

    }

    if(!calificacion.cargar()){
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    if(_repo.guardar(calificacion)){
        cout << "La calificacion ha sido creada." << endl;
        system("pause");
    }
    else{
        cout << "Hubo un error en la creacion de la calificacion." << endl;
        system("pause");
    }

}


// LISTADOS DE CALIFICACIONES
void CalificacionesManager::listarCalificaciones(){

    Calificaciones calificacion;
    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO CALIFICACIONES ----" << endl;

    for(int x = 0; x < cantidad; x++){

        calificacion = _repo.leer(x);

        if(!calificacion.getEliminado()){

            calificacion.mostrar();

            if(x != cantidad - 1)
                cout << "-----------------------------" << endl;

        }

    }

    system("pause");
}

void CalificacionesManager::listarCalificacionesOrdenadasPorPuntaje(){

    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO CALIFICACIONES (DE MENOS A MAS PUNTAJE) ----" << endl;

    if(cantidad == -1){
        cout << "No hay calificaciones registradas." << endl;
        system("pause");
        return;
    }

    Calificaciones* calificaciones = new Calificaciones[cantidad];
    int cantidadActivas = cargarCalificacionesActivas(calificaciones, cantidad);

    for(int x = 0; x < cantidadActivas - 1; x++){
        for(int y = 0; y < cantidadActivas - 1 - x; y++){
            if(calificaciones[y].getPuntaje() > calificaciones[y + 1].getPuntaje()){
                Calificaciones temp = calificaciones[y];
                calificaciones[y] = calificaciones[y + 1];
                calificaciones[y + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidadActivas; x++){
        calificaciones[x].mostrar();
        if(x != cantidadActivas - 1)
            cout << "-----------------------------" << endl;
    }

    delete[] calificaciones;
    system("pause");
}


// CONSULTAS DE CALIFICACIONES
void CalificacionesManager::consultarCalificacionPorId(){

    Calificaciones calificacion;
    int cantidad = _repo.contarRegistros();
    string id;

    limpiarPantalla();
    cout << "---- CONSULTANDO CALIFICACION ----" << endl;
    cout << "Ingrese el ID de la calificacion a consultar: " << endl;
    cin >> id;

    for(int x = 0; x < cantidad; x++){

        calificacion = _repo.leer(x);

        if(!calificacion.getEliminado() &&
           strcmp(calificacion.getId(), id.c_str()) == 0){

            calificacion.mostrar();
            system("pause");
            return;

        }

    }

    cout << "No existe una calificacion con ese ID." << endl;
    system("pause");

}



int CalificacionesManager::cargarCalificacionesActivas(Calificaciones* calificaciones, int cantidadMax){

    Calificaciones calificacion;
    int cantidadActivas = 0;

    for(int x = 0; x < cantidadMax; x++){
        calificacion = _repo.leer(x);
        if(!calificacion.getEliminado()){
            calificaciones[cantidadActivas] = calificacion;
            cantidadActivas++;
        }
    }

    return cantidadActivas;
}

bool CalificacionesManager::hayCalificaciones(){

    return _repo.contarRegistros() > 0;

}

bool CalificacionesManager::existeCalificacion(const char* id){

    Calificaciones calificacion;
    int cantidad = _repo.contarRegistros();

    for(int x = 0; x < cantidad; x++){

        calificacion = _repo.leer(x);

        if(!calificacion.getEliminado() &&
           strcmp(calificacion.getId(), id) == 0)
            return true;

    }

    return false;

}

bool CalificacionesManager::existeViaje(const char* idViaje){

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
