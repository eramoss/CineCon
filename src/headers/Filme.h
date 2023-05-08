#ifndef FILME_H
#define FILME_H
#include <string>

struct DataFilmeParams {
  int hora;
  int minuto;
  int dia;
  int mes;
  int ano;
};
class Filme{

public:
  Filme(const std::string& nome, bool isDublado, bool is3d,unsigned int duracao,const DataFilmeParams& data);
  Filme();
  ~Filme();

  std::string getNome() const;
  bool getDublado() const;
  bool get3D() const;
  time_t getData() const;
  unsigned int getDuracao() const;

  Filme& setNome(const std::string&);
  Filme& setDublado(bool);
  Filme& set3D(bool);
  Filme& setData(const DataFilmeParams&);
  Filme& setDuracao(unsigned int);

private:
  std::string nome;
  bool isDublado;
  bool is3D;
  time_t data;
  unsigned int duracao;
};


#endif