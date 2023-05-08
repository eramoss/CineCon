#include "../headers/ListaSessao.h"
#include <algorithm>

ListaSessao::ListaSessao() : sessoes() {}

ListaSessao::~ListaSessao() {}

void ListaSessao::addSessao(const Sessao& sessao) {
  sessoes.push_back(sessao);
}

void ListaSessao::removeSessao(const std::string& id) {
  sessoes.erase(std::remove_if(sessoes.begin(), sessoes.end(), [id](const Sessao& sessao) {
    return sessao.getSala().getId() == id;
  }), sessoes.end());
}

Sessao ListaSessao::findSessao(const std::string& id) const {
  for (const Sessao& sessao : sessoes) {
    if (sessao.getSala().getId() == id) {
      return sessao;
    }
  }
  std::__throw_runtime_error("Session not found");
}

std::vector<Sessao> ListaSessao::getSessoes() const {
  return sessoes;
}