#pragma once
#include "menu.h"
#include "clientesManager.h"


class MenuClientesGestion : public Menu{

  public:
      MenuClientesGestion();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      ClientesManager _manager;

};
