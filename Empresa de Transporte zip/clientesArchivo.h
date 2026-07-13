#pragma once
#include "clientes.h"

class ClientesArchivo{

  public:
      bool guardar(const Clientes &obj);
      bool guardar(const Clientes &obj, int indice);
      Clientes leer(int indice);
      int contarRegistros();
      bool bajaLogica(int indice);

  private:
      const char* _nombreArchivo = "clientes.dat";

};
