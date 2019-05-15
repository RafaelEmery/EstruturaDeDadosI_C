/*
	Autor: Rafael Emery
	Objetivo: Criar uma LDE que faz as seguuintes operações:
	- Percurso;
	- Busca ordenada;
	- Busca desordenada;
	- Busca pelo menor;
	- Inserção;
	- Remoção;

	Data: 08/12/2018
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Noh {
	int info;
	struct Noh* ant;
	struct Noh* prox;
} Noh_Duplo;

Noh_Duplo* cria_Noh(int valor);
Noh_Duplo* insere_Noh(Noh_Duplo* Lista, int valor);
Noh_Duplo* busca_Ordenada(Noh_Duplo* Lista, int chave);
Noh_Duplo* busca_Normal(Noh_Duplo* Lista, int chave);
Noh_Duplo* remove_Noh(Noh_Duplo* Lista, int chave);
void busca_Menor(Noh_Duplo* Lista);
void exibe_Lista(Noh_Duplo* Lista);

Noh_Duplo* cria_Noh(int valor) {

	Noh_Duplo* novo = (Noh_Duplo*) malloc(sizeof(Noh_Duplo));

	if (novo == NULL) {
		printf("Erro.\n");
		return NULL;
	}
	else {
		novo->info = valor;
		novo->ant = NULL;
		novo->prox = NULL;
		return novo;
	}
}

Noh_Duplo* insere_Noh(Noh_Duplo* Lista, int valor) {

	Noh_Duplo* novo = cria_Noh(valor);
	Noh_Duplo* aux = Lista;

	if (Lista == NULL) {
		return novo;
	}
	else if (Lista->prox == NULL) {
		novo->ant = aux;
		aux->prox = novo;
		return Lista;
	}
	else {
		//Nesse caso, realiza a insercao no final
		//Loop que percorre o aux ate o ultimo noh
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		novo->ant = aux;
		aux->prox = novo;
		return Lista;
	}
}

Noh_Duplo* busca_Normal(Noh_Duplo* Lista, int chave) {

	Noh_Duplo* aux = Lista;
	int i = 0;

	if (Lista == NULL) {
		printf("Lista vazia.\n");
		return NULL;
	}
	else {
		while (aux != NULL) {
			if (aux->info == chave) {
				return aux;
			}
			aux = aux->prox;
			i++;
		}
		return NULL;
	}
}

Noh_Duplo* remove_Noh(Noh_Duplo* Lista, int chave) {

	Noh_Duplo* noh_Buscado = busca_Normal(Lista, chave);

	//Caso nao exista o noh
	if (noh_Buscado == NULL) {
		printf("Inexistente.\n");
		return Lista;
	}
	//Caso seja o unico noh da lista
	else if (noh_Buscado->ant == NULL && noh_Buscado->prox == NULL) {
		free(noh_Buscado);
		return NULL;
	}
	else {
		//Caso seja o primeiro noh
		if (noh_Buscado->ant == NULL) {
			Lista = noh_Buscado->prox;
			noh_Buscado->prox = NULL;
			free(noh_Buscado);
			return Lista;
		}
		//Caso seja o ultimo noh
		else if (noh_Buscado->prox == NULL) {
			noh_Buscado->ant->prox = NULL;
			noh_Buscado->ant = NULL;
			free(noh_Buscado);
			return Lista;
		}
		//Caso esteja no meio
		else {
		noh_Buscado->ant->prox = noh_Buscado->prox;
		noh_Buscado->prox->ant = noh_Buscado->ant;
		noh_Buscado->prox = NULL;
		noh_Buscado->ant = NULL;
		free(noh_Buscado);
		return Lista;
		}
	}
}

void busca_Menor(Noh_Duplo* Lista) {

	Noh_Duplo* aux = Lista;
	Noh_Duplo* menor = aux;

	if (Lista == NULL) {
		printf("Lista vazia.\n");
	}
	else {
		while (aux != NULL) {
			if (aux->info < menor->info) {
				menor = aux;
			}
			aux = aux->prox;
		}
		printf("\n\nO menor elemento e %d!\n", menor->info);
	}
}

void exibe_Lista(Noh_Duplo* Lista) {

	Noh_Duplo* aux = Lista;

	if (Lista == NULL) {
		printf("Lista vazia.\n");
	}
	else {
		while (aux != NULL) {
			printf("%d.\n", aux->info);
			aux = aux->prox;
		}
	}
}

int main() {

	Noh_Duplo* Lista = NULL;
	int i, valor, chave;

	srand((unsigned) time(NULL));

	//Gerando a lista
	for (i=0; i<10; i++) {
		valor = rand() % 500;
		Lista = insere_Noh(Lista, valor); //Insere um noh no fim da lista
	}

	exibe_Lista(Lista); //Imprime a lista

	busca_Menor(Lista);

	printf("\n\nEntre com a chave:\t");
	scanf("%d", &chave);

	Lista = remove_Noh(Lista, chave);

	exibe_Lista(Lista);

	return 0;

}

/*
Prova 1 -> Questão 2 - b) 
Noh_Duplo* remove_PrimeiroNoh(Noh* Lista) {
	Noh_Duplo* aux = Lista;
	
	if (Lista == NULL) {
		printf("Lista vazia");
		return NULL;
	}
	else {
		Lista = aux->prox;
		aux->prox = NULL;
		free(aux);
		return Lista;
	}	
}
*/
