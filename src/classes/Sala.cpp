#include "../headers/Sala.h"

Sala::Sala() {}
Sala::Sala(const std::string& id,int totalAssentos) {
    static int count = 0;
    this->id = id;
    this->totalAssentos = totalAssentos;
    for (int i = 0; i < totalAssentos; i++) {
        Assento * a = new Assento(std::to_string(count),false);
        this->assentos[i] = *a;
        count++;
    }
}

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