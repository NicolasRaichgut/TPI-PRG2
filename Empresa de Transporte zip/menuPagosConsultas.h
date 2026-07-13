#pragma once
#include "menu.h"
#include "pagosManager.h"


class MenuPagosConsultas : public Menu{

  public:
      MenuPagosConsultas();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      PagosManager _manager;

};
