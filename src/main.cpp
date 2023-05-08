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
  Cliente * cliente = new Cliente("564623546","Jhon Doe",true,18);


  Bilhete * bilhe = new Bilhete("4564-f3da-342g-4sda",40.32,*sessao,"1",*cliente);
  
  if (bilhe->getIsMeio()){
    bilhe->setPreco(bilhe->getPreco()/2);
  }

  Bilhete * bilhe1 = new Bilhete("4564-f3da-342g-4sde",40.32,*sessao,"1",*cliente);
  
  std::cout << bilhe1->getAssento().getId() << std::endl;

  std::cout << "O filme " <<bilhe->getSessao().getFilme().getNome() << " vai passar: "  << asctime(localtime(&t)) << "Na sala: " <<bilhe->getSessao().getSala().getId() << "\nE seu assento é: " <<bilhe->getAssento().getId()  << "\n\n" <<"o bilhete custou: " << bilhe->getPreco();

  bilhe->getIsMeio() ? std::cout << ". Por que o Cliente: " << bilhe->getCliente().getNome() << "\nCom Id: " << bilhe->getCliente().getId() << "\n" << "Paga metade do ingresso\n" : std::cout << std::endl;

  return 0;
}
