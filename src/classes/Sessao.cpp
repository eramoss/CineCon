#include "../headers/Sessao.h"
#include <iostream>

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


void Sessao::rmvAssentoDisp(const std::string & id){
    for(std::size_t i = 0; i < this->assentosDisponiveis.size(); i++) {
        if(this->assentosDisponiveis[i].getId() == id){
            this->assentosDisponiveis[i].setReservado(true);
            this->assentosDisponiveis.erase(this->assentosDisponiveis.begin() + i);
        }
    }
}

void Sessao::addAssentoDisp(const std::string & id){
    if(this->assentosDisponiveis.size() == this->sala.getTotalAssentos()) {
        std::cout << "Assentos Disponiveis cheio, não pode inserir mais" << std::endl;
        return;
    }
    for(std::size_t i = 0; i < this->assentosDisponiveis.size(); i++) {
        if(id == this->assentosDisponiveis[i].getId()){
            std::cout << "já existe um assento com esse id";
            return;
        }
    }
    Assento* a = new Assento(id, false);
    this->assentosDisponiveis.push_back(*a);
}