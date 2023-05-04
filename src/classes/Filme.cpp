#include "../headers/Filme.h"

Filme Filme::setData(const DataFilmeParams & params){
  tm tempTM = {
    0, params.minuto, params.hora, // seconds , minutes , seconds
    params.dia, params.mes - 1, params.ano - 1900 // 1-based day , 0-based month // year since 1900
  };
  time_t dataFilme = mktime(&tempTM);
  tm * DataTM = localtime(&dataFilme);

  this->data = mktime(DataTM);
  return * this;
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
