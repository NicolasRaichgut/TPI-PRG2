#pragma once
#include "clientesArchivo.h"
#include "choferesArchivo.h"
#include "viajesArchivo.h"
#include "remisesArchivo.h"
#include "pagosArchivo.h"
#include "calificacionesArchivo.h"

class InformesManager{

  public:

      void informeClienteQueMasGasto();
      void informeChoferQueMasRecaudo();
      void informeRemisMasUtilizado();
      void informeMetodoPagoMasUtilizado();
      void informeRecaudacionTotalEntreFechas();
      void informePromedioCalificacionPorChofer();
      void informeTop5ChoferesConMasViajes();
      void informeTop5ClientesConMasViajes();

  private:

      ClientesArchivo _repoClientes;
      ChoferesArchivo _repoChoferes;
      ViajesArchivo _repoViajes;
      RemisesArchivo _repoRemises;
      PagosArchivo _repoPagos;
      CalificacionesArchivo _repoCalificaciones;

      bool buscarClientePorDni(const char* dni, Clientes& cliente);
      bool buscarChoferPorDni(const char* dni, Choferes& chofer);
      bool buscarViajeActivoPorId(const char* id, Viajes& viaje);
      bool fechaEnRango(Fecha fecha, Fecha desde, Fecha hasta);
      int fechaAEntero(Fecha fecha);
      const char* nombreMetodoPago(int metodo);

};

