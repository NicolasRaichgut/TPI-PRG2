#pragma once
#include "menu.h"
#include "viajesManager.h"


class MenuViajesListados : public Menu{

  public:
      MenuViajesListados();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      ViajesManager _manager;

};
