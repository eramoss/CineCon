#ifndef SESSAO_H
#define SESSAO_H
#include <vector>
#include "Assento.h"
#include "Filme.h"
#include "Sala.h"

class Sessao{

public:
  Sessao(/* args */);
  ~Sessao();

  Filme getFilme() const;
  Sala getSala() const;
  std::vector<Assento> getAssento() const;

  Sessao setFilme(const Filme &);
  Sessao setSala(const Sala &);
  Sessao setAssentosDisp(const std::vector<Assento> &);

private:
  Filme filme;
  Sala sala;
  std::vector<Assento> assentosDisponiveis;
};


#endif