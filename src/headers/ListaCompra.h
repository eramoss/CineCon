#ifndef LISTACOMPRA_H
#define LISTACOMPRA_H

#include <vector>
#include "Bilhete.h"

class ListaCompra {
public:
  void adicionarBilhete(const Bilhete& bilhete);
  void removerBilhete(const std::string&);
  Bilhete& busacarBilhete(const std::string&);
  std::vector<Bilhete>& getBilhetes();
  double getPrecoTotal() const;

private:
  std::vector<Bilhete> bilhetes;
};

#endif