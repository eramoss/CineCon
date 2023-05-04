#include "../headers/Bilhete.h"


Bilhete::Bilhete(){

}
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
Cliente Bilhete::getCliente() const {
  return this->cliente;
}


Bilhete Bilhete::setId(const std::string& newId) {
  this->id = newId;
  return*this;
}

Bilhete Bilhete::setPreco(double newPreco) {
  this->preco = newPreco;
  return*this;
}

Bilhete Bilhete::setSessao(const Sessao& newSessao) {
  this->sessao = newSessao;
  return*this;
}

Bilhete Bilhete::setAssento(const Assento& newAssento) {
  this->assento = newAssento;
  return*this;
}
Bilhete Bilhete::setCliente(const Cliente& newCliente) {
  this->cliente = newCliente;
  return*this;
}


Bilhete Bilhete::Bilhete::setDataCompra(){
  this->dataCompra = time(NULL);
  return*this;
}

Bilhete Bilhete::Bilhete::setDataValidade(){
  time_t dataFilme = this->sessao.getFilme().getData();
  this->dataValidade = dataFilme;
  return*this;
}