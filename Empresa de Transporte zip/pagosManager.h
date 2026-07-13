#pragma once
#include "pagosArchivo.h"

class PagosManager{

  public:
      // Gestion de pagos
      void crearPago();

      // Listados de pagos
      void listarPagos();
      void listarPagosOrdenadosPorMonto();

      // Consultas de pagos
      void consultarPagoPorId();
      void consultarPagosPorMetodoPago();

      bool hayPagos();

  private:
      PagosArchivo _repo;
      bool existePago(const char* id);
      bool existeViaje(const char* idViaje);
      int cargarPagosActivos(Pagos* pagos, int cantidadMax);

};
