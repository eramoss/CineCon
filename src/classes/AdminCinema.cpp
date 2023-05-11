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

void AdminCinema::deleteSessao(const std::string& id, ListaSessao & lista){
  Sessao * sessao = lista.findSessao(id);
  lista.removeSessao(id);
  delete sessao;
}
void AdminCinema::createSessao(const Filme &filme,const Sala &sala, const std::string & id, ListaSessao & lista){
  Sessao * sessao = new Sessao(filme,sala,id);
  lista.addSessao(*sessao);
}

void AdminCinema::createSala(const std::string& id,int totalAssentos, ListaSala & lista){
  Sala * sala = new Sala(id,totalAssentos);
  lista.addSala(*sala);
}

void AdminCinema::deleteSala(const std::string & id, ListaSala & lista){
  Sala * sala = lista.findSala(id);
  lista.removeSala(id);
  delete sala;

}