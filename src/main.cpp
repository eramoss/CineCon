#include <iostream>
#include <string>
#include <stdlib.h>
#include "macros.h"

ListaFilme *listaFilme = new ListaFilme();
ListaSala *listaSala = new ListaSala();
ListaSessao *listaSessao = new ListaSessao();
Filme *filme = new Filme("1", "wall-e", true, true, HOUR_IN_TIME_T, {15, 30, 2, 6, 2023});
Sala *sala = new Sala("1", 18);
Sessao *sessao = new Sessao(*filme, *sala, 38.50, "1");
Cliente *cliente = new Cliente();
AdminCinema *admin = new AdminCinema("idAdmin", "admin", "0000");

void FinalizarCompra(Cliente &cliente)
{
	system("clear");

	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\t\t|    CINECON - COMPRAS     |";
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\tCompra finalizada!!!" << std::endl;
	std::cout << "\n\t\t\t\tO cliente: " << cliente.getNome() << " comprou no total: " << cliente.getListaCompra().getPrecoTotal() << std::endl;

	cliente.getPCD() || cliente.getIdade() < 18 ? std::cout << "\t\t\t\tFoi pago metade do preço pois o cliente ou é de menor ou é PCD" : std::cout << std::endl;
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
		std::cout << "\n\n\t\t\t5. Listar ingressos no carrinho";
		std::cout << "\n\n\t\t\t6. Sair\n\n\t\t\t";
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
			std::cout << "\n\n\n\n\t\t\tConsultar Filmes: (y/n): \n";
			std::cout << "\t\t\t";
			std::string consulta;
			std::cin >> consulta;
			if (consulta == "y")
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
						std::cout << "\t\t\t\tDuracao do filme: " << duracao / 60 / 60 << "/hr e " << duracao % 60 << "/min"
											<< "\n";
						it->getFilme().get3D() ? std::cout << "\t\t\t\tO filme está em 3D" << std::endl : std::cout << "\t\t\t\tO filme não está em 3D" << std::endl;
						it->getFilme().getDublado() ? std::cout << "\t\t\t\tO filme está Dublado" << std::endl : std::cout << "\t\t\t\tO filme não está Dublado" << std::endl;
						std::cout << "\t\t\t\tId do filme: " << it->getFilme().getId() << std::endl;
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
			Filme *filme_i = listaFilme->buscarFilme(indice_filme);
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\t\t\t\t\t|    CINECON - HORÁRIOS    |";
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\n\n\n\t\t\t\tHorario do filme: '" << filme_i->getNome() << "' : ";
			const time_t data = filme_i->getData();
			Sessao *sessao_i = listaSessao->findSessao(filme_i->getId());
			std::cout << " " << asctime(localtime(&data)) << "\n";
			std::cout << "\t\t\t\tPreço do filme: " << sessao_i->preco;
			std::cout << "\n\t\t\t\ttem certeza que deseja realizar a compra? (y/n): \n";
			std::string escolha;
			std::cin >> escolha;
			if (escolha == "y")
			{
				for (int i = 0; i < sessao_i->getAssentoDisp().size(); i++)
				{
					std::cout << "\t\t\t\t" << sessao_i->getAssentoDisp()[i].getId() << "\n";
				}
				std::cout << "\t\t\t\tQual assento você deseja? \n";
				std::string assentoId;
				std::cin >> assentoId;
				Bilhete *bilhete = new Bilhete(std::to_string(time(NULL) % rand()), sessao_i->preco, *sessao_i, assentoId);
				if (cliente->getIdade() < 18 || cliente->getPCD())
				{
					bilhete->setIsMeio(true);
					bilhete->setPreco(sessao_i->preco / 2);
				}
				cliente->getListaCompra().adicionarBilhete(*bilhete);
				system("read 0 -p");
			}
			else if (escolha == "n")
			{
			}
		}
		else if (aux_menu_cliente == 3)
		{
			system("clear");
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\t\t\t\t\t|    CINECON - COMPRAS     |";
			std::cout << "\n\t\t\t\t\t----------------------------";

			for (auto it = cliente->getListaCompra().getBilhetes().begin(); it != cliente->getListaCompra().getBilhetes().end(); ++it)
			{
				std::cout << "\n\t\t\t\t\tId: " << it->getId() << " -- Filme: " << it->getSessao().getFilme().getNome() << "\n";
			}
			std::string escolha;
			std::cout << "\n\t\t\t\tQual deseja retirar?\n";
			std::cin >> escolha;
			cliente->getListaCompra().removerBilhete(escolha);

			system("read 0 -p");
		}
		else if (aux_menu_cliente == 4)
		{
			FinalizarCompra(*cliente);
		}
		else if (aux_menu_cliente == 5)
		{
			system("clear");
			std::cout << "\n\t\t\t\t\t----------------------------";
			std::cout << "\n\t\t\t\t\t|    CINECON - BILHETES    |";
			std::cout << "\n\t\t\t\t\t----------------------------";

			for (auto it = cliente->getListaCompra().getBilhetes().begin(); it != cliente->getListaCompra().getBilhetes().end(); ++it)
			{
				std::cout << "\n\t\t\t\t\tAssento: " << it->getAssento().getId() << " -- Filme: " << it->getSessao().getFilme().getNome() << "\n";
			}
			system("read 0 -p");
		}
	} while (aux_menu_cliente != 6);
}

