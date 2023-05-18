#include "../headers/ListaFilme.h"

ListaFilme::ListaFilme() : filmes() {}
//Construtor da Lista de Filmes
ListaFilme::ListaFilme(const std::vector<Filme>& filmes) : filmes(filmes) {}

ListaFilme::~ListaFilme() {}

//Função void que adiciona um filme a Lista de Filmes, que recebe um filme inteiro
void ListaFilme::adicionarFilme(const Filme& filme) {
  for (auto it = filmes.begin(); it != filmes.end(); ++it) {//iterador recebe como inicio a instrução de begin de filmes, e roda enquanto for diferente que o end de filmes,e no fim é feito iterador que é somadao mais 1
    if (it->getNome() == filme.getNome() && it->getData() == filme.getData()) {//Comparação do nome do Iterador com o nome recebido da função e a data do iterador com a data do filme recebido da função
      std::__throw_invalid_argument("ERROR: na função \"adcionarFilme\", tentativa de adcionar filmes iguais");//Caso já haja um filme com mesmo nome no mesmo horário aparece a mensagem de erro
    }
  }
  filmes.push_back(filme);//Filme é adicionado a lista de filmes
}

//Função void que remove um filme da lista de Filmes, que recebe um id
void ListaFilme::removerFilme(const std::string& id) {
  for (auto it = filmes.begin(); it != filmes.end(); ++it) {//iterador recebe como inicio a instrução de begin de filmes, e roda enquanto for diferente que o end de filmes,e no fim é feito iterador que é somadao mais 1
    if (it->getId() == id){ //Comparação do id do Iterador com o id recebido da função
      filmes.erase(it);//Caso o id do Iterador seja igual com o id recebido da função, o mesmo é removido da lista de Filmes
      break;//É feito o cancelamento do loop
    }
  }
}

//Função de busca de um Filme, que recebe um id
Filme* ListaFilme::buscarFilme(const std::string& id) {
  for (auto it = filmes.begin(); it != filmes.end(); ++it) {//iterador recebe como inicio a instrução de begin de filmes, e roda enquanto for diferente que o end de filmes,e no fim é feito iterador que é somadao mais 1
    if (it->getId() == id) {//Comparação do id do Iterador com o id recebido da função
      return &(*it);//Caso o id do Iterador seja igual com o id recebido da função, é feito o return do iterador
    }
  }
  std::__throw_invalid_argument("Erro na função findFilme, Filme inexistente");
  return nullptr;//Caso o id do Iterador seja diferente do id recebido da função, o programa retorna NULL;
}


std::vector<Filme>& ListaFilme::getLista(){
  return this->filmes;
}