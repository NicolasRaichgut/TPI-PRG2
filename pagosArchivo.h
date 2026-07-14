#pragma once
#include "pagos.h"

class PagosArchivo{

  public:
      bool guardar(const Pagos& obj);
      bool guardar(const Pagos& obj, int indice);
      Pagos leer(int indice);
      int contarRegistros();
      bool bajaLogica(int indice);

  private:
      const char* _nombreArchivo = "pagos.dat";

};
