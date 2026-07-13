#pragma once
#include "menu.h"
#include "remisesManager.h"


class MenuRemisesConsultas : public Menu{

  public:
      MenuRemisesConsultas();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      RemisesManager _manager;

};
