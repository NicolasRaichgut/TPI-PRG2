#pragma once
#include "menu.h"
#include "choferesManager.h"


class MenuChoferesGestion : public Menu{

  public:
      MenuChoferesGestion();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      ChoferesManager _manager;

};
