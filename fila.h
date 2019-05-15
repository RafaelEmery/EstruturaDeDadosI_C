/*
	Enfileirar, desenfileirar, comprimento, próximo
*/

#ifndef FILA_H //Chave para definir o .h
#define FILA_H

//Importacao de bibliotecas
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

//Estrutura dos nohs da fila
typedef struct noh {
	int info;
	struct noh *prox;
} Noh;

//Prototipo das funcoes que serao usadas no .c
Noh* cria_Noh(int x);
Noh* Enfileirar(Noh* fila, int x);
Noh* Desenfileirar(Noh* fila);
Noh* Proximo(Noh* fila);
int Comprimento(Noh* fila);
void exibir_Fila(Noh* fila);

#endif //Fechando a definicao do .h
