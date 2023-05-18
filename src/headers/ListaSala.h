#ifndef LISTASALA_H
#define LISTASALA_H

#include <vector>
#include "Sala.h"

class ListaSala {

public:
  ListaSala();
  ~ListaSala();

  void addSala(const Sala &sala);
  Sala* findSala(const std::string &id);
  void removeSala(const std::string &id);
  std::vector<Sala>& getSalaList() ;

private:
  std::vector<Sala> salas;
};

#endif
