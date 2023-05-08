#include "../headers/ListaCliente.h"

ListaCliente::ListaCliente() {}
ListaCliente::ListaCliente(const std::vector<Cliente>& clientes) : clientes(clientes) {}

ListaCliente::~ListaCliente() {}

void ListaCliente::adicionarCliente(const Cliente& cliente) {
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