#include <iostream>
#include "macros.h"


int main(int argc, char const *argv[]){
    DataFilmeParams data;
    data.ano = 2023;
    data.dia = 15;
    data.hora = 18;
    data.mes = 4;
    data.minuto = 30;


    Filme * filme = new Filme("idFilme","wall-e",true,false,HOUR_IN_TIME_T,data);
    Sala * sala = new Sala("idSala",18);
    Sessao * sessao = new Sessao(*filme , *sala, "idSessao");
    Bilhete * bilhete = new Bilhete("idBilhete",18.90,*sessao,"2");
    Cliente * cliente = new Cliente("654647424","joão",true,18);

    

    cliente->getListaCompra().adicionarBilhete(*bilhete);

   std::cout << cliente->getListaCompra().getPrecoTotal() << std::endl;
    
}
