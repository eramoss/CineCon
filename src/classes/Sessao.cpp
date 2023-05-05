#include "../headers/Sessao.h"
#include <iostream>

Sessao::Sessao() {}
Sessao::Sessao(const Filme &filme,const Sala &sala): filme(filme), sala(sala), assentosDisponiveis(sala.getAssentos().size()) {
    for (int i = 0; i < this->assentosDisponiveis.size(); i++) {
        assentosDisponiveis[i] = sala.getAssentos()[i];
    }
}


Sessao::~Sessao(){
}

Filme Sessao::getFilme() const {
    return this->filme;
}

Sala Sessao::getSala() const {
    return this->sala;
}

std::vector<Assento> Sessao::getAssentoDisp() const {
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
            this->assentosReservados.push_back(this->assentosDisponiveis[i]);
            this->assentosDisponiveis.erase(this->assentosDisponiveis.begin() + i);
        }
    }
}

void Sessao::addAssentoDisp(const std::string & id){
    if(this->assentosDisponiveis.size() >= this->sala.getTotalAssentos()) {
        std::cout << "Assentos Disponiveis cheio, não pode inserir mais\n" << std::endl;
        return;
    }
    for(std::size_t i = 0; i < this->assentosDisponiveis.size(); i++) {
        if(id == this->assentosDisponiveis[i].getId()){
            std::cout << "já existe um assento com esse id\n";
            return;
        }
    }
    for (std::size_t i = 0; i < this->assentosReservados.size(); i++) {
        if(id == this->assentosReservados[i].getId()){
            assentosDisponiveis.push_back(this->assentosReservados[i]);
            rmvAssentoReservado(id);
        }
    }  

}

Assento Sessao::findAssento(const std::string& id){
    for(std::size_t i = 0; i < this->assentosDisponiveis.size(); i++) {
        if(this->assentosDisponiveis[i].getId() == id){
            return this->assentosDisponiveis[i];
        }
    }
    std::cout << "ERROR: assento não encontrado no uso da função \"findAssento\"" << std::endl;
    return Assento();
}

void Sessao::rmvAssentoReservado(const std::string & id){
    for(std::size_t i = 0; i < this->assentosReservados.size(); i++) {
        if(this->assentosReservados[i].getId() == id){
            this->assentosReservados[i].setReservado(false);
            this->assentosDisponiveis.push_back(this->assentosReservados[i]);
            this->assentosReservados.erase(this->assentosReservados.begin() + i);
        }
    }
}

void Sessao::addAssentoReservado(const std::string & id){
    if(this->assentosReservados.size() >= this->sala.getTotalAssentos()) {
        std::cout << "Assentos Reservados cheio, não pode inserir mais\n" << std::endl;
        return;
    }
    for(std::size_t i = 0; i < this->assentosReservados.size(); i++) {
        if(id == this->assentosReservados[i].getId()){
            std::cout << "já existe um assento com esse id reservado\n";
            return;
        }
    }
    for (std::size_t i = 0; i < this->assentosDisponiveis.size(); i++) {
        if(id == this->assentosDisponiveis[i].getId()){
            assentosReservados.push_back(this->assentosDisponiveis[i]);
            rmvAssentoDisp(id);
        }
    }  
}