#pragma once
#include "fecha.h"
#include <string>

class Pagos{
  public:
      //CONSTRUCTORES
      Pagos();
      Pagos(std::string id, std::string idViaje, int metodoPago, float monto, Fecha fechaPago);

      //GETTERS
      const char* getId() const;
      const char* getIdViaje() const;
      int getMetodoPago() const;
      float getMonto() const;
      Fecha getFechaPago() const;
      bool getEliminado() const;
      bool getValido() const;

      //SETTERS
      bool setId(std::string id);
      bool setIdViaje(std::string idViaje);
      bool setMetodoPago(int metodoPago);
      bool setMonto(float monto);
      bool setFechaPago(Fecha fechaPago);

      void eliminar();
      bool cargar();
      void mostrar();

  private:
      char _id[6];
      char _idViaje[6];
      int _metodoPago;
      float _monto;
      Fecha _fechaPago;
      bool _eliminado;
      bool _valido;
};
