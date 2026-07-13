#pragma once
#include "menu.h"
#include "remisesManager.h"


class MenuRemisesGestion : public Menu{

  public:
      MenuRemisesGestion();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      RemisesManager _manager;

};