void AdcionarFilme()
{
	std::string nome, isDublado, is3d;
	int id, duracao;
	DataFilmeParams data;
	Filme *newFilme = new Filme();

	system("clear");
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\t\t| MENU ADMIN - CRIAR FILME |";
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\n\n\n\t\t\t. Insira o nome do novo filme: ";
	std::getline(std::cin>> std::ws, nome);
	std::cout << "\n\n\t\t\t. O filme é dublado? (y/n)";
	std::cin >> isDublado;
	if (isDublado == "y")
		filme->setDublado(true);
	else
		filme->setDublado(false);
	std::cout << "\n\n\t\t\t. O filme é 3D? (y/n) ";
	std::cin >> is3d;
	if (is3d == "y")
		filme->set3D(true);
	else
		filme->set3D(false);
	std::cout << "\n\n\t\t\t. Dia que vai passar: ";
	std::cin >> data.dia;
	std::cout << "\n\n\t\t\t. mes que vai passar: ";
	std::cin >> data.mes;
	std::cout << "\n\n\t\t\t. ano que vai passar: ";
	std::cin >> data.ano;
	std::cout << "\n\n\t\t\t. hora (ex: 13, 9...) que vai passar: ";
	std::cin >> data.hora;
	std::cout << "\n\n\t\t\t. minuto que vai passar: ";
	std::cin >> data.minuto;
	std::cout << "\n\n\t\t\t. Duração do filme (em minutos): ";
	std::cin >> duracao;

	filme->setData(data);
	filme->setDuracao(duracao * 60);
	filme->setNome(nome);
	filme->setId(std::to_string(rand()));
	system("clear");
	admin->createFilme(*filme, *listaFilme);
	std::cout << "Filme Adcionado com sucesso!" << std::endl;
	system("read 0 -p");
}
void RemoverFilme()
{
	std::string aux_id;
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\t\t|MENU ADMIN - EXCLUIR FILME|";
	std::cout << "\n\t\t\t\t\t----------------------------";
	for (Filme &filme : listaFilme->getLista())
	{
		std::cout << "\n\t\t\t\t\tId: " << filme.getId() << " -- Nome: " << filme.getNome() << "\n";
	}
	std::cout << "\n\n\n\n\t\t\t. Insira o ID do filme que será excluído: ";
	std::cin >> aux_id;
	admin->deleteFilme(aux_id, *listaFilme);
}

void AdcionarSala()
{
	std::string id;
	int qtd_assentos;

	system("clear");
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\t\t|  MENU ADMIN - CRIAR SALA |";
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\n\n\n\t\t\t. Insira o ID da nova sala: ";
	std::cin >> id;
	std::cout << "\n\n\t\t\t. Insira a quantidade de assentos da sala: ";
	std::cin >> qtd_assentos;

	admin->createSala(id, qtd_assentos, *listaSala);
	system("clear");
	std::cout << "\t\t\t\tSala inserida com Sucesso!!";
	system("read 0 -p");
}
void RemoverSala()
{
	std::string aux_id;
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\t\t|MENU ADMIN - EXCLUIR SALA |";
	std::cout << "\n\t\t\t\t\t----------------------------";
	for (Sala &sala : listaSala->getSalaList())
	{
		std::cout << "\n\t\t\t\t\tId: " << sala.getId() << "\n";
	}
	std::cout << "\n\n\n\n\t\t\t. Insira o ID da Sala que será excluída: ";
	std::cin >> aux_id;
	admin->deleteSala(aux_id, *listaSala);
}

