#include "../headers/ListaCompra.h"
#include <algorithm>



void ListaCompra::adicionarBilhete(const Bilhete& bilhete) {
  this->bilhetes.push_back(bilhete);
}

void ListaCompra::removerBilhete(const std::string& id) {
 for(auto it =bilhetes.begin(); it !=bilhetes.end(); ++it){
  if(it->getId() == id){
    this->bilhetes.erase(it);
  }
 }
}

Bilhete& ListaCompra::busacarBilhete(const std::string& id) {
  for(auto it = this->bilhetes.begin(); it != this->bilhetes.end(); ++it){
    if(it->getId() == id){
      return *it;
    }
  }
  std::__throw_invalid_argument("Não existe bilhete com este Id");
}

std::vector<Bilhete>& ListaCompra::getBilhetes() {
  return this->bilhetes;
}

double ListaCompra::getPrecoTotal() const {
  double total = 0.0;
  for (auto it = this->bilhetes.begin(); it != this->bilhetes.end(); ++it) {
    total += it->getPreco();
  }
  return total;
}
