#pragma once
#include "menu.h"
#include "calificacionesManager.h"


class MenuCalificacionesListados : public Menu{

  public:
      MenuCalificacionesListados();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      CalificacionesManager _manager;

};
