#pragma once
#include "menu.h"
#include "calificacionesManager.h"


class MenuCalificacionesConsultas : public Menu{

  public:
      MenuCalificacionesConsultas();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      CalificacionesManager _manager;

};
