#include "../headers/Assento.h"

Assento::Assento() {}//Construtor do Assento
Assento::Assento(const std::string& id,bool reservado) {
    this->id = id;
    this->reservado = reservado;
}

Assento::~Assento() {}
//Função void para receber o valor do id do Assento
std::string Assento::getId() const {
    return this->id;
}
//Função void para verificar se o Assento está reservado, caso esteja reservado recebe o valor de 1, e se estiver vago recebe 0
bool Assento::isReservado() const {
    return this->reservado;
}
//Função set, para definir o valor do id do Assento
Assento& Assento::setId(const std::string& newId) {
    this->id = newId;
    return *this;
}
//Função set, para definir se o Assento está reservado
Assento& Assento::setReservado(bool newReservado) {
    this->reservado = newReservado;
    return *this;
}
