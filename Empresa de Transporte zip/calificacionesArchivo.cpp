#include <iostream>
#include "calificacionesArchivo.h"
using namespace std;


bool CalificacionesArchivo::guardar(const Calificaciones &obj){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "ab");
    if(pFile == nullptr)
        return false;

    bool guardado = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return guardado;

}

bool CalificacionesArchivo::guardar(const Calificaciones &obj, int indice){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "rb+");
    if(pFile == nullptr)
        return false;

    fseek(pFile, indice * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return escribio;

}

Calificaciones CalificacionesArchivo::leer(int indice){

    FILE *pFile = nullptr;
    Calificaciones calificacion;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return calificacion;

    fseek(pFile, indice * sizeof calificacion, 0);
    fread(&calificacion, sizeof calificacion, 1, pFile);

    fclose(pFile);
    return calificacion;

}

int CalificacionesArchivo::contarRegistros(){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return -1;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);

    fclose(pFile);

    return bytes / sizeof(Calificaciones);

}

bool CalificacionesArchivo::bajaLogica(int indice){

    Calificaciones calificacion;

    calificacion = leer(indice);
    calificacion.eliminar();

    bool registroEliminado = guardar(calificacion, indice);

    return registroEliminado;

}

