#include <iostream>
#include <string>
#include <cstring>
#include "viajes.h"
#include "pagosManager.h"
#include "calificacionesManager.h"
using namespace std;


//CONSTRUCTORES
Viajes::Viajes(){
    _id[0]='\0';
    _dniCliente[0]='\0';
    _dniChofer[0]='\0';
    _eliminado=false;
    _valido = false;
}

Viajes::Viajes(string id, string dniCliente, string dniChofer, Fecha fechaViaje)
:_eliminado(0){
    if(setId(id) && setDniCliente(dniCliente) && setDniChofer(dniChofer) && setFechaViaje(fechaViaje))
        _valido = 1;
    else
        _valido = 0;

}

//GETTERS
char* Viajes::getId(){ return _id; }

char* Viajes::getDniCliente(){ return _dniCliente; }

char* Viajes::getDniChofer(){ return _dniChofer; }

Fecha Viajes::getFechaViaje(){ return _fechaViaje; }

bool Viajes::getEliminado(){ return _eliminado; }

bool Viajes::getValido(){ return _valido; }


//SETTERS
bool Viajes::setId(string id){

    if(id.length() >= 6 || id.length() <= 4)
        return 0;

    strcpy(_id, id.c_str());
    return 1;

}

bool Viajes::setDniCliente(string dniCliente){

    if(dniCliente.length() < 7 || dniCliente.length() > 8)
        return 0;

    for(int x = 0; x < dniCliente.length(); x++){
        if(dniCliente[x] < '0' || dniCliente[x] > '9')
            return 0;
    }

    strcpy(_dniCliente, dniCliente.c_str());
    return 1;

}

bool Viajes::setDniChofer(string dniChofer){

    if(dniChofer.length() < 7 || dniChofer.length() > 8)
        return 0;

    for(int x = 0; x < dniChofer.length(); x++){
        if(dniChofer[x] < '0' || dniChofer[x] > '9')
            return 0;
    }

    strcpy(_dniChofer, dniChofer.c_str());
    return 1;

}

bool Viajes::setFechaViaje(Fecha fechaViaje){

    if(fechaViaje.getAnio() <= 2014)
        return 0;

    _fechaViaje = fechaViaje;
    return 1;

}


void Viajes::eliminar(){ _eliminado = true; }

bool Viajes::cargar(){
    int dia, mes, anio;
    Fecha fechaViaje;

    while(true){

        cout << "Ingrese dia (0 para cancelar): ";
        cin >> dia;

        if(dia == 0)
            return false;

        cout << "Ingrese mes: ";
        cin >> mes;

        cout << "Ingrese anio: ";
        cin >> anio;

        fechaViaje = Fecha(dia, mes, anio);

        if(setFechaViaje(fechaViaje))
            break;

        cout << "Fecha de nacimiento invalida.\n";

    }

    _valido = 1;
    _eliminado = 0;

}

void Viajes::mostrar(){
    cout << "ID del viaje: " << getId() << endl;
    cout << "-----------------------------" << endl;
    cout << "DNI del cliente: " << getDniCliente() << endl;
    cout << "DNI del chofer: " << getDniChofer() << endl;
    cout << "Fecha: ";
    getFechaViaje().mostrar();
    cout << endl;
}


