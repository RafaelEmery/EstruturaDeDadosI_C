/*
	Empilhar, desempilhar, topo e altura!!!
*/

#ifndef PILHA_H //Chave para definir o .h
#define PILHA_H

//Importando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Estrutura usada para os nohs
typedef struct noh {
	int info;
	struct noh *prox;
} Noh;

//Prototipo das funcoes que serao usadas no .c
Noh* cria_Noh(int x);
Noh* Empilhar(Noh* pilha, int x);
Noh* Desempilhar(Noh* pilha);
Noh* Topo(Noh* pilha);
int Altura(Noh* pilha);
void exibe_Pilha(Noh* pilha);

#endif //Encerrando o #ifndef

