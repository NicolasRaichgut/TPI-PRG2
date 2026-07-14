#pragma once
#include "calificacionesArchivo.h"
#include "viajes.h"

class CalificacionesManager{

  public:
      // Gestion de calificaciones
      void crearCalificacion();

      // Listados de calificaciones
      void listarCalificaciones();
      void listarCalificacionesOrdenadasPorPuntaje();

      // Consultas de calificaciones
      void consultarCalificacionPorId();

      bool hayCalificaciones();

  private:
      CalificacionesArchivo _repo;
      bool existeCalificacion(const char* id);
      bool existeViaje(const char* idViaje);
      int cargarCalificacionesActivas(Calificaciones* calificaciones, int cantidadMax);

};
