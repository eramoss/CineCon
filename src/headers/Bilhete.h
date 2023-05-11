#ifndef BILHETE_H
#define BILHETE_H

#include <string>
#include "Assento.h"
#include "Sessao.h"



class Bilhete{

public:
  Bilhete(const std::string& id,double preco,const Sessao& sessao,const std::string& assentoId);
  Bilhete();
  ~Bilhete();

  std::string getId() const;
  double getPreco() const;
  Sessao getSessao() const;
  Assento getAssento() const;
  time_t getDataCompra() const;
  time_t getDataValidade() const;
  bool getIsMeio() const;

  Bilhete& setId(const std::string&);
  Bilhete& setPreco(double);
  Bilhete& setSessao(const Sessao&);
  Bilhete& setAssento(const Assento&);
  Bilhete& setIsMeio(bool);


  Bilhete& setDataCompra();
  Bilhete& setDataValidade();

private:
  std::string id;
  bool isMeio;
  double preco;
  Sessao sessao;
  Assento assento;
  time_t dataCompra;
  time_t dataValidade;

};

#endif