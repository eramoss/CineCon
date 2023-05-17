#include <iostream>
#include <string>
#include <stdlib.h>
#include "macros.h"

ListaFilme *listaFilme = new ListaFilme();
ListaSala *listaSala = new ListaSala();
ListaSessao *listaSessao = new ListaSessao();

Filme *filme = new Filme("1", "wall-e", true, true, HOUR_IN_TIME_T, {15, 30, 2, 6, 2023});
Sala *sala = new Sala("idSala", 18);
Sessao *sessao = new Sessao(*filme, *sala, "idFilme");
Cliente *cliente = new Cliente("546431654", "eduardo", false, 17);

AdminCinema *admin = new AdminCinema("id", "admin", "alo");

void FinalizarCompra(Cliente & cliente){
	system("clear");

	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\t\t|    CINECON - COMPRAS     |";
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\tCompra finalizada!!!" << std::endl;
	std::cout << "\n\t\t\t\tO cliente: " << cliente.getNome() << " comprou no total: " << cliente.getListaCompra().getPrecoTotal() << std::endl;

	cliente.getPCD() || cliente.getIdade() < 18? std::cout << "\t\t\t\tFoi pago metade do preço pois o cliente ou é de menor ou é PCD": std::cout << std::endl;
	cliente.getListaCompra().getBilhetes().clear();
	system("read 0 -p");
}

void menu_cliente()
{

	int aux_menu_cliente = 1;
	do
	{
		system("clear");
		std::cout << "\n\t\t\t\t\t----------------------------";
		std::cout << "\n\t\t\t\t\t|   BEM-VINDO AO CINECON!  |";
		std::cout << "\n\t\t\t\t\t----------------------------";
		std::cout << "\n\n\n\n\t\t\t - Selecione o que quer fazer -";
		std::cout << "\n\n\n\n\t\t\t1. Ver filmes em cartaz";
		std::cout << "\n\n\t\t\t2. Adcionar ingresso no carrinho";
		std::cout << "\n\n\t\t\t3. Retirar do carrinho";
		std::cout << "\n\n\t\t\t4. Realizar Compra";
		std::cout << "\n\n\t\t\t5. Listar ingressos no carrinho\n\n\t\t\t";
		std::cin >> aux_menu_cliente;

		if (aux_menu_cliente == 1)
		{ /// APENAS VER QUE FILME ESTÁ EM CARTAZ
			system("clear");
			std::cout << "\n\t\t\t\t----------------------------";
			std::cout << "\n\t\t\t\t|          CINECON         |";
			std::cout << "\n\t\t\t\t----------------------------";
			std::cout << "\n\n\n\n\t\t\t\t . Filmes em cartaz: \n\n";

			for (auto it = listaSessao->getSessoes().begin(); it != listaSessao->getSessoes().end(); ++it)
			{

				std::cout << "\t\t\t\t\t" << it->getFilme().getNome() << "\n";
			}
			std::cout << "\n\n\n\n\t\t\t1. Consultar Filmes";
			std::cout << "\n\n\t\t\t* Ou pressione qualquer tecla para voltar ao menu anterior *";
			int consulta;
			std::cin >> consulta;
			if (consulta == 1)
			{
				system("clear");
				std::cout << "\n\t\t\t\t----------------------------";
				std::cout << "\n\t\t\t\t|    CINECON - HORÁRIOS    |";
				std::cout << "\n\t\t\t\t----------------------------";
				std::cout << "\n\n\n\n\t\t\t\t . Escolha o filme: \n\n";
				for (auto it = listaSessao->getSessoes().begin(); it != listaSessao->getSessoes().end(); ++it)
				{
					std::cout << "\t\t\t\t\t" << it->getFilme().getId() << "-" << it->getFilme().getNome() << "\n";
				}
				std::cout << "\n\n\n\n\t\t\t";
				std::string indice_filme;
				std::cin >> indice_filme;
				system("clear");
				int erro = 0;
				for (auto it = listaSessao->getSessoes().begin(); it != listaSessao->getSessoes().end(); it++)
				{
					if (it->getFilme().getId() == indice_filme)
					{
						std::cout << "\n\t\t\t\t----------------------------";
						std::cout << "\n\t\t\t\t|    CINECON - HORÁRIOS    |";
						std::cout << "\n\t\t\t\t----------------------------";
						std::cout << "\n\n\n\n\t\t\t\tSobre o filme: '" << it->getFilme().getNome() << "' : \n\n";
						const time_t data = it->getFilme().getData();
						const time_t duracao = it->getFilme().getDuracao();
						std::cout << "\t\t\t\tData do filme: " << asctime(localtime(&data)) << "\n";
						std::cout << "\t\t\t\tDuracao do filme: " << duracao/60/60 << "/hr e " << duracao%60 << "/min" << "\n";
						it->getFilme().get3D()? std::cout << "\t\t\t\tO filme está em 3D" << std::endl : std::cout << "\t\t\t\tO filme não está em 3D" << std::endl;
						it->getFilme().getDublado()? std::cout << "\t\t\t\tO filme está Dublado" << std::endl : std::cout << "\t\t\t\tO filme não está Dublado" << std::endl;
						std::cout << "\t\t\t\tId do filme: "<< it->getFilme().getId() << std::endl;
						erro = 0;

						system("read 0 -p");
						break;
					}
					erro = 1;
				}
				if (erro == 1)
				{
					std::cout << "\n\t\t\t\t\tNão existe este filme na lista\n\n";
					system("read 0 -p");
				}
			}
		}
		else if (aux_menu_cliente == 2)
		{ /// COMPRA DE INGRESSOS
			system("clear");
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\t\t\t\t\t|          CINECON         |";
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\n\n\n\t\t\t\tFilmes em cartaz: \n\n";
			for (auto it = listaSessao->getSessoes().begin(); it != listaSessao->getSessoes().end(); ++it)
			{
				std::cout << "\t\t\t\t\t" << it->getFilme().getId() << "-" << it->getFilme().getNome() << "\n";
			}
			std::cout << "\n\n\n\n\t\t\t\tEscolha o filme desejado: ";
			std::string indice_filme;
			std::cin >> indice_filme;
			system("clear");
			Filme * filme_i = listaFilme->buscarFilme(indice_filme);
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\t\t\t\t\t|    CINECON - HORÁRIOS    |";
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\n\n\n\t\t\t\tHorario do filme: '" << filme_i->getNome() << "' : ";
			const time_t data = filme_i->getData();
			std::cout << " " << asctime(localtime(&data)) << "\n";
			std::cout << "\t\t\t\tPreço do filme: " << 38.50;
			std::cout << "\n\t\t\t\ttem certeza que deseja realizar a compra? (y/n): \n";
			std::string escolha;
			std::cin >> escolha;
			Sessao * sessao_i = listaSessao->findSessao(filme_i->getId());
			if (escolha == "y"){
				for (int i = 0; i < sessao_i->getAssentoDisp().size(); i++){
					std::cout << "\t\t\t\t" << sessao_i->getAssentoDisp()[i].getId() << "\n";
				}
				std::cout << "\t\t\t\tQual assento você deseja? \n";
				std::string assentoId;
				std::cin >> assentoId;
				Bilhete * bilhete = new Bilhete(std::to_string( time(NULL) %rand() ),38.50,*sessao_i,assentoId);
				if(cliente->getIdade() < 18 || cliente->getPCD()){
					bilhete->setIsMeio(true);
					bilhete->setPreco(38.50/2);
				}
				cliente->getListaCompra().adicionarBilhete(*bilhete);
				system("read 0 -p");
			}else if (escolha == "n"){

			}
		}else if (aux_menu_cliente == 3){
			system("clear");
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\t\t\t\t\t|    CINECON - COMPRAS     |";
			std::cout << "\n\t\t\t\t\t----------------------------";

			for (auto it = cliente->getListaCompra().getBilhetes().begin(); it != cliente->getListaCompra().getBilhetes().end(); ++it) {
				std::cout << "\n\t\t\t\t\tId: " << it->getId() << " -- Filme: " << it->getSessao().getFilme().getNome() << "\n";
			}
			std::string escolha;
			std::cout << "\n\t\t\t\tQual deseja retirar?\n";
			std::cin >> escolha;
			cliente->getListaCompra().removerBilhete(escolha);

			system("read 0 -p");
		}else if (aux_menu_cliente == 4){
			FinalizarCompra(*cliente);
		}else if (aux_menu_cliente == 5){
			system("clear");
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\t\t\t\t\t|    CINECON - BILHETES    |";
			std::cout << "\n\t\t\t\t\t----------------------------";
			
			for (auto it = cliente->getListaCompra().getBilhetes().begin(); it != cliente->getListaCompra().getBilhetes().end(); ++it) {
				std::cout << "\n\t\t\t\t\tAssento: " << it->getAssento().getId() << " -- Filme: " << it->getSessao().getFilme().getNome() << "\n";
			}
			system("read 0 -p");
		}
	} while (aux_menu_cliente != 7);
}

