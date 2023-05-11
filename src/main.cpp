#include <iostream>
#include "macros.h"


int main(int argc, char const *argv[])
{
  Cliente * cliente = new Cliente("id","nome",true,18);
  std::cout << cliente->getNome();

  AdminCinema * admin = new AdminCinema("646432168","aé","5465461345");


  return 0;
}
