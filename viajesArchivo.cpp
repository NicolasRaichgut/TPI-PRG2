#include <iostream>
#include "viajesArchivo.h"
using namespace std;


bool ViajesArchivo::guardar(const Viajes &obj){

    FILE *pFile = nullptr;
    pFile = fopen(_nombreArchivo, "ab");
    if(pFile == nullptr)
        return false;

    bool guardado = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return guardado;

}

bool ViajesArchivo::guardar(const Viajes &obj, int indice){

    FILE *pFile = nullptr;
    pFile = fopen(_nombreArchivo, "rb+");
    if(pFile == nullptr)
        return false;

    fseek(pFile, indice * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return escribio;

}

Viajes ViajesArchivo::leer(int indice){

    FILE *pFile = nullptr;
    Viajes viaje;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return viaje;

    fseek(pFile, indice * sizeof viaje, 0);
    fread(&viaje, sizeof viaje, 1, pFile);

    fclose(pFile);
    return viaje;

}

int ViajesArchivo::contarRegistros(){

    FILE *pFile = nullptr;
    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return -1;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);
    fclose(pFile);

    return bytes/sizeof(Viajes);

}

bool ViajesArchivo::bajaLogica(int indice){

    Viajes viaje;
    viaje = leer(indice);
    viaje.eliminar();
    bool registroEliminado = guardar(viaje, indice);
    return registroEliminado;

}


