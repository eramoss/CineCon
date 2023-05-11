#include "../headers/AdminCinema.h"


void AdminCinema::createFilme(const std::string& id,const std::string& nome, bool isDublado, bool is3d,time_t duracao, const DataFilmeParams& data, ListaFilme & lista){
  Filme * filme = new Filme(id,nome,isDublado,is3d,duracao,data);
  lista.adicionarFilme(*filme);

}

void AdminCinema::deleteFilme(const std::string& id, ListaFilme & lista){
  Filme* filme = lista.buscarFilme(id);
  lista.removerFilme(id);
  delete filme;
}