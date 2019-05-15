/*
	Enfileirar - inicio e fim, desenfileirar - inicio e fim, próximo e último, comprimento
*/

#include "deque.h"

Noh* cria_Noh(int x) {
	Noh* novo = (Noh*) malloc(sizeof(Noh));

	if (novo == NULL) {
		printf("Erro.\n");
		return NULL;
	}
	else {
		novo->info = x;
		novo->prox = NULL;
		return novo;
	}
}

Noh* enfileirar_Inicio(Noh* deque, int x) {
	Noh* novo = cria_Noh(x);

	if (deque == NULL) {
		return novo;
	}	
	else {
		novo->prox = deque;
		return novo;
	}
}

Noh* enfileirar_Fim(Noh* deque, int x) {
	Noh* novo = cria_Noh(x);
	Noh* aux = deque;

	if (deque == NULL) {
		return novo;
	}
	else {
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
		return deque;
	}
}

Noh* desenfileirar_Inicio(Noh* deque) {
	Noh* aux = deque;

	if (deque == NULL) {
		printf("Deque vazio\n");
		return NULL;
	}	
	else {
		deque = aux->prox;
		aux->prox = NULL;
		free(aux);
		return deque;
	}
}

Noh* desenfileirar_Fim(Noh* deque) {
	Noh* aux1 = deque;
	Noh* aux2 = deque->prox;

	if (deque == NULL) {
		printf("Deque vazio\n");
		return NULL;
	}
	else {
		while (aux2->prox != NULL) {
			aux1 = aux2;
			aux2 = aux2->prox;
		}
		aux1->prox = NULL;
		free(aux2);
		return deque;
	}
}

void comprimento_Deque(Noh* deque) {
	Noh* aux = deque;
	int i = 0;

	if (deque == NULL) {
		printf("Deque vazio\n");
		return NULL;
	}
	else {
		while (aux != NULL) {
			aux = aux->prox;
			i++;
		}
		printf("Comprimento -> %d \n", i);
	}
}

void PrimeiroUltimo_Deque(Noh* deque) {
	Noh* aux = deque;

	if (deque == NULL) {
		printf("Deque vazio\n");
		return NULL;
	}
	else {
		printf("Primeiro -> %d \n", deque->info);

		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		printf("Ultimo -> %d \n", aux->info);
	}
}

void exibe_Deque(Noh* deque) {
	Noh* aux = deque;

	if (deque == NULL) {
		printf("Deque vazio\n");
		return NULL;
	}
	else {
		while (aux != NULL) {
			printf("%d \t", aux->info);
			aux = aux->prox;
		}
	}
}

