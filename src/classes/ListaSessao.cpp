#include "../headers/ListaSessao.h"
#include <algorithm>
#include <iostream>

ListaSessao::ListaSessao() : sessoes() {}

ListaSessao::~ListaSessao() {}

void ListaSessao::addSessao(const Sessao& sessao) {
  if(sessoes.size() == 0) {
    sessoes.push_back(sessao);
    return;
  }
  for ( auto it = sessoes.begin(); it != sessoes.end(); ++it){
    if(sessao.getFilme().getData() == it->getFilme().getData() && sessao.getSala().getId() == it->getSala().getId()) {
        std::__throw_invalid_argument("ERROR: na função \"addSessao\", sessão tem mesmo horário e está na mesma sala de outra");  
        return; 
    }
  }
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