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


  Sala * sala = new Sala();
  Sessao * sessao = new Sessao();

  sessao->setFilme(*filme);
  Bilhete * bilhete = new Bilhete();
  bilhete->setSessao(*sessao);




  std::cout << "o filme " << bilhete->getSessao().getFilme().getNome() << " vai passar: "  << asctime(localtime(&t));
  return 0;
}
