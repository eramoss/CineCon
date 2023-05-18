#include "../headers/Sessao.h"
#include <iostream>
#include <assert.h>

//Construtor de Sessão
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

//Função para remover o Assento Disponível, que recebe um id
void Sessao::rmvAssentoDisp(const std::string & id){
    for(auto it = assentosDisponiveis.begin(); it != assentosDisponiveis.end(); it++) { //iterador recebe como inicio a instrução de begin de assentosDisponiveis, e roda enquanto for diferente que o end de assentosDisponiveis,e no fim é feito iterador que é somadao mais 1
        if(it->getId() == id){ //Verificação de igualidade do id do iterador com o id recebeido pela função
            this->assentosDisponiveis.erase(it);//Caso a igualidade for confirmada o iterador é removido
        }
    }
}

//Função para adicionar um Assento Disponível, que recebe um id
void Sessao::addAssentoDisp(const std::string & id){
    if(this->assentosDisponiveis.size() >= this->sala.getTotalAssentos()) { //Verificação de se o tamanho de assentos Disponíveis é maior ou igual que o número Total de Assentos
        std::__throw_runtime_error("Assentos Disponiveis cheio, não pode inserir mais\n");//Caso a verificação de verdadeira, a mensagem aparece
        return;//É feito o return para que acabe a função
    }
    for(auto it = this->assentosDisponiveis.begin(); it != this->assentosDisponiveis.end() ; it++) {//iterador recebe como inicio a instrução de begin de assentos Disponiveis, e roda enquanto for diferente que o end de assentos Disponiveis,e no fim é feito iterador que é somadao mais 1
        if(id == it->getId()){//Verificação de igualidade do id do iterador com o id recebeido pela função
            std::__throw_runtime_error("já existe um assento com esse id\n");//Caso a verificação de verdadeira, a mensagem aparece
            return;//É feito o return para que acabe a função
        }
    }
    for (auto it = this->assentosReservados.begin() ; it != this->assentosReservados.end() ; it++) {//iterador recebe como inicio a instrução de begin de assentos Reservados, e roda enquanto for diferente que o end de assentos Reservados,e no fim é feito iterador que é somadao mais 1
        if(id == it->getId()){//Verificação de igualidade do id do iterador com o id recebeido pela função
            it->setReservado(false);
            assentosDisponiveis.push_back(*it);//Adiciona o iterador aos assentos disponíveis
            rmvAssentoReservado(id);//Remove o iterador dos assentos reservados
        }
    }

}

//Função para econtrar um Assento Disponíveis, que recebe um id
Assento Sessao::findAssento(const std::string& id){
    for(auto it = this->assentosDisponiveis.begin(); it != this->assentosDisponiveis.end(); it++) {//iterador recebe como inicio a instrução de begin de assentos Disponiveis, e roda enquanto for diferente que o end de assentos Disponiveis,e no fim é feito iterador que é somadao mais 1
        if(it->getId() == id){//Verificação de igualidade do id do iterador com o id recebeido pela função
            return *it;//Caso a verificação seja verdadeira, é feito o return do iterador
        }
    }
    std::string errorMassage = "ERROR: assento não encontrado no uso da função \"findAssento\" Assento " + id + " não está na lista de disponiveis";//Caso a verificação seja falsa, aparece essa mensagem
    std::__throw_runtime_error(errorMassage.c_str());
    return Assento();//É feito o return do Assento
}

//Função void que remove o Assento Reservado, que recebe o id
void Sessao::rmvAssentoReservado(const std::string & id){
    for(auto it = this->assentosDisponiveis.begin(); it != this->assentosDisponiveis.end(); it++){//iterador recebe como inicio a instrução de begin de assentos Disponiveis, e roda enquanto for diferente que o end de assentos Disponiveis,e no fim é feito iterador que é somadao mais 1
        if(it->getId() == id){//Verificação de igualidade do id do iterador com o id recebeido pela função
            this->assentosReservados.erase(it);//Caso a verificação de verdadeira, o assento reservado é removido
        }
    }
}

//Função void que adiciona um assento reservado, e recebe um id
void Sessao::addAssentoReservado(const std::string & id){
    if(this->assentosReservados.size() >= this->sala.getTotalAssentos()) {//Verificação de se o tamanho de assentos Reservados é maior ou igual que o número Total de Assentos
        std::__throw_runtime_error("Assentos Reservados cheio, não pode inserir mais\n");//Caso a verificação seja falsa, aparece essa mensagem
        return;//É feito o return para que acabe a função
    }
    for(auto it = this->assentosReservados.begin(); it != this->assentosReservados.end(); ++it) {//iterador recebe como inicio a instrução de begin de assentos Reservados, e roda enquanto for diferente que o end de assentos Reservados,e no fim é feito iterador que é somadao mais 1
        if(id == it->getId()){//Verificação de igualidade do id do iterador com o id recebeido pela função
            std::__throw_runtime_error("já existe um assento com esse id reservado\n");//Caso a verificação seja falsa, aparece essa mensagem
            return;//É feito o return para que acabe a função
        }
    }
    for (auto it = this->assentosDisponiveis.begin(); it != this->assentosDisponiveis.end(); ++it) {//iterador recebe como inicio a instrução de begin de assentos Disponiveis, e roda enquanto for diferente que o end de assentos Disponiveis,e no fim é feito iterador que é somadao mais 1
        if(id == it->getId()){//Verificação de igualidade do id do iterador com o id recebeido pela função
            it->setReservado(true);
            assentosReservados.push_back(*it);//Iterador é adicionado aos assentos Reservados
            rmvAssentoDisp(id);//Id é removido dos Assentos Disponíveis
            return;//É feito o return para que acabe a função
        }
    }
}
