#include <iostream>
#include <cstring>
#include <cstdio>
#include "remisesManager.h"
#include "consola.h"
using namespace std;


// GESTION DE REMISES
void RemisesManager::crearRemis(){

    Remises remis;
    string patente, dniChofer;

    limpiarPantalla();
    cout << "---- CREANDO REMIS ----" << endl;

    while(true){

        cout << "Ingrese patente (0 para cancelar): ";
        cin >> patente;

        if(patente == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(!existeRemis(patente.c_str()) && remis.setPatente(patente))
            break;

        cout << "Patente invalida o existente." << endl;

    }

    while(true){

        cout << "Ingrese DNI del chofer (0 para cancelar): ";
        cin >> dniChofer;

        if(dniChofer == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(existeChofer(dniChofer.c_str()) && remis.setDniChofer(dniChofer))
            break;

        cout << "Chofer inexistente o DNI invalido." << endl;

    }

    cin.ignore();

    if(!remis.cargar()){
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    if(_repo.guardar(remis)){
        cout << "El remis ha sido creado." << endl;
        system("pause");
    }
    else{
        cout << "Hubo un error en la creacion del remis." << endl;
        system("pause");
    }

}

void RemisesManager::eliminarRemis(){

    Remises remis;
    int cantidad = _repo.contarRegistros();
    string patente;

    limpiarPantalla();
    cout << "---- ELIMINANDO REMIS ----" << endl;
    cout << "Ingrese la patente del remis a eliminar: " << endl;
    cin >> patente;

    for(int x = 0; x < cantidad; x++){

        remis = _repo.leer(x);

        if(!remis.getEliminado() &&
           strcmp(remis.getPatente(), patente.c_str()) == 0){

            cout << "Remis encontrado:" << endl;
            remis.mostrar();

            cout << "Esta seguro de que desea eliminar el registro? [1-Si / 0-No]" << endl;

            int opcion;
            cin >> opcion;

            if(opcion == 1){

                if(_repo.bajaLogica(x)){
                    cout << "Remis eliminado correctamente." << endl;
                    system("pause");
                }
                else{
                    cout << "No se pudo eliminar el remis." << endl;
                    system("pause");
                }

                return;

            }
            else{

                cout << "Operacion cancelada." << endl;
                system("pause");
                return;

            }

        }

    }

    cout << "No existe un remis con esa patente." << endl;
    system("pause");

}


// LISTADOS DE REMISES
void RemisesManager::listarRemises(){

    Remises remis;
    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO REMISES ----" << endl;

    for(int x = 0; x < cantidad; x++){

        remis = _repo.leer(x);

        if(!remis.getEliminado()){

            remis.mostrar();

            if(x != cantidad - 1)
            cout << "-----------------------------" << endl;
        
        }

    }
    
    system("pause");
}

void RemisesManager::listarRemisesOrdenadosPorFechaLanzamiento(){

    int cantidad = _repo.contarRegistros();
    Remises* remises = new Remises[cantidad];
    int cantidadActivos = cargarRemisesActivos(remises, cantidad);

    limpiarPantalla();
    cout << "---- LISTANDO REMISES (DEL MAS NUEVO AL MAS VIEJO) ----" << endl;

    for(int x = 0; x < cantidadActivos - 1; x++){
        for(int y = 0; y < cantidadActivos - 1 - x; y++){
            Fecha fechaActual = remises[y].getFechaLanzamiento();
            Fecha fechaSiguiente = remises[y + 1].getFechaLanzamiento();
            bool intercambiar = false;

            if(fechaActual.getAnio() != fechaSiguiente.getAnio())
                intercambiar = fechaActual.getAnio() < fechaSiguiente.getAnio();
            else if(fechaActual.getMes() != fechaSiguiente.getMes())
                intercambiar = fechaActual.getMes() < fechaSiguiente.getMes();
            else if(fechaActual.getDia() != fechaSiguiente.getDia())
                intercambiar = fechaActual.getDia() < fechaSiguiente.getDia();

            if(intercambiar){
                Remises temp = remises[y];
                remises[y] = remises[y + 1];
                remises[y + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidadActivos; x++){
        remises[x].mostrar();
        if(x != cantidadActivos - 1)
            cout << "-----------------------------" << endl;
    }

    delete[] remises;
    system("pause");
}

void RemisesManager::listarRemisesOrdenadosPorCapacidad(){

    int cantidad = _repo.contarRegistros();
    Remises* remises = new Remises[cantidad];
    int cantidadActivos = cargarRemisesActivos(remises, cantidad);

    limpiarPantalla();
    cout << "---- LISTANDO REMISES (DE MENOS A MAS CAPACIDAD) ----" << endl;

    for(int x = 0; x < cantidadActivos - 1; x++){
        for(int y = 0; y < cantidadActivos - 1 - x; y++){
            if(remises[y].getCapacidadPasajeros() > remises[y + 1].getCapacidadPasajeros()){
                Remises temp = remises[y];
                remises[y] = remises[y + 1];
                remises[y + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidadActivos; x++){
        remises[x].mostrar();
        if(x != cantidadActivos - 1)
            cout << "-----------------------------" << endl;
    }

    delete[] remises;
    system("pause");
}


// CONSULTAS DE REMISES
void RemisesManager::consultarRemisPorPatente(){

    Remises remis;
    int cantidad = _repo.contarRegistros();
    string patente;

    limpiarPantalla();
    cout << "---- CONSULTANDO REMIS ----" << endl;
    cout << "Ingrese la patente del remis a consultar: " << endl;
    cin >> patente;

    for(int x = 0; x < cantidad; x++){

        remis = _repo.leer(x);

        if(!remis.getEliminado() &&
           strcmp(remis.getPatente(), patente.c_str()) == 0){

            remis.mostrar();
            system("pause");
            return;
            
        }

    }
    
    cout << "No existe un remis con esa patente." << endl;
    system("pause");
}

void RemisesManager::consultarRemisPorDniChofer(){

    Remises remis;
    int cantidad = _repo.contarRegistros();
    string dni;

    limpiarPantalla();
    cout << "---- CONSULTANDO REMIS ----" << endl;
    cout << "Ingrese el dni del chofer dueno del remis a consultar: " << endl;
    cin >> dni;

    for(int x = 0; x < cantidad; x++){

        remis = _repo.leer(x);
        if(!remis.getEliminado() && strcmp(remis.getDniChofer(), dni.c_str()) == 0){
            remis.mostrar();
            system("pause");
            return;
        }
    }

    cout << "No existe un remis con esa chofer.";
    system("pause");

}



int RemisesManager::cargarRemisesActivos(Remises* remises, int cantidadMax){

    Remises remis;
    int cantidadActivos = 0;

    for(int x = 0; x < cantidadMax; x++){
        remis = _repo.leer(x);
        if(!remis.getEliminado()){
            remises[cantidadActivos] = remis;
            cantidadActivos++;
        }
    }

    return cantidadActivos;
}

bool RemisesManager::hayRemises(){
    return _repo.contarRegistros() > 0;
}

bool RemisesManager::existeRemis(const char* patente){

    Remises remis;
    int cantidad = _repo.contarRegistros();

    for(int x = 0; x < cantidad; x++){

        remis = _repo.leer(x);
        if(!remis.getEliminado() && strcmp(remis.getPatente(), patente)==0)
            return true;


    }

    return false;

}

bool RemisesManager::existeChofer(const char* dniChofer){

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

bool RemisesManager::choferTieneRemis(char* dni){

    Remises remis;
    int cantidad = _repo.contarRegistros();

    for(int x = 0; x < cantidad; x++){

        remis = _repo.leer(x);
        if(!remis.getEliminado() && strcmp(remis.getDniChofer(), dni)==0)
            return true;

    }

    return false;

}


