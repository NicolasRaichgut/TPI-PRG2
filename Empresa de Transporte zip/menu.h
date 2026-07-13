#pragma once

class Menu{

  public:
      //CONSTRUCTOR
      Menu(const char* titulo, int cantidadOpciones);

      //FUNCIONES
      void run();
      void mostrarEncabezado();
      int seleccionarOpcion();

      //FUNCIONES HIJAS
      virtual void mostrarOpciones()=0;
      virtual void ejecutarOpcion(int opcion)=0;

  protected:
      char _titulo[50];
      int _cantidadOpciones;

};

