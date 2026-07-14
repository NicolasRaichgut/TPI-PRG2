#pragma once
#include "fecha.h"
#include <string>


class Viajes{

  public:
      //CONSTRUCTORES
      Viajes();
      Viajes(std::string id, std::string dniCliente, std::string dniChofer, Fecha fechaViaje);

      //GETTERS
      char* getId();
      char* getDniCliente();
      char* getDniChofer();
      Fecha getFechaViaje();
      bool getEliminado();
      bool getValido();

      //SETTERS
      bool setId(std::string id);
      bool setDniCliente(std::string dniCliente);
      bool setDniChofer(std::string dniChofer);
      bool setFechaViaje(Fecha fechaViaje);

      void eliminar();
      bool cargar();
      void mostrar();

  private:
      char _id[6];
      char _dniCliente[9];
      char _dniChofer[9];
      Fecha _fechaViaje;
      bool _eliminado;
      bool _valido;

};
