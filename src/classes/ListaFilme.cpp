#include "../headers/ListaFilme.h"

ListaFilme::ListaFilme() : filmes() {}

ListaFilme::ListaFilme(const std::vector<Filme>& filmes) : filmes(filmes) {}

ListaFilme::~ListaFilme() {}

void ListaFilme::adicionarFilme(const Filme& filme) {
  for (auto it = filmes.begin(); it != filmes.end(); ++it) {
    if (it->getNome() == filme.getNome() && it->getData() == filme.getData()) {
      std::__throw_invalid_argument("ERROR: na função \"adcionarFilme\", tentativa de adcionar filmes iguais");
    }
  }
  filmes.push_back(filme);
}

void ListaFilme::removerFilme(const std::string& id) {
  for (auto it = filmes.begin(); it != filmes.end(); ++it) {
    if (it->getId() == id) {
      filmes.erase(it);
      break;
    }
  }
}

Filme* ListaFilme::buscarFilme(const std::string& id) {
  for (auto it = filmes.begin(); it != filmes.end(); ++it) {
    if (it->getId() == id) {
      return &(*it);
    }
  }
  return nullptr;
}

std::vector<Filme>& ListaFilme::getLista(){
  return this->filmes;
}