#include "clientes.h"
using namespace std;

Clientes::Clientes():Personas(){}

Clientes::Clientes(string dni, string nombre, string apellido, string numTelefono,
string email, string direccion, Fecha fechaNacimiento)
:Personas(dni, nombre, apellido, numTelefono, email, direccion, fechaNacimiento){}
