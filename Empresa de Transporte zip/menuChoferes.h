#pragma once
#include "menu.h"
#include "menuChoferesGestion.h"
#include "menuChoferesListados.h"
#include "menuChoferesConsultas.h"


class MenuChoferes : public Menu{

  public:
      MenuChoferes();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      MenuChoferesGestion _menuGestion;
      MenuChoferesListados _menuListados;
      MenuChoferesConsultas _menuConsultas;

};

