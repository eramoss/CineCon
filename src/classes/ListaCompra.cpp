#include "../headers/ListaCompra.h"
#include <algorithm>



void ListaCompra::adicionarBilhete(const Bilhete& bilhete) {
  bilhetes.push_back(bilhete);
}

void ListaCompra::removerBilhete(const std::string& id) {
 for(auto it =bilhetes.begin(); it !=bilhetes.end(); ++it){
  if(it->getId() == id){
    bilhetes.erase(it);
  }
 }
}

Bilhete& ListaCompra::busacarBilhete(const std::string& id) {
  for(auto it =bilhetes.begin(); it !=bilhetes.end(); ++it){
    if(it->getId() == id){
      return *it;
    }
  }
}

std::vector<Bilhete> ListaCompra::getBilhetes() const {
  return bilhetes;
}

double ListaCompra::getPrecoTotal() const {
  double total = 0.0;
  for (const auto& bilhete : bilhetes) {
    total += bilhete.getPreco();
  }
  return total;
}
