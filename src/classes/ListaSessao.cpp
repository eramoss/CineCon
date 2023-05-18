#include "../headers/ListaSessao.h"
#include <algorithm>
#include <iostream>
#include <string>

ListaSessao::ListaSessao() : sessoes() {}
//Construtor de Lista de Sessões
ListaSessao::~ListaSessao() {}

//Função void para adicionar uma Sessão a Lista de Sessões, que recebe uma sessão inteira
void ListaSessao::addSessao(const Sessao& sessao) {
  if(sessoes.size() == 0){ //Verificação do tamanho de sessoes
    sessoes.push_back(sessao);//Se o tamanho for igual a 0, é adicionado a sessao a Lista de Sessões
    return;//É feito o return para que acabe a função
  }
  for( auto it = sessoes.begin(); it != sessoes.end(); ++it){//iterador recebe como inicio a instrução de begin de sessoes, e roda enquanto for diferente que o end de sessoes,e no fim é feito iterador que é somadao mais 1
    time_t INICIO_SESSAO = sessao.getFilme().getData();
    time_t TERMINO_SESSAO = sessao.getFilme().getData() + sessao.getFilme().getDuracao();
    time_t INICIO_ITERATOR = it->getFilme().getData();
    time_t TERMINO_ITERATOR = it->getFilme().getData() + it->getFilme().getDuracao();

    if(sessao.getFilme().getData() == it->getFilme().getData() && sessao.getSala().getId() == it->getSala().getId()) {//Verificação se o data do filme da sessão é igual a do iterador e se o id da sala da sessão é igual ao do iterador
        std::__throw_invalid_argument("ERROR: na função \"addSessao\", sessão tem mesmo horário e está na mesma sala de outra"); //Caso a condição seja verdadeira aparece a mensagem
        return; //É feito o return para que acabe a função
    }
    if(sessao.getSala().getId() == it->getSala().getId()){//Verificação do id da sala for igual ao id do iterador
      if(TERMINO_SESSAO > INICIO_ITERATOR && INICIO_ITERATOR > INICIO_SESSAO) { //Verificação se o termino da sessão é maior que o inicio do iterador e se o inicio do iterador é maior que o inicio da sessão
            std::string error_message = "Filme: "+ it->getFilme().getNome() + " tem inicio às: " +  std::to_string(localtime(&INICIO_ITERATOR)->tm_hour)  + ":" + std::to_string(localtime(&INICIO_ITERATOR)->tm_min) + ". E o filme inserido: " + sessao.getFilme().getNome() + " termina: " + std::to_string(localtime(&TERMINO_SESSAO)->tm_hour) + ":" + std::to_string(localtime(&TERMINO_SESSAO)->tm_min);//Caso seja verdade aparece a mensagem
            std::__throw_invalid_argument(error_message.c_str());
          }
        if(TERMINO_ITERATOR > INICIO_SESSAO && INICIO_SESSAO > INICIO_ITERATOR){ //Verificação se o termino do iterador é maior que o inicio da sessão e se o inicio da sessão é maior que o inicio do iterador
            std::string error_message = "Filme: "+ it->getFilme().getNome() + " termina às: " +  std::to_string(localtime(&TERMINO_ITERATOR)->tm_hour)  + ":" + std::to_string(localtime(&TERMINO_ITERATOR)->tm_min) + ". E o filme inserido: " + sessao.getFilme().getNome() + " começa: " + std::to_string(localtime(&INICIO_SESSAO)->tm_hour) + ":" + std::to_string(localtime(&INICIO_SESSAO)->tm_min); //Caso seja verdade aparece a mensagem
            std::__throw_invalid_argument(error_message.c_str());
        }
      }
  }

  sessoes.push_back(sessao);//Sessão adicionada a lista de sessões
}

//Função void de remoção de uma Sessão da lista de Sessões, que recebe um id
void ListaSessao::removeSessao(const std::string& id) {
  sessoes.erase(std::remove_if(sessoes.begin(), sessoes.end(), [id](const Sessao& sessao) {
    return sessao.getId() == id;
  }), sessoes.end());
}

//Função de busca de sessão da lista de Sessões, que recebe um id
Sessao* ListaSessao::findSessao(const std::string& id){
  for (Sessao& sessao : sessoes) {
    if (sessao.getFilme().getId() == id) {//Verificador de igualidade do id da sessão e do id recebido pela sessão
      return &sessao;//Caso a igualidade for confirmada, é feito o return da sessão
    }
  }
  std::__throw_invalid_argument("Erro na função findSessao, Sessão inexistente");
  return nullptr;
}

//Função da Lista de Sessões que retorna uma sessão
std::vector<Sessao>& ListaSessao::getSessoes() {
  return sessoes;
}
