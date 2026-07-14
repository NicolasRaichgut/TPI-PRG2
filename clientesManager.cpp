#include <iostream>
#include <cstring>
#include <cstdio>
#include "clientesManager.h"
#include "consola.h"
using namespace std;


// GESTION DE CLIENTES
void ClientesManager::crearCliente(){

    Clientes cliente;
    string dni;

    limpiarPantalla();
    cout << "---- CREANDO CLIENTE ----" << endl;

    while(true){

        cout << "Ingrese DNI (0 para cancelar): ";
        cin >> dni;

        if(dni == "0"){
            cout << "Operacion cancelada.\n";
            system("pause");
            return;
        }

        if(!existeDni(dni.c_str()) && cliente.setDni(dni))
            break;

        cout << "DNI invalido o existente.\n";

    }

    cin.ignore();

    if(!cliente.cargar()){
        cout << "Operacion cancelada.\n";
        system("pause");
        return;
    }

    if(_repo.guardar(cliente)){
        cout << "El cliente ha sido creado.\n";
        system("pause");
    }
    else{
        cout << "Hubo un error en la creacion del cliente.\n";
        system("pause");
    }
}

void ClientesManager::modificarCliente(){

    Clientes cliente;
    int cantidad = _repo.contarRegistros();
    string dni;

    limpiarPantalla();
    cout << "---- MODIFICANDO CLIENTE ----" << endl;
    cout << "Ingrese el DNI del cliente a modificar: " << endl;
    cin >> dni;

    for(int x = 0; x < cantidad; x++){
        cliente = _repo.leer(x);
        if(!cliente.getEliminado() && strcmp(cliente.getDni(), dni.c_str())==0){
            cout << "Cliente encontrado: " << endl;
            cliente.mostrar();
            cout << "Esta seguro de que desea modificar el registro? [1-Si / 0-No]" << endl;
            int opcion;
            cin >> opcion;
            if(opcion == 1){

                limpiarPantalla();
                cout << " ---- Nuevos datos ---- " << endl;
                if(!cliente.cargar()){
                    cout << "operacion cancelada." << endl;
                    system("pause");
                    return;
                }
                if(_repo.guardar(cliente, x)){
                    cout << "El cliente modificado ha sido guardado con exito!" << endl;
                    system("pause");
                    return;
                }
                else{
                    cout << "No se pudieron cargar los nuevos datos" << endl;
                    system("pause");
                    return;
                }

            }else{
                cout << "Operacion cancelada." << endl;
                system("pause");
                return;
            }
        }
    }

    cout << "No existe un cliente con ese dni." << endl;
    system("pause");

}

void ClientesManager::eliminarCliente(){

    Clientes cliente;
    int cantidad = _repo.contarRegistros();
    int opcion;
    string dni;

    limpiarPantalla();
    cout << "---- ELIMINANDO CLIENTE ----" << endl;
    cout << "Ingrese el DNI del cliente a eliminar: " << endl;
    cin >> dni;

    for(int x = 0; x < cantidad; x++){
        cliente = _repo.leer(x);
        if(!cliente.getEliminado() && strcmp(cliente.getDni(), dni.c_str())==0){

            cout << "Cliente encontrado: " << endl;
            cliente.mostrar();

            cout << "Esta seguro de que desea eliminar el registro? [1-Si / 0-No]" << endl;
            cin >> opcion;

            if(opcion == 1){

                if(_repo.bajaLogica(x)){
                    cout << "Cliente eliminado correctamente." << endl;
                    system("pause");
                }else{
                    cout << "No se pudo eliminar el cliente." << endl;
                    system("pause");
                }
                return;

            }else{
                cout << "Operacion cancelada." << endl;
                system("pause");
                return;
            }
        }
    }

    cout << "No existe un cliente con ese dni." << endl;
    system("pause");

}


// LISTADOS DE CLIENTES
void ClientesManager::listarClientes(){

    Clientes cliente;
    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO CLIENTES ----" << endl;

    for(int x = 0; x < cantidad; x++){
        cliente = _repo.leer(x);
        if(!cliente.getEliminado()){
            cliente.mostrar();
            if(x != cantidad-1)
                cout<<"-----------------------------"<<endl;
        }
    }

    system("pause");
}

