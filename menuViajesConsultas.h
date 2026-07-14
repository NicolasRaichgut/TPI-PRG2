#pragma once
#include "menu.h"
#include "viajesManager.h"


class MenuViajesConsultas : public Menu{

  public:
      MenuViajesConsultas();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      ViajesManager _manager;

};
