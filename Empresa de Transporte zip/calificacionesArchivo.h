#pragma once
#include "calificaciones.h"

class CalificacionesArchivo{

  public:
      bool guardar(const Calificaciones &obj);
      bool guardar(const Calificaciones &obj, int indice);
      Calificaciones leer(int indice);
      int contarRegistros();
      bool bajaLogica(int indice);

  private:
      const char* _nombreArchivo = "calificaciones.dat";

};