void menu_admin()
{
	system("clear");
	std::cout << "cu";
	system("read -n1 -r -p \"Press any key to continue...\"");
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	admin->createFilme(*filme, *listaFilme);

	admin->createSala(*sala, *listaSala);

	admin->createSessao(*sessao, *listaSessao);

	int select = 0;

	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\t\t| CINECON - MENU DE ACESSO |";
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\n\n\n\t\t\t- Selecione o seu tipo de acesso -";
	std::cout << "\n\n\n\n\t\t\t1. Acesso de Cliente";
	std::cout << "\n\n\t\t\t2. Acesso Admin\n\n\n\n\t\t\t";

	std::cin >> select; // Verifica a tecla pressionada no teclado

	if (select == 1)
	{ // Caso a tecla pressionada seja 1
	system("clear");
		std::cout << "INSIRA O NOME DE USUARIO\n";
		std::string nome;
		std::cin >> nome;
		std::cout << "INSIRA O IDADE DO USUARIO\n";
		int idade;
		std::cin >> idade;
		std::cout << "VOCÊ É PCD?(y/n)\n";
		std::string pcd;
		std::cin >> pcd;
		pcd == "y" ? cliente->setPCD(true) : cliente->setPCD(false);
		cliente->setNome(nome);
		cliente->setIdade(idade);
		cliente->setId("5433468");
		menu_cliente();
	}
	else if (select == 2)
	{
		menu_admin();
	}
	return 0;
}
