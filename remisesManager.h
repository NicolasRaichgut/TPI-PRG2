#pragma once
#include <string>
#include "remisesArchivo.h"
#include "choferesArchivo.h"

class RemisesManager{

  public:
      // Gestion de remises
      void crearRemis();
      void eliminarRemis();
      
      // Listados de remises
      void listarRemises();
      void listarRemisesOrdenadosPorFechaLanzamiento();
      void listarRemisesOrdenadosPorCapacidad();

      // Consultas de remises
      void consultarRemisPorPatente();
      void consultarRemisPorDniChofer();
      
      bool choferTieneRemis(char* dni);
      bool hayRemises();

  private:
      RemisesArchivo _repo;
      ChoferesArchivo _repoChoferes;

      bool existeRemis(const char* patente);
      bool existeChofer(const char* dniChofer);
      int cargarRemisesActivos(Remises* remises, int cantidadMax);

};
