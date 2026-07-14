#pragma once
#include "menu.h"
#include "pagosManager.h"


class MenuPagosListados : public Menu{

  public:
      MenuPagosListados();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      PagosManager _manager;

};
