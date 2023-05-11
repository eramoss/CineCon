#ifndef ADMINCINEMA_H
#define ADMINCINEMA_H

#include <string>
#include "Pessoa.h"

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

private:
  std::string senha;
};

#endif
