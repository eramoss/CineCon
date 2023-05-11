#ifndef LISTACOMPRA_H
#define LISTACOMPRA_H

#include <vector>
#include "Bilhete.h"

class ListaCompra {
public:
  void adicionarBilhete(const Bilhete& bilhete);
  void removerBilhete(const Bilhete& bilhete);
  std::vector<Bilhete> getBilhetes() const;
  double getPrecoTotal() const;

private:
  std::vector<Bilhete> bilhetes;
};

#endif