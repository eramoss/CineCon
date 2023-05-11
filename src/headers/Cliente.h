#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "Pessoa.h"



class Cliente: public Pessoa{

public:
  Cliente();
  Cliente(const std::string& id,const std::string& nome,bool PCD,int idade);
  ~Cliente();

  std::string getNome() const;
  std::string getId() const;
  bool getPCD() const;
  int getIdade() const;

  void setId(const std::string&);
  void setNome(const std::string&);
  Cliente& setPCD(bool);
  Cliente& setIdade(int);


private:
  int idade;
  bool PCD;


};

#endif