#include "../headers/Assento.h"

Assento::Assento() {}

Assento::~Assento() {}

std::string Assento::getId() const {
    return this->id;
}

bool Assento::isReservado() const {
    return this->Reservado;
}

Assento Assento::setId(const std::string& newId) {
    this->id = newId;
    return *this;
}

Assento Assento::setReservado(bool newReservado) {
    this->Reservado = newReservado;
    return *this;
}