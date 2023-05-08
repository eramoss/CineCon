#include <iostream>
#include "macros.h"


int main(int argc, char const *argv[])
{
  Filme * filme = new Filme();
  struct DataFilmeParams data = {
    /*hora: */ 15,
    /*minuto: */ 30,
    /*dia: */ 6,
    /*mês: */ 5,
    /*ano: */ 2023,
  };
  
  filme->setData(data);
  const time_t t = filme->getData();
  filme->setNome("Wall-e");


  Sala * sala = new Sala("a1", 12);
  Sessao * sessao = new Sessao(*filme,*sala);
  Cliente * cliente = new Cliente("564623546","Jhon Doe",false,15);
  Bilhete * bilhe = new Bilhete("4564-fsda-342g-4sda",40.32,*sessao,sessao->findAssento("1"),*cliente);
  if (bilhe->getIsMeio()){
    bilhe->setPreco(bilhe->getPreco()/2);
  }



  std::cout << "N filme " <<bilhe->getSessao().getFilme().getNome() << " vai passar: "  << asctime(localtime(&t)) << "Na sala: " <<bilhe->getSessao().getSala().getId() << "\nE seu assento é: " <<bilhe->getAssento().getId()  << "\n" <<"o bilhete custou: " << bilhe->getPreco() << "\n";
  if ( bilhe->getIsMeio()) std::cout << "Por que o Cliente: " << cliente->getNome() << "\nCom Id: " << cliente->getId() << "\n" << "Paga metade do ingresso\n";
  return 0;
}
