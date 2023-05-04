#include "../headers/Sala.h"

Sala::Sala() {}

Sala::~Sala() {}

std::string Sala::getId() const {
    return this->id;
}

int Sala::getTotalAssentos() const {
    return this->totalAssentos;
}

std::vector<Assento> Sala::getAssentos() const {
    return this->assentos;
}

Sala Sala::setId(const std::string& newId) {
    this->id = newId;
    return *this;
}

Sala Sala::setTotalAssentos(int newTotalAssentos) {
    this->totalAssentos = newTotalAssentos;
    return *this;
}

Sala Sala::setAssentos(const std::vector<Assento>& newAssentos) {
    this->assentos = newAssentos;
    return *this;
}