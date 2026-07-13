#pragma once
#include "menu.h"
#include "remisesManager.h"


class MenuRemisesListados : public Menu{

  public:
      MenuRemisesListados();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      RemisesManager _manager;

};
