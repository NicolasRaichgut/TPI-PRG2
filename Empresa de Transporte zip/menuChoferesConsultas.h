#pragma once
#include "menu.h"
#include "choferesManager.h"


class MenuChoferesConsultas : public Menu{

  public:
      MenuChoferesConsultas();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      ChoferesManager _manager;

};
