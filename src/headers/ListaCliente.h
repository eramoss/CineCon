#ifndef LISTACLIENTE_H
#define LISTACLIENTE_H

#include "Cliente.h"
#include <vector>

class ListaCliente {

public:
  ListaCliente();
  ListaCliente(const std::vector<Cliente>&);
  ~ListaCliente();

  void adicionarCliente(const Cliente& cliente);
  void removerCliente(const std::string& id);
  Cliente* buscarCliente(const std::string& id);
  std::vector<Cliente>& getClienteList();

private:
  std::vector<Cliente> clientes;

};

#endif
