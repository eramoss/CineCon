#include "Filme.h"
#include <ctime>
#include <vector>

class ListaFilme {
public:
  ListaFilme();
  explicit ListaFilme(const std::vector<Filme>& filmes);
  ~ListaFilme();

  void adicionarFilme(const Filme& filme);
  void removerFilme(const std::string& id);
  Filme* buscarFilme(const std::string& id);

private:
  std::vector<Filme> filmes;
};