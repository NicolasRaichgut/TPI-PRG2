#pragma once
#include "choferesArchivo.h"

class ChoferesManager{

  public:
      // Gestion de choferes
      void crearChofer();
      void modificarChofer();
      void eliminarChofer();

      // Listados de choferes
      void listarChoferes();
      void listarChoferesOrdenadosPorNombre();
      void listarChoferesOrdenadosPorFechaNacimiento();

      // Consultas de choferes
      void consultarChoferPorDni();
      void consultarChoferesPorAnioNacimiento();

      bool hayChoferes();

  private:
      ChoferesArchivo _repo;
      bool existeDni(const char* dni);
      int cargarChoferesActivos(Choferes* choferes, int cantidadMax);

};
