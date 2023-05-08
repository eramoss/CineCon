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
  filme->setNome("Wall-e");
  Filme * filme1 = new Filme();
  struct DataFilmeParams data1 = {
    /*hora: */ 16,
    /*minuto: */ 30,
    /*dia: */ 6,
    /*mês: */ 5,
    /*ano: */ 2023,
  };
  
  filme1->setData(data1);
  filme1->setNome("Wall-e");
    Filme * filme2 = new Filme();
  struct DataFilmeParams data2 = {
    /*hora: */ 17,
    /*minuto: */ 30,
    /*dia: */ 6,
    /*mês: */ 5,
    /*ano: */ 2023,
  };
  
  filme1->setData(data2);
  filme1->setNome("Wall-e");


  Sala * sala = new Sala("a1", 12);
  Sala * sala1 = new Sala("a2", 12);
  Sessao * sessao = new Sessao(*filme,*sala);
  Sessao * sessao1 = new Sessao(*filme1,*sala);
  Sessao * sessao2 = new Sessao(*filme, *sala1);

  ListaSessao * ls = new ListaSessao();
  ls->addSessao(*sessao);
  ls->addSessao(*sessao1);
  ls->addSessao(*sessao2);
  return 0;
}
