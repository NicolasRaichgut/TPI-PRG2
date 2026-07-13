#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include "personas.h"
using namespace std;


//CONSTRUCTORES
Personas::Personas(){
    _dni[0]='\0';
    _nombre[0]='\0';
    _apellido[0]='\0';
    _numTelefono[0]='\0';
    _email[0]='\0';
    _direccion[0]='\0';
    _eliminado=0;
    _valido=0;
}

Personas::Personas(string dni, string nombre, string apellido, string numTelefono,
string email, string direccion, Fecha fechaNacimiento)
:_eliminado(0){
    if(setDni(dni) && setNombre(nombre) && setApellido(apellido) && setNumTelefono(numTelefono) && setDireccion(direccion)
       && setEmail(email) && setFechaNacimiento(fechaNacimiento))
        _valido = 1;

    else
        _valido = 0;

}


//SETTERS
void Personas::eliminar(){
    _eliminado = true;
}

bool Personas::setDni(string dni){

    if(dni.length() < 7 || dni.length() > 8)
        return 0;

    for(int x = 0; x < dni.length(); x++){
        if(dni[x] < '0' || dni[x] > '9')
            return 0;
    }

    strcpy(_dni, dni.c_str());
    return 1;

}

bool Personas::setNombre(string nombre){

    if(nombre.length() <= 2 || nombre.length() >= 30)
        return 0;

    for(int x = 0; x < nombre.length(); x++){
        if(nombre[x] >= '0' && nombre[x] <= '9')
            return 0;
    }

    strcpy(_nombre, nombre.c_str());
    return 1;

}

bool Personas::setApellido(string apellido){

    if(apellido.length() <= 2 || apellido.length() >= 30)
        return 0;

    for(int x = 0; x < apellido.length(); x++){
        if(apellido[x] >= '0' && apellido[x] <= '9')
            return 0;
    }

    strcpy(_apellido, apellido.c_str());
    return 1;

}

bool Personas::setNumTelefono(string numTelefono){

    if(numTelefono.length() < 8 || numTelefono.length() >= 12)
        return 0;

    strcpy(_numTelefono, numTelefono.c_str());
    return 1;

}

bool Personas::setDireccion(string direccion){

    if(direccion.length() <= 5 || direccion.length() >= 50)
        return 0;

    strcpy(_direccion, direccion.c_str());
    return 1;

}

bool Personas::setEmail(string email){

    if(email.length() <= 8 || email.length() >= 50)
        return 0;

    bool arroba = 0, punto = 0;

    for(int x = 0; x < email.length(); x++){
        if(email[x] == '@')
            arroba = 1;

        if(email[x] == '.')
            punto = 1;
    }

    if(!arroba || !punto)
        return 0;

    strcpy(_email, email.c_str());
    return 1;

}

bool Personas::setFechaNacimiento(Fecha fechaNacimiento){

    if(fechaNacimiento.getAnio() <= 1900)
        return 0;

    _fechaNacimiento = fechaNacimiento;
    return 1;

}


//GETTERS
const char* Personas::getDni() const{ return _dni; }

const char* Personas::getNombre() const{ return _nombre; }

const char* Personas::getApellido() const{ return _apellido; }

const char* Personas::getNumTelefono() const{ return _numTelefono; }

const char* Personas::getEmail() const{ return _email; }

const char* Personas::getDireccion() const{ return _direccion; }

Fecha Personas::getFechaNacimiento() const{ return _fechaNacimiento; }

bool Personas::getEliminado() const{ return _eliminado; }

bool Personas::getValido() const{ return _valido; }


bool Personas::cargar(){

    string nombre, apellido, numTelefono, email, direccion;
    int dia, mes, anio;
    Fecha fechaNacimiento;

    while(true){

        cout << "Ingrese el nombre (0 para cancelar): ";
        getline(cin, nombre);

        if(nombre == "0")
            return false;

        if(setNombre(nombre))
            break;

        cout << "Nombre invalido.\n";

    }

    while(true){

        cout << "Ingrese el apellido (0 para cancelar): ";
        getline(cin, apellido);

        if(apellido == "0")
            return false;

        if(setApellido(apellido))
            break;

        cout << "Apellido invalido.\n";

    }

    while(true){

        cout << "Ingrese el numero telefonico (9/11 ****-****)(0 para cancelar): ";
        getline(cin, numTelefono);

        if(numTelefono == "0")
            return false;

        if(setNumTelefono(numTelefono))
            break;

        cout << "Numero telefonico invalido.\n";

    }

    while(true){

        cout << "Ingrese el email (0 para cancelar): ";
        getline(cin, email);

        if(email == "0")
            return false;

        if(setEmail(email))
            break;

        cout << "Email invalido.\n";

    }

    while(true){

        cout << "Ingrese la direccion (0 para cancelar): ";
        getline(cin, direccion);

        if(direccion == "0")
            return false;

        if(setDireccion(direccion))
            break;

        cout << "Direccion invalida.\n";

    }

    while(true){

        cout << "Ingrese dia (0 para cancelar): ";
        cin >> dia;

        if(dia == 0)
            return false;

        cout << "Ingrese mes: ";
        cin >> mes;

        cout << "Ingrese anio: ";
        cin >> anio;

        fechaNacimiento = Fecha(dia, mes, anio);

        if(setFechaNacimiento(fechaNacimiento))
            break;

        cout << "Fecha de nacimiento invalida.\n";

    }

    _valido = 1;
    _eliminado = 0;
    cin.ignore();
    return true;
}

void Personas::mostrar(){

    cout << getNombre() << " " << getApellido() << endl;
    cout << "---------------------------------------" << endl;
    cout << "DNI: " << getDni() << endl;
    cout << "Numero telefonico: " << getNumTelefono() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Direccion: " << getDireccion() << endl;
    cout << "Fecha de nacimiento: ";
    getFechaNacimiento().mostrar();
    cout << endl;
}



