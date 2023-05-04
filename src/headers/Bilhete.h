#ifndef BILHETE_H
#define BILHETE_H

#include <string>
#include "Assento.h"
#include "Sessao.h"

class Bilhete{

public:
  Bilhete(/* args */);
  ~Bilhete();

  std::string getId() const;
  double getPreco() const;
  Sessao getSessao() const;
  Assento getAssento() const;
  time_t getData() const;

  Bilhete setId(std::string);
  Bilhete setPreco(double);
  Bilhete setSessao(Sessao);
  Bilhete setAssento(Assento);
  Bilhete setData(std::string);

private:
  std::string id;
  double preco;
  Sessao sessao;
  Assento assento;
  time_t data;
};

#endif