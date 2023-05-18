#include "../headers/ListaCliente.h"

ListaCliente::ListaCliente() {}
//Construtor de Lista de Clientes
ListaCliente::ListaCliente(const std::vector<Cliente>& clientes) : clientes(clientes) {}

ListaCliente::~ListaCliente() {}

//Fun��o para adicionar cliente na lista de clientes, que recebe um cliente inteiro
void ListaCliente::adicionarCliente(const Cliente& cliente) {
  for (auto it = clientes.begin(); it != clientes.end(); ++it) {//iterador recebe como inicio a instru��o de begin de clientes, e roda enquanto for diferente que o end de clientes,e no fim � feito iterador � somadao mais 1
    if(it->getId() == cliente.getId()){//Compara��o do id do Iterador com o do Cliente recebido da fun��o
      std::__throw_invalid_argument("ERROR: na fun��o \"adicionarCliente\", tentativa de adcionar cliente com id de outro existente");//Se j� houver um cliente com este id, acontece um erro
    }
  }
  clientes.push_back(cliente);//� Adicionado o cliente no final da lista
}
//Fun��o de remo��o de um cliente da lista de Clientes, que recebe um id
void ListaCliente::removerCliente(const std::string& id) {
  for (auto it = clientes.begin(); it != clientes.end(); ++it){ //iterador recebe como inicio a instru��o de begin de clientes, e roda enquanto for diferente que o end de clientes,e no fim � feito iterador que � somadao mais 1
    if (it->getId() == id) {//Compara��o do id do Iterador com o id recebido da fun��o
        clientes.erase(it);//� feito  a remo��o do cliente do id selecionado
        break;
    }
  }
}
//Fun��o de busca do cliente, que recebe o id
Cliente* ListaCliente::buscarCliente(const std::string& id) {
  for (auto it = clientes.begin(); it != clientes.end(); ++it) {//iterador recebe como inicio a instru��o de begin de clientes, e roda enquanto for diferente que o end de clientes,e no fim � feito iterador que � somadao mais
    if (it->getId() == id) {//Compara��o do id do Iterador com o id recebido da fun��o
      return &(*it);//� feito o retorno do iterator
    }
  }
  return nullptr;//Caso n�o haja nenhum id com o mesmo valor do id do iterador, o programa retorna para NULL
}

std::vector<Cliente>& ListaCliente::getClienteList(){
  return this->clientes;
}