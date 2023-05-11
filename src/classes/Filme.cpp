#include "../headers/Filme.h"

/*
@param sequência Hora, Minuto, Dia, Mes, Ano;
@param exemplo setData({15 ,30 ,2 ,6 ,2023});
@param significado isso significa que este filme passará às 3 e 30 da tarde no dia 2 do 6 em 2023
*/
Filme& Filme::setData(const DataFilmeParams & params){
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


Filme::Filme(){

}


Filme::Filme(const std::string& id,const std::string& nome, bool isDublado, bool is3d,time_t duracao, const DataFilmeParams& data){
    this->id = id;
    this->nome = nome;
    this->isDublado = isDublado;
    this->is3D = is3d;
    this->duracao = duracao;
    setData(data);
}


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
time_t Filme::getDuracao() const {
    return this->duracao;
}
std::string Filme::getId() const {
    return this->id;
}

Filme& Filme::setNome(const std::string& newNome) {
    this->nome = newNome;
    return *this;
}

Filme& Filme::setDublado(bool newDublado) {
    this->isDublado = newDublado;
    return *this;
}

Filme& Filme::set3D(bool new3D) {
    this->is3D = new3D;
    return *this;
}
Filme& Filme::setDuracao(time_t newDuracao) {
    this->duracao = newDuracao;
    return *this;
}
Filme& Filme::setId(const std::string& id) {
    this->id = id;
    return *this;
}