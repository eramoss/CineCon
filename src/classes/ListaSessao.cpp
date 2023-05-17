#include "../headers/ListaSessao.h"
#include <algorithm>
#include <iostream>
#include <string>

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
    time_t INICIO_ITERATOR = it->getFilme().getData();
    time_t TERMINO_ITERATOR = it->getFilme().getData() + it->getFilme().getDuracao();

    if(sessao.getFilme().getData() == it->getFilme().getData() && sessao.getSala().getId() == it->getSala().getId()) {
        std::__throw_invalid_argument("ERROR: na função \"addSessao\", sessão tem mesmo horário e está na mesma sala de outra");  
        return; 
    }
    if(sessao.getSala().getId() == it->getSala().getId()){
      if(TERMINO_SESSAO > INICIO_ITERATOR && INICIO_ITERATOR > INICIO_SESSAO) {
            std::string error_message = "Filme: "+ it->getFilme().getNome() + " tem inicio às: " +  std::to_string(localtime(&INICIO_ITERATOR)->tm_hour)  + ":" + std::to_string(localtime(&INICIO_ITERATOR)->tm_min) + ". E o filme inserido: " + sessao.getFilme().getNome() + " termina: " + std::to_string(localtime(&TERMINO_SESSAO)->tm_hour) + ":" + std::to_string(localtime(&TERMINO_SESSAO)->tm_min);             
            std::__throw_invalid_argument(error_message.c_str());
          }
        if(TERMINO_ITERATOR > INICIO_SESSAO && INICIO_SESSAO > INICIO_ITERATOR){
            std::string error_message = "Filme: "+ it->getFilme().getNome() + " termina às: " +  std::to_string(localtime(&TERMINO_ITERATOR)->tm_hour)  + ":" + std::to_string(localtime(&TERMINO_ITERATOR)->tm_min) + ". E o filme inserido: " + sessao.getFilme().getNome() + " começa: " + std::to_string(localtime(&INICIO_SESSAO)->tm_hour) + ":" + std::to_string(localtime(&INICIO_SESSAO)->tm_min);             
            std::__throw_invalid_argument(error_message.c_str());
        }
      }
  }
  
  sessoes.push_back(sessao);
}

void ListaSessao::removeSessao(const std::string& id) {
  sessoes.erase(std::remove_if(sessoes.begin(), sessoes.end(), [id](const Sessao& sessao) {
    return sessao.getId() == id;
  }), sessoes.end());
}

Sessao* ListaSessao::findSessao(const std::string& id)  {
  for (Sessao& sessao : sessoes) {
    if (sessao.getFilme().getId() == id) {
      return &sessao;
    }
  }
  std::__throw_runtime_error("Session not found");
}

std::vector<Sessao> ListaSessao::getSessoes() const {
  return sessoes;
}