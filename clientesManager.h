#pragma once
#include "clientesArchivo.h"

class ClientesManager{

  public:
      // Gestion de clientes
      void crearCliente();
      void modificarCliente();
      void eliminarCliente();

      // Listados de clientes
      void listarClientes();
      void listarClientesOrdenadosPorNombre();
      void listarClientesOrdenadosPorFechaNacimiento();

      // Consultas de clientes
      void consultarClientePorDni();
      void consultarClientesPorAnioNacimiento();

      bool hayClientes();

  private:
      ClientesArchivo _repo;
      bool existeDni(const char* dni);
      int cargarClientesActivos(Clientes* clientes, int cantidadMax);

};
