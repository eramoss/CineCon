#include "../headers/Assento.h"

Assento::Assento() {}
Assento::Assento(const std::string& id,bool reservado) {
    this->id = id;
    this->reservado = reservado;
}

Assento::~Assento() {}

std::string Assento::getId() const {
    return this->id;
}

bool Assento::isReservado() const {
    return this->reservado;
}

Assento Assento::setId(const std::string& newId) {
    this->id = newId;
    return *this;
}

Assento Assento::setReservado(bool newReservado) {
    this->reservado = newReservado;
    return *this;
}