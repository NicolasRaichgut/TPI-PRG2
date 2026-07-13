#pragma once
#include <string>
#include "fecha.h"

class Remises{

  public:
      //CONSTRUCTORES
      Remises();
      Remises(std::string patente, std::string marca, std::string modelo, std::string dniChofer, Fecha fechaLanzamiento, int capacidadPasajeros);

      //SETTERS
      bool setPatente(std::string patente);
      bool setMarca(std::string marca);
      bool setModelo(std::string modelo);
      bool setDniChofer(std::string dniChofer);
      bool setFechaLanzamiento(Fecha fechaLanzamiento);
      bool setCapacidadPasajeros(int capacidadPasajeros);
      void eliminar();

      //GETTERS
      const char* getPatente() const;
      const char* getMarca() const;
      const char* getModelo() const;
      const char* getDniChofer() const;
      Fecha getFechaLanzamiento() const;
      int getCapacidadPasajeros() const;
      bool getEliminado() const;
      bool getValido() const;

      bool tieneChofer() const;
      bool cargar();
      void mostrar();

  private:
      char _patente[10];
      char _marca[20];
      char _modelo[20];
      char _dniChofer[9];
      Fecha _fechaLanzamiento;
      int _capacidadPasajeros;
      bool _eliminado;
      bool _valido;

};
