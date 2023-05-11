#include <iostream>
#include "macros.h"


int main(int argc, char const *argv[])
{
  Cliente * cliente = new Cliente("id","nome",true,18);

  AdminCinema * admin = new AdminCinema("646432168","aé","5465461345");
  DataFilmeParams params;
  params.ano = 2023;
  params.dia = 6;
  params.hora = 15;
  params.mes = 4;
  params.minuto = 30;
  Filme * filme = new Filme("id","nome",true,true,HOUR_IN_TIME_T,params);
  ListaFilme * ls = new ListaFilme();
  admin->createFilme(*filme, *ls);

  const time_t data = ls->buscarFilme("id")->getData();

  
  std::cout << "Filme: " << ls->buscarFilme("id")->getNome() << std::endl << "tem horario: " << localtime(&data)->tm_hour << ":" << localtime(&data)->tm_min  << std::endl ;
  return 0;
}