void ClientesManager::listarClientesOrdenadosPorNombre(){

    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO CLIENTES (A-Z POR NOMBRE) ----" << endl;

    if(cantidad == -1){
        cout << "No hay clientes registrados." << endl;
        system("pause");
        return;
    }

    Clientes* clientes = new Clientes[cantidad];
    int cantidadActivos = cargarClientesActivos(clientes, cantidad);

    for(int x = 0; x < cantidadActivos - 1; x++){
        for(int y = 0; y < cantidadActivos - 1 - x; y++){
            if(strcmp(clientes[y].getNombre(), clientes[y + 1].getNombre()) > 0){
                Clientes temp = clientes[y];
                clientes[y] = clientes[y + 1];
                clientes[y + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidadActivos; x++){
        clientes[x].mostrar();
        if(x != cantidadActivos - 1)
            cout << "-----------------------------" << endl;
    }

    delete[] clientes;
    system("pause");

}

void ClientesManager::listarClientesOrdenadosPorFechaNacimiento(){

    int cantidad = _repo.contarRegistros();

    limpiarPantalla();
    cout << "---- LISTANDO CLIENTES (DEL MAS JOVEN AL MAS VIEJO) ----" << endl;

    if(cantidad == -1){
        cout << "No hay clientes registrados." << endl;
        system("pause");
        return;
    }

    Clientes* clientes = new Clientes[cantidad];
    int cantidadActivos = cargarClientesActivos(clientes, cantidad);

    for(int x = 0; x < cantidadActivos - 1; x++){
        for(int y = 0; y < cantidadActivos - 1 - x; y++){
            Fecha fechaActual = clientes[y].getFechaNacimiento();
            Fecha fechaSiguiente = clientes[y + 1].getFechaNacimiento();
            bool intercambiar = false;

            if(fechaActual.getAnio() != fechaSiguiente.getAnio())
                intercambiar = fechaActual.getAnio() < fechaSiguiente.getAnio();
            else if(fechaActual.getMes() != fechaSiguiente.getMes())
                intercambiar = fechaActual.getMes() < fechaSiguiente.getMes();
            else if(fechaActual.getDia() != fechaSiguiente.getDia())
                intercambiar = fechaActual.getDia() < fechaSiguiente.getDia();

            if(intercambiar){
                Clientes temp = clientes[y];
                clientes[y] = clientes[y + 1];
                clientes[y + 1] = temp;
            }
        }
    }

    for(int x = 0; x < cantidadActivos; x++){
        clientes[x].mostrar();
        if(x != cantidadActivos - 1)
            cout << "-----------------------------" << endl;
    }

    delete[] clientes;
    system("pause");

}


// CONSULTAS DE CLIENTES
void ClientesManager::consultarClientePorDni(){

    Clientes cliente;
    int cantidad = _repo.contarRegistros();
    string dni;

    limpiarPantalla();
    cout << "---- CONSULTANDO CLIENTE ----" << endl;
    cout << "Ingrese el DNI del cliente a consultar: " << endl;
    cin >> dni;

    for(int x = 0; x < cantidad; x++){
        cliente = _repo.leer(x);
        if(!cliente.getEliminado() && strcmp(cliente.getDni(), dni.c_str())==0){
            cliente.mostrar();
            system("pause");
            return;
        }
    }

    cout << "No existe un cliente con ese dni." << endl;
    system("pause");
}

void ClientesManager::consultarClientesPorAnioNacimiento(){

    Clientes cliente;
    int cantidad = _repo.contarRegistros();
    int anio;
    bool encontro = false;

    limpiarPantalla();
    cout << "---- CONSULTANDO CLIENTES POR ANIO DE NACIMIENTO ----" << endl;

    while(true){

        cout << "Ingrese el anio de nacimiento (0 para cancelar): ";
        cin >> anio;

        if(anio == 0){
            cout << "Operacion cancelada." << endl;
            system("pause");
            return;
        }

        Fecha fechaPrueba(1, 1, anio);
        if(cliente.setFechaNacimiento(fechaPrueba))
            break;

        cout << "Anio invalido." << endl;

    }

    for(int x = 0; x < cantidad; x++){
        cliente = _repo.leer(x);
        if(!cliente.getEliminado() && cliente.getFechaNacimiento().getAnio() == anio){

            if(encontro)
                cout << "-----------------------------" << endl;

            cliente.mostrar();
            encontro = true;

        }
    }

    if(!encontro)
        cout << "No hay clientes nacidos en ese anio." << endl;

    system("pause");
}



int ClientesManager::cargarClientesActivos(Clientes* clientes, int cantidadMax){

    Clientes cliente;
    int cantidadActivos = 0;

    for(int x = 0; x < cantidadMax; x++){
        cliente = _repo.leer(x);
        if(!cliente.getEliminado()){
            clientes[cantidadActivos] = cliente;
            cantidadActivos++;
        }
    }

    return cantidadActivos;
}

bool ClientesManager::hayClientes(){
    return _repo.contarRegistros() > 0;
}

bool ClientesManager::existeDni(const char* dni){

    Clientes cliente;
    int cantidad = _repo.contarRegistros();

    for(int x = 0; x < cantidad; x++){
        cliente = _repo.leer(x);
        if(!cliente.getEliminado() && strcmp(cliente.getDni(), dni)==0)
            return true;
    }

    return false;

}


