#include "../headers/ListaCompra.h"
#include <algorithm>
#include <iostream>

ListaCompra::ListaCompra():bilhetes(){}
// Função para adicionar um bilhete a lista de compras, que recebe um bilhete inteiro
void ListaCompra::adicionarBilhete(const Bilhete &bilhete)
{
  this->bilhetes.push_back(bilhete);
}
// Função bool que remove um bilhete da Lista de Compras, que recebe o id do bilhete que deseja ser removido
bool ListaCompra::removerBilhete(const std::string &id)
{
  for (auto it = bilhetes.begin(); it != bilhetes.end(); ++it)
  { // iterador recebe como inicio a instrução de begin de bilhetes, e roda enquanto for diferente que o end de bilhetes,e no fim é feito iterador que é somadao mais 1
    if (it->getId() == id)
    {                           // Comparação do id do Iterador com o id recebido da função
      this->bilhetes.erase(it); // É feito  a remoção do bilhete do id selecionado
      std::cout << "\n\t\t\t\tRetirado com sucesso!!";
      return true;
  }
  }
   std::cout << "\n\t\t\t\tOcorreu um erro contate o suporte...";
  return false;
}
// Função de busca do bilhete na lista de bilhetes, que recebe o id que deseja buscar
Bilhete &ListaCompra::busacarBilhete(const std::string &id)
{
  for (auto it = this->bilhetes.begin(); it != this->bilhetes.end(); ++it)
  { // iterador recebe como inicio a instrução de begin de bilhetes, e roda enquanto for diferente que o end de bilhetes,e no fim é feito iterador que é somadao mais 1
    if (it->getId() == id)
    {             // Comparação do id do Iterador com o id recebido da função
      return *it; // Caso o id do Iterador seja igual com o id recebido, é feito o retorno do iterador
    }
  }
  std::__throw_invalid_argument("Não existe bilhete com este Id"); // Caso não exista um bilhete com id recebido, a mensagem aparece
}

std::vector<Bilhete> &ListaCompra::getBilhetes()
{
  return this->bilhetes;
}

double ListaCompra::getPrecoTotal() const
{
  double total = 0.0;
  for (auto it = this->bilhetes.begin(); it != this->bilhetes.end(); ++it)
  {
    total += it->getPreco();
  }
  return total;
}
