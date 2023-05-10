#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "Bilhete.h"


class Cliente{

public:
  Cliente();
  Cliente(const std::string& id,const std::string& nome,bool PCD,int idade);
  ~Cliente();

  std::string getId() const;
  std::string getNome() const;
  bool getPCD() const;
  int getIdade() const;

  Cliente& setId(const std::string&);
  Cliente& setNome(const std::string&);
  Cliente& setPCD(bool);
  Cliente& setIdade(int);
  void AddCompra(const Bilhete&);
  void rmvCompra(const std::string&);

private:
  std::string id;
  std::string nome;
  int idade;
  bool PCD;
  std::vector<Bilhete> listaCompras;

};

#endif