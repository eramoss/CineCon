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
  Filme(const std::string& nome, bool isDublado, bool is3d,time_t duracao,const DataFilmeParams& data);
  Filme();
  ~Filme();

  std::string getNome() const;
  bool getDublado() const;
  bool get3D() const;
  time_t getData() const;
  time_t getDuracao() const;

  Filme& setNome(const std::string&);
  Filme& setDublado(bool);
  Filme& set3D(bool);
  Filme& setData(const DataFilmeParams&);
  Filme& setDuracao(time_t);

private:
  std::string nome;
  bool isDublado;
  bool is3D;
  time_t data;
  time_t duracao;
};


#endif