/*
	Enfileirar - inicio e fim, desenfileirar - inicio e fim, próximo e último, comprimento
*/

#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct noh {
	int info;
	struct noh *prox;
} Noh;

Noh* cria_Noh(int x);
Noh* enfileirar_Inicio(Noh* deque, int x);
Noh* enfileirar_Fim(Noh* deque, int x);
Noh* desenfileirar_Inicio(Noh* deque);
Noh* desenfileirar_Fim(Noh* deque);
void comprimento_Deque(Noh* deque);
void PrimeiroUltimo_Deque(Noh* deque);
void exibe_Deque(Noh* deque);

#endif