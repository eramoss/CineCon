#include "../headers/Cliente.h"


Cliente::Cliente(){}
Cliente::Cliente(const std::string& id,const std::string& nome,bool PCD,int idade){
  this->id = id;
  this->nome = nome;
  this->PCD = PCD;
  this->idade = idade;
}
Cliente::~Cliente(){}

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

Cliente Cliente::setId(const std::string& newId) {
  this->id = newId;
  return *this;
}

Cliente Cliente::setNome(const std::string& newNome) {
  this->nome = newNome;
  return *this;
}

Cliente Cliente::setPCD(bool newPCD) {
  this->PCD = newPCD;
  return *this;
}

Cliente Cliente::setIdade(int idade) {
  this->idade = idade;
  return *this;
}