void AdcionarSessao()
{

	std::string filme, sala, id;
	float preco;

	system("clear");
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\t\t| MENU ADMIN - CRIAR SESSÃO|";
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\n\n\n\t\t\t. Insira o ID da nova sessão: ";
	std::cin >> id;
	std::cout << "\n\n\t\t\t. Qual é o filme que será exibido nessa sessão? ";
	for (Filme &filme : listaFilme->getLista())
	{
		std::cout << "\n\t\t\t\t\tId: " << filme.getId() << " -- Nome: " << filme.getNome() << "\n";
	}
	std::cin >> filme;
	std::cout << "\n\n\t\t\t. Qual é a sala que será utilizada nessa sessão? ";
	for (Sala &sala : listaSala->getSalaList())
	{
		std::cout << "\n\t\t\t\t\tId: " << sala.getId() << "\n";
	}
	std::cin >> sala;
	std::cout << "\n\n\t\t\t. Insira o preço desta sessao: ";
	std::cin >> preco;
	const Filme &filme_r = *listaFilme->buscarFilme(filme);
	const Sala &sala_r = *listaSala->findSala(sala);
	admin->createSessao(filme_r, sala_r, id, preco, *listaSessao);
	system("clear");
	std::cout << "\t\t\t\tSessão inserida com Sucesso!!";
	system("read 0 -p");
}
void RemoverSessao()
{
	std::string aux_id;
	std::cout << "\n\t\t\t\t\t----------------------------";
	std::cout << "\n\t\t\t\t\t|MENU ADMIN - EXCLUIR SESSAO|";
	std::cout << "\n\t\t\t\t\t----------------------------";
	for (Sessao &Sessao : listaSessao->getSessoes())
	{
		std::cout << "\n\t\t\t\t\tId: " << Sessao.getId() << "\n";
	}
	std::cout << "\n\n\n\n\t\t\t. Insira o ID da Sessao que será excluída: ";
	std::cin >> aux_id;
	admin->deleteSessao(aux_id, *listaSessao);
}
void menu_admin()
{
	int aux_menu_admin = 1;
	do
	{
		system("clear");
		std::cout << "\n\t\t\t\t\t----------------------------";
		std::cout << "\n\t\t\t\t\t|   BEM-VINDO AO CINECON!  |";
		std::cout << "\n\t\t\t\t\t----------------------------";
		std::cout << "\n\n\n\n\t\t\t - Selecione o que quer fazer -";
		std::cout << "\n\n\n\n\t\t\t1. Adcionar Filme";
		std::cout << "\n\n\t\t\t2. Retirar Filme";
		std::cout << "\n\n\t\t\t3. Adcionar Sala";
		std::cout << "\n\n\t\t\t4. Retirar Sala";
		std::cout << "\n\n\t\t\t5. Adcionar Sessão";
		std::cout << "\n\n\t\t\t6. Remover Sessão";
		std::cout << "\n\n\t\t\t7. Sair\n\n\t\t\t";
		std::cin >> aux_menu_admin;

		switch (aux_menu_admin)
		{
		case 1:
		{
			try
			{
				AdcionarFilme();
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				system("pause");
			}

			break;
		}

		case 2:
		{
			try
			{
				RemoverFilme();
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				system("read 0 -p");
			}
			break;
		}

		case 3:
		{
			try
			{
				AdcionarSala();
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				system("read 0 -p");
			}

			break;
		}
		case 4:
		{
			try
			{
				RemoverSala();
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				system("read 0 -p");
			}
			break;
		}
		case 5:
		{
			try
			{
				AdcionarSessao();
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				system("read 0 -p");
			}

			break;
		}
		case 6:
		{
			try
			{
				RemoverSessao();
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				system("read 0 -p");
			}
			break;
		}
		}
	} while (aux_menu_admin != 7);
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	admin->createFilme(*filme, *listaFilme);

	admin->createSala(*sala, *listaSala);

	admin->createSessao(*sessao, *listaSessao);

	int select = 0;

	do
	{
		system("clear");
		std::cout << "\n\t\t\t\t\t----------------------------";
		std::cout << "\n\t\t\t\t\t| CINECON - MENU DE ACESSO |";
		std::cout << "\n\t\t\t\t\t----------------------------";
		std::cout << "\n\n\n\n\t\t\t- Selecione o seu tipo de acesso -";
		std::cout << "\n\n\n\n\t\t\t1. Acesso de Cliente";
		std::cout << "\n\n\t\t\t2. Acesso Admin";
		std::cout << "\n\n\t\t\t3. Sair\n\n\n\n\t\t\t";

		std::cin >> select; // Verifica a tecla pressionada no teclado

		if (select == 1)
		{ // Caso a tecla pressionada seja 1
			system("clear");
			std::cout << "INSIRA O NOME DE USUARIO: ";
			std::string nome;
			std::getline(std::cin>> std::ws, nome);
			std::cout << "INSIRA O IDADE DO USUARIO: ";
			int idade;
			std::cin >> idade;
			std::cout << "O USUARIO POSSUI ALGUM TIPO DE DEFICIÊNCIA?(y/n): ";
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
			system("clear");
			int tentativas = 0;
			do
			{
				std::cout << "INSIRA A SENHA DE ADMIN\t(default: 0000)\n";
				std::string senha;
				std::cin >> senha;
				if (senha == admin->getSenha())
				{
					menu_admin();
					tentativas = 3;
				}
				else
				{
					++tentativas;
					system("clear");
					std::cout << "\n\nsenha invalida!\n\n";
				}
			} while (tentativas < 3);
		}
	} while (select != 3);

	return 0;
}
