#include "../headers/Cliente.h"


Cliente::Cliente(){}
Cliente::Cliente(const std::string& id,const std::string& nome,bool PCD,int idade):Pessoa(id,nome){
  this->PCD = PCD;
  this->idade = idade;
}
Cliente::~Cliente(){
}

std::string Cliente::getId() const {
  return this->id;
}

std::string Cliente::getNome() const {
  return this->nome;
}

bool Cliente::getPCD() const {
  return this->PCD;
}

int Cliente::getIdade() const {
  return this->idade;
}
ListaCompra Cliente::getListaCompra() const {
  return this->listaCompra;
}

void Cliente::setId(const std::string& newId) {
  this->id = newId;

}

void Cliente::setNome(const std::string& newNome) {
  this->nome = newNome;

}

Cliente& Cliente::setPCD(bool newPCD) {
  this->PCD = newPCD;
  return *this;
}

Cliente& Cliente::setIdade(int idade) {
  this->idade = idade;
  return *this;
}