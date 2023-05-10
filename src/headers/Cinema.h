#include "ListaCliente.h"
#include "ListaFilme.h" 
#include "ListaSala.h"
#include "ListaSessao.h"
#include "Bilhete.h"

class Cinema{

public:
  Cinema();
  Cinema(ListaCliente lsCliente,ListaSessao lsSessao,ListaFilme lsFilme,ListaSala lsSala);
  ~Cinema();

  ListaCliente& getLsClinete() const;
  ListaSessao& getLsSessao() const;
  ListaFilme& getLsFilme() const;
  ListaSala& getLsSala() const;

private:
  ListaCliente lsCliente;
  ListaSessao lsSessao;
  ListaFilme lsFilme;
  ListaSala lsSala;
};
