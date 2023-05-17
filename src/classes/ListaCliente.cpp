#include "../headers/ListaCliente.h"

ListaCliente::ListaCliente() {}
ListaCliente::ListaCliente(const std::vector<Cliente>& clientes) : clientes(clientes) {}

ListaCliente::~ListaCliente() {}

void ListaCliente::adicionarCliente(const Cliente& cliente) {
  for (auto it = clientes.begin(); it != clientes.end(); ++it) {
    if(it->getId() == cliente.getId()){
      std::__throw_invalid_argument("ERROR: na função \"adicionarCliente\", tentativa de adcionar cliente com id de outro existente");
    }
  }
  clientes.push_back(cliente);
}

void ListaCliente::removerCliente(const std::string& id) {
  for (auto it = clientes.begin(); it != clientes.end(); ++it) {
    if (it->getId() == id) {
      clientes.erase(it);
      break;
    }
  }
}

Cliente* ListaCliente::buscarCliente(const std::string& id) {
  for (auto it = clientes.begin(); it != clientes.end(); ++it) {
    if (it->getId() == id) {
      return &(*it);
    }
  }
  return nullptr;
}

std::vector<Cliente>& ListaCliente::getClienteList(){
  return this->clientes;
}