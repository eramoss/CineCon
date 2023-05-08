#include "../headers/ListaSala.h"

ListaSala::ListaSala() {}

ListaSala::~ListaSala() {}

void ListaSala::addSala(const Sala &sala) {
  salas.push_back(sala);
}

Sala ListaSala::findSala(const std::string &id) {
  for (Sala &sala : salas) {
    if (sala.getId() == id) {
      return sala;
    }
  }
  std::__throw_invalid_argument("Sala não encontrada.");
}

void ListaSala::removeSala(const std::string &id) {
  for (auto it = salas.begin(); it != salas.end(); ++it) {
    if (it->getId() == id) {
      salas.erase(it);
      return;
    }
  }
  std::__throw_invalid_argument("Sala não encontrada.");
}

std::vector<Sala> ListaSala::getSalaList() const {
  return salas;
}