/*
	Enfileirar, desenfileirar, comprimento, próximo
*/

#include "fila.h"

//Implementacao dos prototipos do .h
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

//Problema com a insercao de um noh no final da lista
Noh* Enfileirar(Noh* fila, int x) {
	Noh* novo = cria_Noh(x);
	Noh* aux = fila;

	//Insere o noh no final
	if (fila == NULL) {
		return novo;
	}
	else {
		//Percorre a lista ate chegar no ultimo elemento
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
		return fila;
	}
}

Noh* Desenfileirar(Noh* fila) {
	Noh* aux = fila;

	if (fila == NULL) {
		printf("Fila vazia.\n");
		return NULL;
	}
	else {
		fila = aux->prox;
		aux->prox = NULL;
		free(aux);
		return fila;
	}
}

Noh* Proximo(Noh* fila) {
	Noh* aux = fila;

	if (fila == NULL) {
		printf("Fila vazia.\n");
		return NULL;
	}
	else {
		return aux;
	}
}

int Comprimento(Noh* fila) {
	Noh* aux = fila;
	int i = 0;

	if (fila == NULL) {
		printf("Fila vazia.\n");
		return NULL;
	}
	else {
		while (aux != NULL) {
			aux = aux->prox;
			i++;
		}
		return i;
	}
}

void exibir_Fila(Noh* fila) {
	Noh* aux = fila;

	if (fila == NULL) {
		printf("Fila vazia.\n");
	}
	else {
		while (aux != NULL) {
			printf("%d.\t", aux->info);
			aux = aux->prox;
		}
	}
}