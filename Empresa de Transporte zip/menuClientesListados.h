#pragma once
#include "menu.h"
#include "clientesManager.h"


class MenuClientesListados : public Menu{

  public:
      MenuClientesListados();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      ClientesManager _manager;

};
