/*
	Empilhar, desempilhar, topo e altura!!!
*/

#include "pilha.h" //Chamando o arquivo .h

//Implementacoes dos prototipos do .h
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

Noh* Empilhar(Noh* pilha, int x) {
	Noh* novo = cria_Noh(x);

	//Realizando a insercao no inicio
	if (pilha == NULL) {
		return novo;
	}
	else {
		novo->prox = pilha;
		return novo;
	}
}

Noh* Desempilhar(Noh* pilha) {
	Noh* aux = pilha;

	//Realizando a remocao no inicio
	if (pilha == NULL) {
		printf("Pilha vazia.\n");
		return NULL;
	}
	else {
		pilha = pilha->prox; //Passando pilha para o segundo noh
		aux->prox = NULL; 
		free(aux); //Liberando aux da memoria
		return pilha;
	}
}

Noh* Topo(Noh* pilha) {

	//Retorna o primeiro elemento da pilha (topo)
	if (pilha == NULL) {
		printf("Pilha vazia.\n");
		return NULL;
	}
	else {
		return pilha;
	}
}

int Altura(Noh* pilha) {
	Noh* aux = pilha;
	int i = 0;

	if (pilha == NULL) {
		printf("Pilha vazia.\n");
		return 0;
	}
	else {
		while (aux != NULL) {
			aux = aux->prox;
			i++;
		}
		return i;
	}
}

void exibir_Pilha(Noh* pilha) {
	Noh* aux = pilha;

	if (pilha == NULL) {
		printf("Pilha vazia.\n");
	}
	else {
		while (aux != NULL) {
			printf("%d.\n", aux->info);
			aux = aux->prox;
		}
	}
}


