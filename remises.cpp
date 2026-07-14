#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include "remises.h"
using namespace std;

//CONSTRUCTORES
Remises::Remises(){
    _patente[0]='\0';
    _marca[0]='\0';
    _modelo[0]='\0';
    _dniChofer[0]='\0';
    _capacidadPasajeros=0;
    _eliminado = false;
    _valido = false;
}

Remises::Remises(string patente, string marca, string modelo, string dniChofer, Fecha fechaLanzamiento, int capacidadPasajeros)
:_eliminado(0)
{
    if(setPatente(patente) && setMarca(marca) && setModelo(modelo) && setDniChofer(dniChofer) && setFechaLanzamiento(fechaLanzamiento)
       && setCapacidadPasajeros(capacidadPasajeros))
        _valido = 1;
    else
        _valido = 0;
}


//SETTERS
bool Remises::setPatente(string patente){

    if(patente.length() < 6 || patente.length() > 7)
        return 0;

    // ABC123
    if(patente.length() == 6){

        for(int x = 0; x < 3; x++){
            if(patente[x] < 'A' || patente[x] > 'Z')
                return 0;
        }

        for(int x = 3; x < 6; x++){
            if(patente[x] < '0' || patente[x] > '9')
                return 0;
        }

        strcpy(_patente, patente.c_str());
        return true;

    }

    // AB123CD
    if(patente.length() == 7){

        for(int x = 0; x < 2; x++){
            if(patente[x] < 'A' || patente[x] > 'Z')
                return 0;
        }

        for(int x = 2; x < 5; x++){
            if(patente[x] < '0' || patente[x] > '9')
                return 0;
        }

        for(int x = 5; x < 7; x++){
            if(patente[x] < 'A' || patente[x] > 'Z')
                return 0;
        }

        strcpy(_patente, patente.c_str());
        return true;
    }

}

bool Remises::setMarca(string marca){

    if(marca.length() <= 1 || marca.length() >= 20)
        return 0;

    strcpy(_marca, marca.c_str());
    return 1;

}

bool Remises::setModelo(string modelo){

    if(modelo.length() <= 1 || modelo.length() >= 20)
        return 0;

    strcpy(_modelo, modelo.c_str());
    return 1;

}

bool Remises::setDniChofer(string dniChofer){

    if(dniChofer.length() < 7 || dniChofer.length() > 8)
        return 0;

    for(int x = 0; x < dniChofer.length(); x++){
        if(dniChofer[x] < '0' || dniChofer[x] > '9')
            return 0;
    }

    strcpy(_dniChofer, dniChofer.c_str());
    return 1;

}

bool Remises::setFechaLanzamiento(Fecha fechaLanzamiento){

    if((fechaLanzamiento.getAnio() == 1) || fechaLanzamiento.getAnio() > 2026)
        return 0;

    _fechaLanzamiento = fechaLanzamiento;
    return 1;

}

bool Remises::setCapacidadPasajeros(int capacidadPasajeros){

    if(capacidadPasajeros < 1 || capacidadPasajeros > 7)
        return 0;

    _capacidadPasajeros = capacidadPasajeros;
    return 1;

}

void Remises::eliminar(){ _eliminado = true; }


//GETTERS
const char* Remises::getPatente() const{ return _patente; }

const char* Remises::getMarca() const{ return _marca; }

const char* Remises::getModelo() const{ return _modelo; }

const char* Remises::getDniChofer() const{ return _dniChofer; }

Fecha Remises::getFechaLanzamiento() const{ return _fechaLanzamiento; }

int Remises::getCapacidadPasajeros() const{ return _capacidadPasajeros; }

bool Remises::getEliminado() const{ return _eliminado; }

bool Remises::getValido() const{ return _valido; }



bool Remises::tieneChofer() const{
    if(_dniChofer[0]=='\0')
        return false;

    return true;
}

bool Remises::cargar(){

    string marca, modelo;
    int dia, mes, anio, capacidadPasajeros;
    Fecha fechaLanzamiento;

    while(true){

        cout << "Ingrese la marca (0 para cancelar): ";
        getline(cin, marca);

        if(marca == "0")
            return false;

        if(setMarca(marca))
            break;

        cout << "Marca invalida.\n";

    }

    while(true){

        cout << "Ingrese el modelo (0 para cancelar): ";
        getline(cin, modelo);

        if(modelo == "0")
            return false;

        if(setModelo(modelo))
            break;

        cout << "Modelo invalido.\n";

    }

    while(true){

        cout << "Ingrese dia de lanzamiento (0 para cancelar): ";
        cin >> dia;

        if(dia == 0)
            return false;

        cout << "Ingrese mes: ";
        cin >> mes;

        cout << "Ingrese anio: ";
        cin >> anio;

        fechaLanzamiento = Fecha(dia, mes, anio);

        if(setFechaLanzamiento(fechaLanzamiento))
            break;

        cout << "Fecha invalida.\n";

    }

    while(true){

        cout << "Ingrese la capacidad de pasajeros (0 para cancelar): ";
        cin >> capacidadPasajeros;

        if(capacidadPasajeros == 0)
            return false;

        if(setCapacidadPasajeros(capacidadPasajeros))
            break;

        cout << "Capacidad de pasajeros invalida.\n";

    }

    _valido = 1;
    _eliminado = 0;

    cin.ignore();

    return true;

}

void Remises::mostrar(){
    cout << "Patente: " << getPatente() << endl;
    cout << "---------------------------" << endl;
    cout << "Marca: " << getMarca() << endl;
    cout << "Modelo: " << getModelo() << endl;
    cout << "Fecha de lanzamiento del modelo: ";
    getFechaLanzamiento().mostrar();
    cout << endl;
    cout << "Capacidad: " << getCapacidadPasajeros() << " pasajeros" << endl;
    cout << "DNI del chofer: " << getDniChofer() << endl;
}

