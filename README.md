# Cinecon - Sistema de Gerenciamento de Cinema

O Cinecon é um sistema de gerenciamento de cinema que permite aos usuários realizar diversas operações, como visualizar os filmes em cartaz, adicionar ingressos ao carrinho, remover ingressos do carrinho, realizar compras e listar os ingressos no carrinho. O sistema também oferece funcionalidades específicas para administradores, como adicionar e remover filmes.

## Funcionalidades do Cliente

O menu do cliente oferece as seguintes opções:

1. Ver filmes em cartaz: Esta opção permite visualizar os filmes disponíveis no cinema.
2. Adicionar ingresso no carrinho: Permite adicionar ingressos ao carrinho de compras.
3. Retirar do carrinho: Permite remover ingressos do carrinho.
4. Realizar compra: Finaliza a compra dos ingressos adicionados ao carrinho.
5. Listar ingressos no carrinho: Exibe os ingressos atualmente no carrinho.
6. Sair: Encerra o programa.

## Funcionalidades do Administrador

O menu do administrador oferece as seguintes opções:

1. Adicionar filme: Permite adicionar um novo filme ao sistema, informando seu nome, se é dublado e se é em 3D, além de outros detalhes.
2. Remover filme: Permite remover um filme existente no sistema, informando o seu ID.

## Como compilar e executar o programa

Para compilar e executar o programa, siga as instruções abaixo:

1. Certifique-se de ter instalado um compilador C++ em seu sistema. \
   1.1 Caso não seja o g++ troque no makefile e certifique-se se as flags passadas existem.
2. Baixe todos os arquivos necessários para a compilação, incluindo o arquivo Makefile.
3. No terminal, navegue até o diretório onde os arquivos estão localizados.
4. Execute o seguinte comando para compilar o programa: `make`.
5. Após a compilação, execute o programa com o seguinte comando: `./CineCon`.

Certifique-se de que as variáveis `CC` e `CFLAGS` no Makefile estejam configuradas corretamente, de acordo com as especificações do seu sistema.

## Requisitos do Sistema

O programa requer um compilador C++ compatível e suporte a bibliotecas como `iostream`, `string` e `stdlib.h`.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).
