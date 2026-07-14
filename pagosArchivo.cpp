#include <iostream>
#include "pagosArchivo.h"
using namespace std;

bool PagosArchivo::guardar(const Pagos &obj){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "ab");
    if(pFile == nullptr)
        return false;

    bool guardado = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return guardado;

}

bool PagosArchivo::guardar(const Pagos &obj, int indice){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "rb+");
    if(pFile == nullptr)
        return false;

    fseek(pFile, indice * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return escribio;

}

Pagos PagosArchivo::leer(int indice){

    FILE *pFile = nullptr;
    Pagos pago;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return pago;

    fseek(pFile, indice * sizeof pago, 0);
    fread(&pago, sizeof pago, 1, pFile);

    fclose(pFile);
    return pago;

}

int PagosArchivo::contarRegistros(){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return -1;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);

    fclose(pFile);

    return bytes / sizeof(Pagos);

}

bool PagosArchivo::bajaLogica(int indice){

    Pagos pago;

    pago = leer(indice);
    pago.eliminar();

    bool registroEliminado = guardar(pago, indice);

    return registroEliminado;

}
