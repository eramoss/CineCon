#include "../headers/ListaFilme.h"

ListaFilme::ListaFilme() : filmes() {}

ListaFilme::ListaFilme(const std::vector<Filme>& filmes) : filmes(filmes) {}

ListaFilme::~ListaFilme() {}

void ListaFilme::adicionarFilme(const Filme& filme) {
  filmes.push_back(filme);
}

void ListaFilme::removerFilme(const std::string& nome) {
  for (auto it = filmes.begin(); it != filmes.end(); ++it) {
    if (it->getNome() == nome) {
      filmes.erase(it);
      break;
    }
  }
}

Filme* ListaFilme::buscarFilme(const std::string& nome) {
  for (auto it = filmes.begin(); it != filmes.end(); ++it) {
    if (it->getNome() == nome) {
      return &(*it);
    }
  }
  return nullptr;
}
