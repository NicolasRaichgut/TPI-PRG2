#include <iostream>
#include <cstring>
#include "calificaciones.h"
using namespace std;

//CONSTRUCTORES
Calificaciones::Calificaciones(){
    _id[0]='\0';
    _idViaje[0]='\0';
    _comentario[0]='\0';
    _puntaje=0;
    _eliminado=false;
    _valido=false;
}

Calificaciones::Calificaciones(string id, string idViaje, int puntaje, string comentario)
:_eliminado(0){

    if(setId(id) && setIdViaje(idViaje) && setPuntaje(puntaje) && setComentario(comentario))
        _valido = 1;
    else
        _valido = 0;

}


//GETTERS
const char* Calificaciones::getId() const{ return _id; }

const char* Calificaciones::getIdViaje() const{ return _idViaje; }

int Calificaciones::getPuntaje() const{ return _puntaje; }

const char* Calificaciones::getComentario() const{ return _comentario; }

bool Calificaciones::getEliminado() const{ return _eliminado; }

bool Calificaciones::getValido() const{ return _valido; }


//SETTERS
bool Calificaciones::setId(string id){

    if(id.length() <= 4 || id.length() >= 6)
        return 0;

    strcpy(_id, id.c_str());
    return 1;

}

bool Calificaciones::setIdViaje(string idViaje){

    if(idViaje.length() <= 4 || idViaje.length() >= 6)
        return 0;

    strcpy(_idViaje, idViaje.c_str());
    return 1;

}

bool Calificaciones::setPuntaje(int puntaje){

    if(puntaje < 1 || puntaje > 5)
        return 0;

    _puntaje = puntaje;
    return 1;

}

bool Calificaciones::setComentario(string comentario){

    if(comentario.length() < 3 || comentario.length() >= 120)
        return 0;

    strcpy(_comentario, comentario.c_str());
    return 1;

}


void Calificaciones::eliminar(){
    _eliminado=true;
}

bool Calificaciones::cargar(){

    int puntaje, opcion;
    string texto;

    while(true){

        cout << "Ingrese puntaje (1 a 5) (0 para cancelar): ";
        cin >> puntaje;

        if(puntaje == 0)
            return false;

        if(setPuntaje(puntaje))
            break;

        cout << "Puntaje invalido.\n";

    }

    while(true){

        cout << "Desea dejar un comentario?" << endl;
        cout << "1 - Si" << endl;
        cout << "2 - No" << endl;
        cout << "0 - Cancelar" << endl;
        cout << "Opcion: ";

        cin >> opcion;

        if(opcion == 0)
            return false;

        if(opcion == 1 || opcion == 2)
            break;

        cout << "Opcion invalida.\n";

    }

    cin.ignore();

    if(opcion == 1){

        while(true){

            cout << "Deje un comentario sobre su viaje (119 caracteres max) (0 para cancelar): " << endl;
            getline(cin, texto);

            if(texto == "0")
                return false;

            if(setComentario(texto))
                break;

            cout << "Comentario invalido.\n";

        }

    }
    else{

        _comentario[0] = '\0';

    }

    _valido = 1;
    _eliminado = 0;

    return true;

}

void Calificaciones::mostrar(){

    cout << "ID viaje: " << getId() << endl;
    cout << "---------------------" << endl;
    cout << "Puntaje: " << getPuntaje() << "/5" << endl;
    cout << "Comentario: ";
    if(_comentario[0] == '\0'){
        cout << "Este viaje no recibio un comentario." << endl;
    }else
        cout << "'" << getComentario() << "'." << endl;

}


