#pragma once
#include "menu.h"
#include "menuViajesGestion.h"
#include "menuViajesListados.h"
#include "menuViajesConsultas.h"


class MenuViajes : public Menu{

  public:
      MenuViajes();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      MenuViajesGestion _menuGestion;
      MenuViajesListados _menuListados;
      MenuViajesConsultas _menuConsultas;

};

