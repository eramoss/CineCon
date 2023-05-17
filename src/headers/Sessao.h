#ifndef SESSAO_H
#define SESSAO_H
#include <vector>
#include "Assento.h"
#include "Filme.h"
#include "Sala.h"

class Sessao{

public:
  Sessao();
  Sessao(const Filme &filme,const Sala &sala, std::string id,float preco);
  ~Sessao();

  Filme getFilme() const;
  Sala getSala() const;
  std::vector<Assento>& getAssentoDisp() ;
  std::string getId() const;

  Sessao& setFilme(const Filme &);
  Sessao& setSala(const Sala &);
  Sessao& setAssentosDisp(const std::vector<Assento> &);
  Sessao & setId(const std::string &);

  void rmvAssentoDisp(const std::string &id);
  void addAssentoDisp(const std::string &id);
  Assento findAssento(const std::string &id);
  void addAssentoReservado(const std::string & id);
  void rmvAssentoReservado(const std::string & id);
  float preco;
private:
  std::string id;
  Filme filme;
  Sala sala;
  std::vector<Assento> assentosDisponiveis;
  std::vector<Assento> assentosReservados;
};


#endif