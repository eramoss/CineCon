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
    time_t INICIO_SESSAO = sessao.getFilme().getData();
    time_t TERMINO_SESSAO = sessao.getFilme().getData() + sessao.getFilme().getDuracao();
    time_t DATA_ITERATOR = it->getFilme().getData();

    if(sessao.getFilme().getData() == it->getFilme().getData() && sessao.getSala().getId() == it->getSala().getId()) {
        std::__throw_invalid_argument("ERROR: na função \"addSessao\", sessão tem mesmo horário e está na mesma sala de outra");  
        return; 
    }
    if(sessao.getSala().getId() == it->getSala().getId()){
      if(TERMINO_SESSAO > DATA_ITERATOR && DATA_ITERATOR > INICIO_SESSAO ) {
             std::__throw_invalid_argument("ERROR: na função \"addSessao\", sessão já ocorrendo nesta sala");
          }
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