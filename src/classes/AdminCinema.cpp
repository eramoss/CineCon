#include "../headers/AdminCinema.h"


bool AdminCinema::createFilme(const std::string& id,const std::string& nome, bool isDublado, bool is3d,time_t duracao, const DataFilmeParams& data, ListaFilme & lista){
  Filme * filme = new Filme(id,nome,isDublado,is3d,duracao,data);
  lista.adicionarFilme(*filme);
  return true;
}

bool AdminCinema::deleteFilme(const std::string& id, ListaFilme & lista){
  lista.removerFilme(id);
}