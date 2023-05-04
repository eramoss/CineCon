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

  Bilhete setId(const std::string&);
  Bilhete setPreco(double);
  Bilhete setSessao(const Sessao&);
  Bilhete setAssento(const Assento&);
  Bilhete setData(time_t);

private:
  std::string id;
  double preco;
  Sessao sessao;
  Assento assento;
  time_t data;
};

#endif