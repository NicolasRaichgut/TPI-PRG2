#include <iostream>
#include "clientesArchivo.h"
#include"Clientes.h"
using namespace std;


bool ClientesArchivo::guardar(const Clientes &obj){

    FILE *pFile = nullptr;

    pFile = fopen(_nombreArchivo, "ab");
    if(pFile == nullptr)
        return false;

    bool guardado = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return guardado;

}

bool ClientesArchivo::guardar(const Clientes &obj, int indice){

    FILE *pFile = nullptr;
    pFile = fopen(_nombreArchivo, "rb+");
    if(pFile == nullptr)
        return false;

    fseek(pFile, indice * sizeof obj, 0);
    bool escribio = fwrite(&obj, sizeof obj, 1, pFile);
    fclose(pFile);

    return escribio;

}

Clientes ClientesArchivo::leer(int indice){

    FILE *pFile = nullptr;
    Clientes cliente;

    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return cliente;

    fseek(pFile, indice * sizeof cliente, 0);
    fread(&cliente, sizeof cliente, 1, pFile);

    fclose(pFile);
    return cliente;

}

int ClientesArchivo::contarRegistros(){

    FILE *pFile = nullptr;
    pFile = fopen(_nombreArchivo, "rb");
    if(pFile == nullptr)
        return -1;

    fseek(pFile, 0, SEEK_END);
    int bytes = ftell(pFile);
    fclose(pFile);

    return bytes/sizeof(Clientes);

}

bool ClientesArchivo::bajaLogica(int indice){

    Clientes cliente;
    cliente = leer(indice);
    cliente.eliminar();
    bool registroEliminado = guardar(cliente, indice);

    return registroEliminado;

}
