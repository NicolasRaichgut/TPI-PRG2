#pragma once
#include "viajesArchivo.h"
#include "clientesArchivo.h"
#include "choferesArchivo.h"

class ViajesManager{

  public:
      // Gestion de viajes
      void crearViaje();

      // Listados de viajes
      void listarViajes();
      void listarViajesOrdenadosPorFecha();

      // Consultas de viajes
      void consultarViajePorId();
      void consultarViajesPorDniCliente();
      void consultarViajesPorDniChofer();
      void consultarViajesPorMesAnio();

      bool hayViajes();

  private:
      ViajesArchivo _repo;
      ClientesArchivo _repoClientes;
      ChoferesArchivo _repoChoferes;
      bool existeCliente(const char* dniCliente);
      bool existeChofer(const char* dniChofer);
      bool existeViaje(const char* id);
      int cargarViajesActivos(Viajes* viajes, int cantidadMax);

};
