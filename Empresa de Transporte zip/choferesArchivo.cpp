#include <iostream>
#include "choferesArchivo.h"
using namespace std;


bool ChoferesArchivo::guardar(const Choferes &obj){

    FILE *pFile = nullptr;
    pFile = fopen(_nombreArchivo, "ab");
    if(pFile == nullptr)
        return false;

    bool archivoCargado = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return archivoCargado;

}

bool ChoferesArchivo::guardar(const Choferes &obj, int indice){

    FILE *pFile = nullptr;
    pFile = fopen(_nombreArchivo, "rb+");
    if(pFile == nullptr)
        return false;

    fseek(pFile, indice * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return escribio;

}

Choferes ChoferesArchivo::leer(int indice){

    FILE *pFile = nullptr;
    Choferes chofer;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return chofer;

    fseek(pFile, indice * sizeof chofer, 0);
    fread(&chofer, sizeof chofer, 1, pFile);
    fclose(pFile);

    return chofer;

}

int ChoferesArchivo::contarRegistros(){

    FILE *pFile = nullptr;
    Choferes chofer;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return -1;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);
    fclose(pFile);

    return bytes / sizeof chofer;

}

bool ChoferesArchivo::bajaLogica(int indice){

    Choferes chofer;
    chofer = leer(indice);
    chofer.eliminar();
    bool registroEliminado = guardar(chofer, indice);

    return registroEliminado;

}


