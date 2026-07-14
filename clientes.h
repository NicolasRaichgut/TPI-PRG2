#pragma once
#include "personas.h"

class Clientes : public Personas{

  public:
      Clientes();
      Clientes(std::string dni, std::string nombre, std::string apellido, std::string numTelefono,
      std::string email, std::string direccion, Fecha fechaNacimiento);

};
