#pragma once
#include "menu.h"
#include "pagosManager.h"


class MenuPagosGestion : public Menu{

  public:
      MenuPagosGestion();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      PagosManager _manager;

};
