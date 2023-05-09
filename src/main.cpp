#include <iostream>
#include "macros.h"


int main(int argc, char const *argv[])
{
  Filme * filme = new Filme();
  struct DataFilmeParams data = {
    /*hora: */ 16,
    /*minuto: */ 30,
    /*dia: */ 6,
    /*mês: */ 5,
    /*ano: */ 2023,
  };

  filme->setData(data);
  filme->setNome("Wall-e");
  filme->setDuracao(HOUR_IN_TIME_T);



  Filme * filme1 = new Filme();
  struct DataFilmeParams data1 = {
    /*hora: */ 15,
    /*minuto: */ 30,
    /*dia: */ 6,
    /*mês: */ 5,
    /*ano: */ 2023,
  };
  
  filme1->setData(data1);
  filme1->setNome("Inception");
  filme1->setDuracao(MINUTE_IN_TIME_T);

  Filme * filme2 = new Filme();
  struct DataFilmeParams data2 = {
    /*hora: */ 15,
    /*minuto: */ 32,
    /*dia: */ 6,
    /*mês: */ 5,
    /*ano: */ 2023,
  };
  
  filme2->setData(data2);
  filme2->setNome("The grandFather");
  filme2->setDuracao(HOUR_IN_TIME_T);
 


  Sala * sala = new Sala("a1", 12);
  Sala * sala1 = new Sala("a2", 12);

  Sessao * sessao = new Sessao(*filme,*sala);
  Sessao * sessao1 = new Sessao(*filme1,*sala);
  Sessao * sessao2 = new Sessao(*filme2,*sala);

  ListaSessao * ls = new ListaSessao();
  ls->addSessao(*sessao);
  ls->addSessao(*sessao1);
  ls->addSessao(*sessao2);


  return 0;
}
