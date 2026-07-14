#pragma once
#include "menu.h"
#include "menuRemisesGestion.h"
#include "menuRemisesListados.h"
#include "menuRemisesConsultas.h"


class MenuRemises : public Menu{

  public:
      MenuRemises();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      MenuRemisesGestion _menuGestion;
      MenuRemisesListados _menuListados;
      MenuRemisesConsultas _menuConsultas;

};

