#include <iostream>
#include "remisesArchivo.h"
using namespace std;


bool RemisesArchivo::guardar(const Remises &obj){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "ab");
    if(pFile == nullptr)
        return false;

    bool guardado = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return guardado;

}

bool RemisesArchivo::guardar(const Remises &obj, int indice){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "rb+");
    if(pFile == nullptr)
        return false;

    fseek(pFile, indice * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return escribio;

}

Remises RemisesArchivo::leer(int indice){

    FILE *pFile = nullptr;
    Remises remis;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return remis;

    fseek(pFile, indice * sizeof remis, 0);
    fread(&remis, sizeof remis, 1, pFile);

    fclose(pFile);
    return remis;

}

int RemisesArchivo::contarRegistros(){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return -1;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);

    fclose(pFile);

    return bytes / sizeof(Remises);

}

bool RemisesArchivo::bajaLogica(int indice){

    Remises remis;

    remis = leer(indice);
    remis.eliminar();

    bool registroEliminado = guardar(remis, indice);

    return registroEliminado;

}


