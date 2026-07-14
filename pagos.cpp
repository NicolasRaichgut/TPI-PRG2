#include <iostream>
#include <cstring>
#include "pagos.h"
using namespace std;

//CONSTRUCTORES
Pagos::Pagos(){
    _id[0]='\0';
    _idViaje[0]='\0';
    _metodoPago=0;
    _monto=0;
    _eliminado=false;
    _valido=false;
}

Pagos::Pagos(string id, string idViaje, int metodoPago, float monto, Fecha fechaPago)
:_eliminado(0){

    if(setId(id) && setIdViaje(idViaje) && setMetodoPago(metodoPago) && setMonto(monto) && setFechaPago(fechaPago))
        _valido = 1;
    else
        _valido = 0;

}


//GETTERS
const char* Pagos::getId() const{ return _id; }

const char* Pagos::getIdViaje() const{ return _idViaje; }

int Pagos::getMetodoPago() const{ return _metodoPago; }

float Pagos::getMonto() const{ return _monto; }

Fecha Pagos::getFechaPago() const{ return _fechaPago; }

bool Pagos::getEliminado() const{ return _eliminado; }

bool Pagos::getValido() const{ return _valido; }


//SETTERS
bool Pagos::setId(string id){

    if(id.length() <= 4 || id.length() >= 6)
        return 0;

    strcpy(_id, id.c_str());
    return 1;

}

bool Pagos::setIdViaje(string idViaje){

    if(idViaje.length() <= 4 || idViaje.length() >= 6)
        return 0;

    strcpy(_idViaje, idViaje.c_str());
    return 1;

}

bool Pagos::setMetodoPago(int metodoPago){

    if(metodoPago < 1 || metodoPago > 3)
        return 0;

    _metodoPago = metodoPago;
    return 1;

}

bool Pagos::setMonto(float monto){

    if(monto <= 0)
        return 0;

    _monto = monto;
    return 1;

}

bool Pagos::setFechaPago(Fecha fechaPago){

    if(fechaPago.getAnio() == 1)
        return 0;

    _fechaPago = fechaPago;
    return 1;

}



void Pagos::eliminar(){
    _eliminado = true;
}

bool Pagos::cargar(){

    float monto;
    int metodoPago, dia, mes, anio;
    Fecha fechaPago;

    while(true){

        cout << "Metodo de pago:" << endl;
        cout << "1 - Efectivo" << endl;
        cout << "2 - Tarjeta" << endl;
        cout << "3 - Transferencia" << endl;
        cout << "(0 para cancelar)" << endl;
        cout << "Opcion: ";

        cin >> metodoPago;

        if(metodoPago == 0)
            return false;

        if(setMetodoPago(metodoPago))
            break;

        cout << "Metodo de pago invalido.\n";

    }

    while(true){

        cout << "Ingrese el monto (0 para cancelar): ";
        cin >> monto;

        if(monto == 0)
            return false;

        if(setMonto(monto))
            break;

        cout << "Monto invalido.\n";

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

        fechaPago = Fecha(dia, mes, anio);

        if(setFechaPago(fechaPago))
            break;

        cout << "Fecha de pago invalida.\n";

    }
    
    _valido = 1;
    _eliminado = 0;

    return true;

}

void Pagos::mostrar(){

    cout << "ID pago: " << getId() << endl;
    cout << "---------------------" << endl;
    cout << "ID viaje: " << getIdViaje() << endl;
    cout << "Metodo de pago: ";
    switch(getMetodoPago()){
        case 1:
            cout << "Efectivo";
            break;
        case 2:
            cout << "Tarjeta";
            break;
        case 3:
            cout << "Transferencia";
            break;
    }
    cout << endl;
    cout << "Monto: " << getMonto() << endl;
    cout << "Fecha: ";
    getFechaPago().mostrar();
    cout << endl;

}


