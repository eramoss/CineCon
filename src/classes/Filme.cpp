#include "../headers/Filme.h"

Filme Filme::setData(const DataFilmeParams & params){
    struct tm newTime;
    newTime.tm_hour = params.hora;
    newTime.tm_min = params.minuto;
    newTime.tm_mday = params.dia;
    newTime.tm_mon = params.mes - 1;  // months are 0-11
    newTime.tm_year = params.ano - 1900;  // years are since 1900
    newTime.tm_sec = 0;
    newTime.tm_isdst = -1;
    data = mktime(&newTime);
    return *this;
}


Filme::Filme() {}

Filme::~Filme() {}

std::string Filme::getNome() const {
    return this->nome;
}

bool Filme::getDublado() const {
    return this->isDublado;
}

bool Filme::get3D() const {
    return this->is3D;
}

time_t Filme::getData() const {
    return this->data;
}


Filme Filme::setNome(const std::string& newNome) {
    this->nome = newNome;
    return *this;
}

Filme Filme::setDublado(bool newDublado) {
    this->isDublado = newDublado;
    return *this;
}

Filme Filme::set3D(bool new3D) {
    this->is3D = new3D;
    return *this;
}
