#include "../headers/Cliente.h"


Cliente::Cliente(){}

std::string Cliente::getId() const {
  return this->id;
}

std::string Cliente::getNome() const {
  return this->nome;
}

bool Cliente::getPCD() const {
  return this->PCD;
}

bool Cliente::getMeio() const {
  return this->isMeio;
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

Cliente Cliente::setMeio(bool newMeio) {
  this->isMeio = newMeio;
  return *this;
}