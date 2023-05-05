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
  Filme(const std::string& nome, bool isDublado, bool is3d,const DataFilmeParams& data);
  Filme();
  ~Filme();

  std::string getNome() const;
  bool getDublado() const;
  bool get3D() const;
  time_t getData() const;

  Filme setNome(const std::string&);
  Filme setDublado(bool);
  Filme set3D(bool);
  Filme setData(const DataFilmeParams&);

private:
  std::string nome;
  bool isDublado;
  bool is3D;
  time_t data;
};


#endif