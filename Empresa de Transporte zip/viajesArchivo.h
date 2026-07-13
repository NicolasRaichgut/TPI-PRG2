#pragma once
#include "viajes.h"

class ViajesArchivo{

  public:
      bool guardar(const Viajes &obj);
      bool guardar(const Viajes &obj, int indice);
      Viajes leer(int indice);
      int contarRegistros();
      bool bajaLogica(int indice);

  private:
      const char* _nombreArchivo = "viajes.dat";

};
