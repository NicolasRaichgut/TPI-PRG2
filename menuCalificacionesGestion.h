#pragma once
#include "menu.h"
#include "calificacionesManager.h"


class MenuCalificacionesGestion : public Menu{

  public:
      MenuCalificacionesGestion();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      CalificacionesManager _manager;

};
