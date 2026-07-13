#pragma once
#include "choferes.h"

class ChoferesArchivo{

  public:
      bool guardar(const Choferes &obj);
      bool guardar(const Choferes &obj, int indice);
      Choferes leer(int indice);
      int contarRegistros();
      bool bajaLogica(int indice);

  private:
      const char* _nombreArchivo = "choferes.dat";

};
