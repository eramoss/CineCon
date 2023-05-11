#ifndef PESSOA_H
#define PESSOA_H
#include <string>

class Pessoa{

public:
  Pessoa(std::string id,std::string nome){
    this->id = id;
    this->nome = nome;
  }
  Pessoa(){}
  ~Pessoa(){}
  virtual std::string getNome() const{
    return this->nome;
  }
  virtual std::string getId() const{
    return this->id;
  }

  virtual void setNome(const std::string &name){
    this->nome = name;
  }
  virtual void setId(const std::string& id){
    this->id = id;
  }
protected:
  std::string id;
  std::string nome;
};

#endif