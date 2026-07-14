#pragma once
#include "menuClientes.h"
#include "menuChoferes.h"
#include "menuViajes.h"
#include "menuRemises.h"
#include "menuPagos.h"
#include "menuCalificaciones.h"
#include "menuInformes.h"

class App : public Menu{

  public:
    App();
    void mostrarOpciones() override;
    void ejecutarOpcion(int opcion) override;

  private:
    MenuClientes _menuClientes;
    MenuChoferes _menuChoferes;
    MenuViajes _menuViajes;
    MenuRemises _menuRemises;
    MenuPagos _menuPagos;
    MenuCalificaciones _menuCalificaciones;
    MenuInformes _menuInformes;

};
