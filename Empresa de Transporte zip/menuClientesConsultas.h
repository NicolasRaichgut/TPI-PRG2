#pragma once
#include "menu.h"
#include "clientesManager.h"


class MenuClientesConsultas : public Menu{

  public:
      MenuClientesConsultas();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      ClientesManager _manager;

};
