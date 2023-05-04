#include <iostream>
#include "macros.h"


int main(int argc, char const *argv[])
{
  Filme * fl = new Filme();
  fl->setData({15,30,6,5,2023});
  const time_t t = fl->getData();
  fl->setNome("Wall-e");

  std::cout << "o filme " << fl->getNome() << " vai passar: "  << asctime(localtime(&t));
  return 0;
}
