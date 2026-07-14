#pragma once
#include "personas.h"

class Choferes:public Personas{
public:
    Choferes();
    Choferes(std::string dni, std::string nombre, std::string apellido, std::string numTelefono,
    std::string email, std::string direccion, Fecha fechaNacimiento);
};
