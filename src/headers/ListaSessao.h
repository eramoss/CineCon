#ifndef LISTASESSAO_H
#define LISTASESSAO_H

#include <vector>
#include "Sessao.h"

class ListaSessao {

public:
  ListaSessao();
  ~ListaSessao();

  void addSessao(const Sessao& sessao);
  void removeSessao(const std::string& id);
  Sessao* findSessao(const std::string& id);
  std::vector<Sessao>& getSessoes() ;

private:
  std::vector<Sessao> sessoes;
};

#endif
