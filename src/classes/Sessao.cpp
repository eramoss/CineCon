#include "../headers/Sessao.h"
#include <iostream>
#include <assert.h>
#include <fmtmsg.h>

Sessao::Sessao() {}
Sessao::Sessao(const Filme &filme,const Sala &sala,float preco, std::string id): filme(filme), sala(sala), assentosDisponiveis(sala.getAssentos().size()), id(id){
    for (int i = 0; i < this->assentosDisponiveis.size(); i++) {
        assentosDisponiveis[i] = sala.getAssentos()[i];
    }
    this->preco = preco;
}


Sessao::~Sessao(){
}

Filme Sessao::getFilme() const {
    return this->filme;
}

Sala Sessao::getSala() const {
    return this->sala;
}

std::vector<Assento>& Sessao::getAssentoDisp() {
    return this->assentosDisponiveis;
}
std::string Sessao::getId() const {
    return this->id;
}

Sessao& Sessao::setFilme(const Filme& newFilme) {
    this->filme = newFilme;
    return *this;
}

Sessao& Sessao::setSala(const Sala& newSala) {
    this->sala = newSala;
    return *this;
}
Sessao& Sessao::setId(const std::string& newId) {
    this->id = newId;
    return *this;
}

Sessao& Sessao::setAssentosDisp(const std::vector<Assento>& newAssentosDisponiveis) {
    this->assentosDisponiveis = newAssentosDisponiveis;
    return *this;
}


void Sessao::rmvAssentoDisp(const std::string & id){
    for(auto it = assentosDisponiveis.begin(); it != assentosDisponiveis.end(); it++) {
        if(it->getId() == id){
            this->assentosDisponiveis.erase(it);
        }
    }
}

void Sessao::addAssentoDisp(const std::string & id){
    if(this->assentosDisponiveis.size() >= this->sala.getTotalAssentos()) {
        std::__throw_runtime_error("Assentos Disponiveis cheio, não pode inserir mais\n");
        return;
    }
    for(auto it = this->assentosDisponiveis.begin(); it != this->assentosDisponiveis.end() ; it++) {
        if(id == it->getId()){
            std::__throw_runtime_error("já existe um assento com esse id\n");
            return;
        }
    }
    for (auto it = this->assentosReservados.begin() ; it != this->assentosReservados.end() ; it++) {
        if(id == it->getId()){
            it->setReservado(false);
            assentosDisponiveis.push_back(*it);
            rmvAssentoReservado(id);
        }
    }  

}

Assento Sessao::findAssento(const std::string& id){
    for(auto it = this->assentosDisponiveis.begin(); it != this->assentosDisponiveis.end(); it++) {
        if(it->getId() == id){
            return *it;
        }
    }
    std::string errorMassage = "ERROR: assento não encontrado no uso da função \"findAssento\" Assento " + id + " não está na lista de disponiveis";
    std::__throw_runtime_error(errorMassage.c_str());
    return Assento();
}

void Sessao::rmvAssentoReservado(const std::string & id){
    for(auto it = this->assentosDisponiveis.begin(); it != this->assentosDisponiveis.end(); it++){
        if(it->getId() == id){
            this->assentosReservados.erase(it);
        }
    }
}

void Sessao::addAssentoReservado(const std::string & id){
    if(this->assentosReservados.size() >= this->sala.getTotalAssentos()) {
        std::__throw_runtime_error("Assentos Reservados cheio, não pode inserir mais\n");
        return;
    }
    for(auto it = this->assentosReservados.begin(); it != this->assentosReservados.end(); ++it) {
        if(id == it->getId()){
            std::__throw_runtime_error("já existe um assento com esse id reservado\n");
            return;
        }
    }
    for (auto it = this->assentosDisponiveis.begin(); it != this->assentosDisponiveis.end(); ++it) {
        if(id == it->getId()){
            it->setReservado(true);
            assentosReservados.push_back(*it);
            rmvAssentoDisp(id);
            return;
        }
    }  
}