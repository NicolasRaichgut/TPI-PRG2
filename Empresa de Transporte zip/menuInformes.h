#pragma once
#include "menu.h"
#include "informesManager.h"

class MenuInformes : public Menu{

  public:
      MenuInformes();
      void mostrarOpciones() override;
      void ejecutarOpcion(int opcion) override;

  private:
      InformesManager _manager;

};
