#include "../headers/Bilhete.h"
#include <iostream>

//Construtor de Bilhete
Bilhete::Bilhete(){

}
Bilhete::Bilhete(const std::string& id,double preco,const Sessao& sessao,const std::string& assentoId):sessao(sessao){
  this->id = id;
  this->preco = preco;
  this->dataCompra = time(NULL);
  this->dataValidade = this->getSessao().getFilme().getData();

  Sessao * s = const_cast<Sessao*>(&sessao);
  const Assento& newAssento = s->findAssento(assentoId);
  s->addAssentoReservado(assentoId);
  setAssento(newAssento);
}

Bilhete::~Bilhete(){}

std::string Bilhete::getId() const {
  return this->id;
}

double Bilhete::getPreco() const {
  return this->preco;
}

Sessao Bilhete::getSessao() const {
  return this->sessao;
}

Assento Bilhete::getAssento() const {
  return this->assento;
}

time_t Bilhete::getDataValidade() const {
  return this->dataValidade;
}

time_t Bilhete::getDataCompra() const {
  return this->dataCompra;
}

bool Bilhete::getIsMeio() const {
  return this->isMeio;
}


Bilhete& Bilhete::setId(const std::string& newId) {
  this->id = newId;
  return*this;
}

Bilhete& Bilhete::setPreco(double newPreco) {
  this->preco = newPreco;
  return*this;
}

Bilhete& Bilhete::setSessao(const Sessao& newSessao) {
  this->sessao = newSessao;
  return*this;
}

Bilhete& Bilhete::setAssento( const  Assento & newAssento) {
  Assento * assento = const_cast<Assento *>(&newAssento);
  if (assento->isReservado()){
    std::__throw_runtime_error("ERROR: na função setAssento, assento já reservado");
    return*this;
  }
  assento->setReservado(true);
  this->assento = *assento;
  return*this;
}

Bilhete& Bilhete::setIsMeio(bool isMeio){
  this->isMeio = isMeio;
  return*this;
}

Bilhete& Bilhete::Bilhete::setDataCompra(){
  this->dataCompra = time(NULL);
  return*this;
}

Bilhete& Bilhete::Bilhete::setDataValidade(){
  time_t dataFilme = this->sessao.getFilme().getData();
  this->dataValidade = dataFilme;
  return*this;
}
