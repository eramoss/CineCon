#ifndef SESSAO_H
#define SESSAO_H
#include <vector>
#include "Assento.h"
#include "Filme.h"
#include "Sala.h"

class Sessao{

public:
  Sessao();
  Sessao(const Filme &filme,const Sala &sala);
  ~Sessao();

  Filme getFilme() const;
  Sala getSala() const;
  std::vector<Assento> getAssento() const;

  Sessao setFilme(const Filme &);
  Sessao setSala(const Sala &);
  Sessao setAssentosDisp(const std::vector<Assento> &);

  void rmvAssentoDisp(const std::string &id);
  void addAssentoDisp(const std::string &id);

private:
  Filme filme;
  Sala sala;
  std::vector<Assento> assentosDisponiveis;
};


#endif