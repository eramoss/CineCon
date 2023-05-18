#include "../headers/ListaSala.h"

ListaSala::ListaSala(): salas() {}
//Construtor da Lista de Salas
ListaSala::~ListaSala() {}

//Função void para adicionar uma sala a lista de Salas, que recebe uma sala
void ListaSala::addSala(const Sala &sala) {
  for (auto it = salas.begin(); it != salas.end(); ++it) {//iterador recebe como inicio a instrução de begin de sala, e roda enquanto for diferente que o end de sala,e no fim é feito iterador que é somadao mais 1
    if (it->getId() == sala.getId()) {//Comparação do id do Iterador com o id recebido da função
      std::__throw_invalid_argument("ERROR: na função \"addSala\", tentativa de adcionar nova sala com mesmo id de outra");//Caso haja a tentativa de adicionar uma sala com mesmo id, resulta em erro
    }
  }
  salas.push_back(sala);//Sala adicionada na Lista de Salas
}

//Função para encontrar uma sala, que recebe o valor de um id
Sala* ListaSala::findSala(const std::string &id) {
  for (auto it = salas.begin(); it != salas.end(); ++it) {
    if (it->getId() == id) {//Comparação entre o id da sala com o id recebido da função
      return &(*it);//caso haja um id igual ao id recebido, ele da o return da sala
    }
  }
    std::__throw_invalid_argument("Erro na função findSala, Sala inexistente");
    return nullptr;
}

//Função void para remover uma sala da Lista de Salas
void ListaSala::removeSala(const std::string &id) {
  for (auto it = salas.begin(); it != salas.end(); ++it) {//iterador recebe como inicio a instrução de begin de sala, e roda enquanto for diferente que o end de sala,e no fim é feito iterador que é somadao mais 1
    if (it->getId() == id) {//Comparação do id do Iterador com o id recebido da função
      salas.erase(it);//Caso os ids comparados sejam iguais o iterador é removido
      break;//É feito o break para acabar com o loop
    }
  }

}

std::vector<Sala>& ListaSala::getSalaList() {
  return salas;
}