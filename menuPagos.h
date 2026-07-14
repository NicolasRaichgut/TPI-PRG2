#pragma once
#include "menu.h"
#include "menuPagosGestion.h"
#include "menuPagosListados.h"
#include "menuPagosConsultas.h"


class MenuPagos : public Menu{

  public:
      MenuPagos();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      MenuPagosGestion _menuGestion;
      MenuPagosListados _menuListados;
      MenuPagosConsultas _menuConsultas;

};

