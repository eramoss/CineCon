#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>


class Cliente{

public:
  Cliente(/* args */);
  ~Cliente();

  std::string getId() const;
  std::string getNome() const;
  bool getPCD() const;
  bool getMeio() const;

  Cliente setId(const std::string&);
  Cliente setNome(const std::string&);
  Cliente setPCD(bool);
  Cliente setMeio(bool);

private:
  std::string id;
  std::string nome;
  bool PCD;
  bool isMeio;
};

#endif