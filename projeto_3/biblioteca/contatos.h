#ifndef CONTATOS_H
#define CONTATOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contatos{

  char nome_completo[101];
  char celular[11];
  char endereco[101];
  unsigned int CEP;
  char data_de_nascimento[11];

  struct contatos *anterior;
  struct contatos *proximo;
}Contatos;

/* Operacoes permitidadas para a lista de contatos */

void menu(int *);
Contatos *insertionSort(Contatos *,Contatos *);//percorrer a lista de contatos e organiza-la em ordem alfabetica
FILE *criaArquivoContatos_txt(); //para o caso do programa nao conseguir abrir o arquivo existente ou se nao houver arquivo pre existente. Retorna null se deu errado, ou um ponteiro para o arquivo, se deu certo
Contatos *criaContatosVazia();
Contatos *inserirNovoRegistro(Contatos *); //retorna 1 se inseriu corretamente, 0 caso contrario. Deve chamar a funcao criaElemento e a funcao de ordenacao
Contatos **adicionaContatosDoArquivo(FILE *); //caso de errado, retorna 0;
void liberaContatos(Contatos *); //liberar a partir do primeiro contato
int removerContatosPorString(char *, Contatos *); //retorna 1 se removeu, 0 caso contrario. Deve percorrer a lista e tentar remover aquele nome, depois reordenar a lista
Contatos *visualizarContatosPorString(char *, Contatos *); //retorna um ponteiro para o contato, se ele existe, ou null caso contrario. Deve percorrer a lista para achar o contato
void visualizarTodosOsContatos(Contatos *primeiroContato); //pesquisar na lista qual o primeiro contato(*anterior==null) e printar a partir dele;
void sair(FILE *, Contatos *); // salvar todos os contatos, em ordem, no arquivo contatos.txt ou no arquivo possivelmente criado

#endif
