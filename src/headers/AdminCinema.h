#ifndef ADMINCINEMA_H
#define ADMINCINEMA_H

#include <string>
#include "Pessoa.h"
#include "Filme.h"
#include "../headers/ListaFilme.h"
#include "../headers/ListaSessao.h"
#include "../headers/ListaSala.h"

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
  
  void createFilme(const std::string& id,const std::string& nome, bool isDublado, bool is3d,time_t duracao, const DataFilmeParams& data,ListaFilme & lista);
  void deleteFilme(const std::string& id,ListaFilme & lista);

  void createSessao(const Filme &filme,const Sala &sala, const std::string & id,ListaSessao & lista);
  void deleteSessao(const std::string& id, ListaSessao & lista);

  void createSala(const std::string& id,int totalAssentos, ListaSala & lista);
  void deleteSala(const std::string& id,ListaSala & lista);

private:
  std::string senha;
};

#endif
