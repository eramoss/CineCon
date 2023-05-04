#ifndef FILME_H
#define FILME_H
#include <string>

class Filme{

public:
  Filme(/* args */);
  ~Filme();

  std::string getNome() const;
  bool getDublado() const;
  bool get3D() const;
  time_t getData() const;

  Filme setNome(const std::string&);
  Filme setDublado(bool);
  Filme set3D(bool);
  Filme setData(time_t);

private:
  std::string nome;
  bool isDublado;
  bool is3D;
  time_t data;
};


#endif