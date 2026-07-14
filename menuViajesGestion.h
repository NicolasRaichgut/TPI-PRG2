#pragma once
#include "menu.h"
#include "viajesManager.h"


class MenuViajesGestion : public Menu{

  public:
      MenuViajesGestion();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      ViajesManager _manager;

};
