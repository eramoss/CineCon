#include "../headers/Sessao.h"

Sessao::Sessao() {}
Sessao::Sessao(const Filme &filme,const Sala &sala): filme(filme), sala(sala), assentosDisponiveis(sala.getAssentos()) {}


Sessao::~Sessao(){
}

Filme Sessao::getFilme() const {
    return this->filme;
}

Sala Sessao::getSala() const {
    return this->sala;
}

std::vector<Assento> Sessao::getAssento() const {
    return this->assentosDisponiveis;
}

Sessao Sessao::setFilme(const Filme& newFilme) {
    this->filme = newFilme;
    return *this;
}

Sessao Sessao::setSala(const Sala& newSala) {
    this->sala = newSala;
    return *this;
}

Sessao Sessao::setAssentosDisp(const std::vector<Assento>& newAssentosDisponiveis) {
    this->assentosDisponiveis = newAssentosDisponiveis;
    return *this;
}