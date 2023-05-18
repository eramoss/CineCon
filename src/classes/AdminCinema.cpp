#include "../headers/AdminCinema.h"

// Fun��o void para a cria��o de um Filme que recebe o id, nome, isDublado, is3d, dura��o, Data do Filme, lista dos filmes.
void AdminCinema::createFilme(const std::string &id, const std::string &nome, bool isDublado, bool is3d, time_t duracao, const DataFilmeParams &data, ListaFilme &lista)
{
  Filme *filme = new Filme(id, nome, isDublado, is3d, duracao, data); // � feito a cria��o de um novo filme recebendo os valores que um filme precisa, pela fun��o.
  lista.adicionarFilme(*filme);                                       // Filme adicionado a lista de filmes
}
// Fun��o void para a cria��o de um filme que recebe o filme inteiro, e a lista de filmes.
void AdminCinema::createFilme(Filme &filme, ListaFilme &lista)
{
  lista.adicionarFilme(filme); // Filme adicionado a lista de filmes
}
// Fun��o void para deletar um filme, que recebe o id do Filme e a lista de filmes
void AdminCinema::deleteFilme(const std::string &id, ListaFilme &lista)
{
  Filme *filme = lista.buscarFilme(id); // Primeiramente o filme nesta fun��o recebe o a fun��o de busca do filme com id do filme que � desejado ser deletado
  lista.removerFilme(id);               // � feito a remo��o do filme da lista de filmes
}
// Fun��o void para deletar a sess�o, que recebe o if da Sess�o e a lista de filmes
void AdminCinema::deleteSessao(const std::string &id, ListaSessao &lista)
{
  Sessao *sessao = lista.findSessao(id); // Primeiramente a sessao nesta fun��o recebe o a fun��o de busca da sess�o com id da sess�o que � desejado ser deletado
  lista.removeSessao(id);                // � feito a remo��o da Sess�o da lista de Sess�es
}
// Fun��o void para a cria��o de uma Sess�o de filme, que recebe um filme, a sala, o id e a lista de Sess�o
void AdminCinema::createSessao(const Filme &filme, const Sala &sala, const std::string &id, float preco, ListaSessao &lista)
{
  Sessao *sessao = new Sessao(filme, sala, preco, id); // � feito a cria��o de uma nova Sess�o recebendo os valores que um filme precisa, pela fun��o
  lista.addSessao(*sessao);                            // A Sess�o criada � adicionada a lista de Sess�es
}
// Fun��o void para a cria��o de uma Sess�o de filme, que recebe uma Sess�o inteia e a lista de Sess�o
void AdminCinema::createSessao(Sessao &sessao, ListaSessao &lista)
{
  lista.addSessao(sessao); // Sess�o � adicionada a lista de Sess�es
}
// Fun��o void para a cria��o de uma Sala, que recebe id, o n�mero total de assentos da sala e a lista de salas
void AdminCinema::createSala(const std::string &id, int totalAssentos, ListaSala &lista)
{
  Sala *sala = new Sala(id, totalAssentos); // � criado uma sala que recebe o id e o n�mero total de assentos
  lista.addSala(*sala);                     // A Nova Sala criada � adicionada a lista de salas
}
// Fun��o void para a cria��o de uma Sala, que recebe uma sala inteira e a lista de Salas
void AdminCinema::createSala(Sala &sala, ListaSala &lista)
{
  lista.addSala(sala); // Sala recebida � adicionada a Lista de Salas
}
// Fun��o void para deletar uma Sala, que recebe o id e a lista de Salas
void AdminCinema::deleteSala(const std::string &id, ListaSala &lista)
{
  Sala *sala = lista.findSala(id); // � criado uma sala que recebe a sala com id que � desejado ser removido
  lista.removeSala(id);            // � feito a remo��o da sala com id, da lista de Salas
}