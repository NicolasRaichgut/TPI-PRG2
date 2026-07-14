#include "choferes.h"
using namespace std;

Choferes::Choferes():Personas(){}

Choferes::Choferes(string dni, string nombre, string apellido, string numTelefono,
string email, string direccion, Fecha fechaNacimiento)
:Personas(dni, nombre, apellido, numTelefono, email, direccion, fechaNacimiento){}
