#ifndef ADMINCINEMA_H
#define ADMINCINEMA_H

#include <string>
#include "Pessoa.h"
#include "Filme.h"
#include "../headers/ListaFilme.h"

class AdminCinema : public Pessoa {

public:
  AdminCinema(const std::string& id, const std::string& nome, const std::string& senha)
    : Pessoa(id, nome), senha(senha) {}

  std::string getSenha() const {
    return senha;
  }

  void setSenha(const std::string& senha) {
    this->senha = senha;
  }
  
  bool createFilme(const std::string& id,const std::string& nome, bool isDublado, bool is3d,time_t duracao, const DataFilmeParams& data,ListaFilme & lista);
  bool deleteFilme(const std::string& id,ListaFilme & lista);

private:
  std::string senha;
};

#endif
