#pragma once
#include "menu.h"
#include "choferesManager.h"


class MenuChoferesListados : public Menu{

  public:
      MenuChoferesListados();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      ChoferesManager _manager;

};
