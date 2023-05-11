#include "../headers/ListaCompra.h"
#include <algorithm>



void ListaCompra::adicionarBilhete(const Bilhete& bilhete) {
  bilhetes.push_back(bilhete);
}

void ListaCompra::removerBilhete(const Bilhete& bilhete) {
  auto it = std::find(bilhetes.begin(), bilhetes.end(), bilhete);
  if (it != bilhetes.end()) {
    bilhetes.erase(it);
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
