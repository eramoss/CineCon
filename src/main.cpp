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
  sessao->rmvAssentoDisp("0");
  sessao->addAssentoDisp("0");
  Bilhete * bilhete = new Bilhete();
  bilhete->setSessao(*sessao);
  Assento a = sessao->findAssento("1");
  bilhete->setAssento(a);
  Bilhete * bilhete1 = new Bilhete();
  bilhete1->setSessao(*sessao);
  bilhete1->setAssento(a);




  std::cout << "o filme " << bilhete->getSessao().getFilme().getNome() << " vai passar: "  << asctime(localtime(&t)) << "na sala: " << bilhete->getSessao().getSala().getId() << "\nE seu assento é: " << bilhete1->getAssento().getId() << "\n";
  return 0;
}
