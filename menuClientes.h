#pragma once
#include "menu.h"
#include "menuClientesGestion.h"
#include "menuClientesListados.h"
#include "menuClientesConsultas.h"

class MenuClientes : public Menu{

  public:
      MenuClientes();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      MenuClientesGestion _menuGestion;
      MenuClientesListados _menuListados;
      MenuClientesConsultas _menuConsultas;

};



