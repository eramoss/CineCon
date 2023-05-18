#include "../headers/ListaSala.h"

ListaSala::ListaSala(): salas() {}

ListaSala::~ListaSala() {}

void ListaSala::addSala(const Sala &sala) {
  for (auto it = salas.begin(); it != salas.end(); ++it) {
    if (it->getId() == sala.getId()) {
      std::__throw_invalid_argument("ERROR: na função \"addSala\", tentativa de adcionar nova sala com mesmo id de outra");
    }
  }
  salas.push_back(sala);
}

Sala* ListaSala::findSala(const std::string &id) {
  for (auto it = salas.begin(); it != salas.end(); ++it) {
    if (it->getId() == id) {
      return &(*it);
    }
  }
  return nullptr;
}

void ListaSala::removeSala(const std::string &id) {
  for (auto it = salas.begin(); it != salas.end(); ++it) {
    if (it->getId() == id) {
      salas.erase(it);
      break;
    }
  }
}

std::vector<Sala>& ListaSala::getSalaList()  {
  return salas;
}