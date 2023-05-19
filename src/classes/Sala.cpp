#include "../headers/Sala.h"

//Construtor de Sala
Sala::Sala() {}
Sala::Sala(const std::string& id,int totalAssentos): assentos(totalAssentos) {
    this->id = id;
    this->totalAssentos = totalAssentos;
    for (int i = 0; i <= totalAssentos ; i++) {
        Assento * a = new Assento(std::to_string(i),false);
        this->assentos[i] = *a;
    }
}

Sala::~Sala() {}

std::string Sala::getId() const {
    return this->id;
}

unsigned int Sala::getTotalAssentos() const {
    return this->totalAssentos;
}

std::vector<Assento> Sala::getAssentos() const {
    return this->assentos;
}

Sala& Sala::setId(const std::string& newId) {
    this->id = newId;
    return *this;
}

Sala& Sala::setTotalAssentos(int newTotalAssentos) {
    this->totalAssentos = newTotalAssentos;
    return *this;
}

Sala& Sala::setAssentos(const std::vector<Assento>& newAssentos) {
    this->assentos = newAssentos;
    return *this;
}
