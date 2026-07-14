#pragma once
#include <string>
#include "fecha.h"

class Personas{

  public:

      //CONSTRUCTORES
      Personas();
      Personas(std::string dni, std::string nombre, std::string apellido, std::string numTelefono,
      std::string email, std::string direccion, Fecha fechaNacimiento);

      //SETTERS
      bool setDni(std::string dni);
      bool setNombre(std::string nombre);
      bool setApellido(std::string apellido);
      bool setNumTelefono(std::string numTelefono);
      bool setEmail(std::string email);
      bool setDireccion(std::string direccion);
      bool setFechaNacimiento(Fecha fechaNacimiento);

      //GETTERS
      const char* getDni() const;
      const char* getNombre() const;
      const char* getApellido() const;
      const char* getNumTelefono() const;
      const char* getEmail() const;
      const char* getDireccion() const;
      Fecha getFechaNacimiento() const;
      bool getEliminado() const;
      bool getValido() const;

      bool cargar();
      void mostrar();
      void eliminar();

  protected:
      char _dni[9];
      char _nombre[30];
      char _apellido[30];
      char _numTelefono[12];
      char _email[50];
      char _direccion[50];
      Fecha _fechaNacimiento;
      bool _eliminado;
      bool _valido;

};
