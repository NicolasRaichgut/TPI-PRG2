#pragma once
#include "menu.h"
#include "menuCalificacionesGestion.h"
#include "menuCalificacionesListados.h"
#include "menuCalificacionesConsultas.h"


class MenuCalificaciones : public Menu{

  public:
      MenuCalificaciones();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      MenuCalificacionesGestion _menuGestion;
      MenuCalificacionesListados _menuListados;
      MenuCalificacionesConsultas _menuConsultas;

};

