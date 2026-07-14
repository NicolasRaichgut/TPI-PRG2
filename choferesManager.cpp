#include <iostream>
#include <cstring>
#include <cstdio>
#include "choferesManager.h"
#include "consola.h"
using namespace std;


// GESTION DE CHOFERES
void ChoferesManager::crearChofer(){

    Choferes chofer;
    string dni;

    limpiarPantalla();
    cout << "---- CREANDO CHOFER ----" << endl;

    while(true){

        cout << "Ingrese DNI (0 para cancelar): ";
        cin >> dni;

        if(dni == "0"){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        if(!existeDni(dni.c_str()) && chofer.setDni(dni))
            break;

        cout << "DNI invalido o existente." << endl;

    }

    cin.ignore();

    if(!chofer.cargar()){
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    if(_repo.guardar(chofer)){
        cout << "El chofer ha sido creado." << endl;
        system("pause");
    }
    else{
        cout << "Hubo un error en la creacion del chofer." << endl;
        system("pause");
    }

}

void ChoferesManager::modificarChofer(){

    Choferes chofer;
    int cantidad = _repo.contarRegistros();
    string dni;

    limpiarPantalla();
    cout << "---- MODIFICANDO CHOFER ----" << endl;
    cout << "Ingrese el DNI del chofer a modificar: " << endl;
    cin >> dni;

    for(int x = 0; x < cantidad; x++){

        chofer = _repo.leer(x);

        if(!chofer.getEliminado() &&
           strcmp(chofer.getDni(), dni.c_str()) == 0){

            cout << "Chofer encontrado:" << endl;
            chofer.mostrar();

            cout << "Esta seguro de que desea modificar el registro? [1-Si / 0-No]" << endl;

            int opcion;
            cin >> opcion;

            if(opcion == 1){

                limpiarPantalla();

                cout << "---- Nuevos datos ----" << endl;

                if(!chofer.cargar()){
                    cout << "Operacion cancelada." << endl;
                    system("pause");
                    return;
                }

                if(_repo.guardar(chofer, x)){
                    cout << "El chofer modificado ha sido guardado con exito!" << endl;
                    system("pause");
                    return;
                }
                else{
                    cout << "No se pudieron cargar los nuevos datos." << endl;
                    system("pause");
                    return;
                }

            }
            else{
                cout << "Operacion cancelada." << endl;
                system("pause");
                return;
            }

        }

    }

    cout << "No existe un chofer con ese dni." << endl;
    system("pause");

}

void ChoferesManager::eliminarChofer(){

    Choferes chofer;
    int cantidad = _repo.contarRegistros();
    string dni;

    limpiarPantalla();
    cout << "---- ELIMINANDO CHOFER ----" << endl;
    cout << "Ingrese el DNI del chofer a eliminar: " << endl;
    cin >> dni;

    for(int x = 0; x < cantidad; x++){

        chofer = _repo.leer(x);

        if(!chofer.getEliminado() &&
           strcmp(chofer.getDni(), dni.c_str()) == 0){

            cout << "Chofer encontrado:" << endl;
            chofer.mostrar();

            cout << "Esta seguro de que desea eliminar el registro? [1-Si / 0-No]" << endl;

            int opcion;
            cin >> opcion;

            if(opcion == 1){

                if(_repo.bajaLogica(x)){
                    cout << "Chofer eliminado correctamente." << endl;
                    system("pause");
                }
                else{
                    cout << "No se pudo eliminar el chofer." << endl;
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

    cout << "No existe un chofer con ese dni." << endl;
    system("pause");

}


// LISTADOS DE CHOFERES
void ChoferesManager::listarChoferes(){

    Choferes chofer;
    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO CHOFERES ----" << endl;

    for(int x = 0; x < cantidad; x++){

        chofer = _repo.leer(x);

        if(!chofer.getEliminado()){

            chofer.mostrar();

            if(x != cantidad - 1)
                cout << "-----------------------------" << endl;

        }

    }

    system("pause");

}

void ChoferesManager::listarChoferesOrdenadosPorNombre(){

    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO CHOFERES (A-Z POR NOMBRE) ----" << endl;

    if(cantidad == -1){
        cout << "No hay choferes registrados." << endl;
        system("pause");
        return;
    }

    Choferes* choferes = new Choferes[cantidad];
    int cantidadActivos = cargarChoferesActivos(choferes, cantidad);

    for(int x = 0; x < cantidadActivos - 1; x++){
        for(int y = 0; y < cantidadActivos - 1 - x; y++){
            if(strcmp(choferes[y].getNombre(), choferes[y + 1].getNombre()) > 0){
                Choferes temp = choferes[y];
                choferes[y] = choferes[y + 1];
                choferes[y + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidadActivos; x++){
        choferes[x].mostrar();
        if(x != cantidadActivos - 1)
            cout << "-----------------------------" << endl;
    }

    delete[] choferes;
    system("pause");
}

void ChoferesManager::listarChoferesOrdenadosPorFechaNacimiento(){

    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO CHOFERES (DEL MAS JOVEN AL MAS VIEJO) ----" << endl;

    if(cantidad == -1){
        cout << "No hay choferes registrados." << endl;
        system("pause");
        return;
    }

    Choferes* choferes = new Choferes[cantidad];
    int cantidadActivos = cargarChoferesActivos(choferes, cantidad);

    for(int x = 0; x < cantidadActivos - 1; x++){
        for(int y = 0; y < cantidadActivos - 1 - x; y++){
            Fecha fechaActual = choferes[y].getFechaNacimiento();
            Fecha fechaSiguiente = choferes[y + 1].getFechaNacimiento();
            bool intercambiar = false;

            if(fechaActual.getAnio() != fechaSiguiente.getAnio())
                intercambiar = fechaActual.getAnio() < fechaSiguiente.getAnio();
            else if(fechaActual.getMes() != fechaSiguiente.getMes())
                intercambiar = fechaActual.getMes() < fechaSiguiente.getMes();
            else if(fechaActual.getDia() != fechaSiguiente.getDia())
                intercambiar = fechaActual.getDia() < fechaSiguiente.getDia();

            if(intercambiar){
                Choferes temp = choferes[y];
                choferes[y] = choferes[y + 1];
                choferes[y + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidadActivos; x++){
        choferes[x].mostrar();
        if(x != cantidadActivos - 1)
            cout << "-----------------------------" << endl;
    }

    delete[] choferes;
    system("pause");
}


// CONSULTAS DE CHOFERES
void ChoferesManager::consultarChoferPorDni(){

    Choferes chofer;
    int cantidad = _repo.contarRegistros();
    string dni;

    limpiarPantalla();
    cout << "---- CONSULTANDO CHOFER ----" << endl;
    cout << "Ingrese el DNI del chofer a consultar: " << endl;
    cin >> dni;

    for(int x = 0; x < cantidad; x++){

        chofer = _repo.leer(x);

        if(!chofer.getEliminado() &&
           strcmp(chofer.getDni(), dni.c_str()) == 0){

            chofer.mostrar();
            system("pause");
            return;

        }

    }

    cout << "No existe un chofer con ese dni." << endl;
    system("pause");

}

void ChoferesManager::consultarChoferesPorAnioNacimiento(){

    Choferes chofer;
    int cantidad = _repo.contarRegistros();
    int anio;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- CONSULTANDO CHOFERES POR ANIO DE NACIMIENTO ----" << endl;

    while(true){

        cout << "Ingrese el anio de nacimiento (0 para cancelar): ";
        cin >> anio;

        if(anio == 0){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        Fecha fechaPrueba(1, 1, anio);
        if(chofer.setFechaNacimiento(fechaPrueba))
            break;

        cout << "Anio invalido." << endl;

    }

    for(int x = 0; x < cantidad; x++){
        chofer = _repo.leer(x);
        if(!chofer.getEliminado() && chofer.getFechaNacimiento().getAnio() == anio){

            if(encontro)
                cout << "-----------------------------" << endl;

            chofer.mostrar();
            encontro = true;

        }
    }

    if(!encontro)
        cout << "No hay choferes nacidos en ese anio." << endl;

    system("pause");

}



int ChoferesManager::cargarChoferesActivos(Choferes* choferes, int cantidadMax){

    Choferes chofer;
    int cantidadActivos = 0;

    for(int x = 0; x < cantidadMax; x++){
        chofer = _repo.leer(x);
        if(!chofer.getEliminado()){
            choferes[cantidadActivos] = chofer;
            cantidadActivos++;
        }
    }

    return cantidadActivos;
}

bool ChoferesManager::hayChoferes(){

    return _repo.contarRegistros() > 0;

}

bool ChoferesManager::existeDni(const char* dni){

    Choferes chofer;
    int cantidad = _repo.contarRegistros();

    for(int x = 0; x < cantidad; x++){

        chofer = _repo.leer(x);

        if(!chofer.getEliminado() &&
           strcmp(chofer.getDni(), dni) == 0)
            return true;

    }

    return false;

}


