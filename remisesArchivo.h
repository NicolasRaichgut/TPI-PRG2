#pragma once
#include "remises.h"

class RemisesArchivo{

  public:
      bool guardar(const Remises &obj);
      bool guardar(const Remises &obj, int indice);
      Remises leer(int indice);
      int contarRegistros();
      bool bajaLogica(int indice);

  private:
      const char* _nombreArchivo = "remises.dat";

};
