/*
	Inserção, busca, grau do noh, percurso (Pré, In, Pós);
	---> Busca (prova), remoção e outras funções
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Seed no rand()

typedef struct noh {
	int info;
	struct noh* esq; //Esquerda (menor)
	struct noh* dir; //Direita (maior)
} Noh;

Noh* cria_Noh(int chave);
Noh* insere(Noh* raiz, Noh* novo);
Noh* busca_Binaria(Noh* raiz, int x);
int grau_Noh(Noh* raiz, int x);
int grau_Arvore(Noh* raiz);
void percurso_PreOrdem(Noh* raiz);
void percurso_InOrdem(Noh* raiz);
void percurso_PosOrdem(Noh* raiz);

Noh* cria_Noh(int chave) {
	Noh* novo = (Noh*) malloc(sizeof(Noh));

	if (novo == NULL) {
		printf("Erro.\n");
		return NULL;
	}
	else {
		novo->info = chave;
		novo->esq = NULL;
		novo->dir = NULL;
		return novo;
	}
}

//O noh inserido sempre sera uma folha
Noh* insere(Noh* raiz, Noh* novo) {

	if (raiz == NULL) {
		return novo;
	}
	else {
		//Se a chave do novo noh for menor
		if (novo->info < raiz->info) {
			//Se somente retornar, a recursao nao retorna e raiz fica apontando
			//para o ultimo elemento inserido
			raiz->esq = insere(raiz->esq, novo);
		}
		//Se a chave do novo noh for maior
		else if (novo->info > raiz->info) {
			raiz->dir = insere(raiz->dir, novo);
		}
		return raiz;
	}
}

//Fazer com um ponteiro que retorna para o pai do noh encontrado
//Caso nao seja encontrado, retornar o noh que seria o pai do noh (caso inserido)
Noh* busca_Binaria(Noh* raiz, int x) {

	//Caso a arvore seja vazia ou nao encontre o elemento
	if (raiz == NULL) {
		return NULL;
	}
	//Condicao de parada para a recursividade
	else if (x == raiz->info) {
		printf("Encontrado!\n");
		return raiz;
	}
	else {
		//Caso x seja maior que raiz->info
		if (x > raiz->info) {
			return busca_Binaria(raiz->dir, x);
		}
		//Caso x seja menor que raiz->info
		else {
			return busca_Binaria(raiz->esq, x);
		}
	}
}

int grau_Noh(Noh* raiz, int x) {

	Noh* buscado = busca_Binaria(raiz, x);
	int grau = 0;

	if (buscado == NULL) {
		printf("Erro.\n");
		return NULL;
	}
	//Duvida ---> esse condicional ta certo???
	else {
		if (buscado->dir != NULL) {
			if (buscado->esq == NULL) {
				grau = 1;
			}
			else {
				grau = 2;
			}
		}
		else if (buscado->esq != NULL) {
			if (buscado->dir == NULL) {
				grau = 1;
			}
			else {
				grau = 2;
			}
		}
	}
	return grau;
}

int grau_Arvore(Noh* raiz) {
	Noh* atual;
	//Unfinished (!!!)
	//Se passar por um noh e seu grau for 2 -> retorna 2
	//Se tiver um noh -> retorna 0
	//Se todos os nohs (ou ao menos um) tiverem grau 1 -> retorna 1
}

int altura_Arvore(Noh* raiz) {
	int alturaDir = 1;
	int alturaEsq = 1;

	if (raiz->esq != NULL) {
		alturaEsq += altura_Arvore(raiz->esq);
	}
	else if (raiz->dir != NULL) {
		alturaDir += altura_Arvore(raiz->dir);
	}

	printf("Noh: %d.\t", raiz->info);

	if (alturaDir >= alturaEsq) {
		printf("Altura: %d.\n", alturaDir);
		return alturaDir;
	}
	else {
		printf("Altura: %d.\n", alturaEsq);
		return alturaEsq;	
	}
}

//Raiz - Esquerda - Direita
void percurso_PreOrdem(Noh* raiz) {

	//Enquanto tiver nohs a percorrer
	if (raiz != NULL) {
		printf("%d.\t", raiz->info);
		percurso_PreOrdem(raiz->esq);
		percurso_PreOrdem(raiz->dir);
	}
}

//Esquerda - Raiz - Direita
void percurso_InOrdem(Noh* raiz) {

	//Enquanto tiver nohs a percorrer
	if (raiz != NULL) {
		percurso_InOrdem(raiz->esq);
		printf("%d.\t", raiz->info);
		percurso_InOrdem(raiz->dir);
	}
}

//Esquerda - Direita - Raiz
void percurso_PosOrdem(Noh* raiz) {

	//Enquanto tiver nohs a percorrer
	if (raiz != NULL) {
		percurso_PosOrdem(raiz->esq);
		percurso_PosOrdem(raiz->dir);
		printf("%d.\t", raiz->info);
	}
}



int main() {
	Noh* raiz = NULL;
	Noh* novo = NULL;
	Noh* buscado = NULL;
	int grau, x, option, chave, i;
	int arvore[7] = {25, 15, 5, 20, 50, 60, 35};

	do {
		printf("\n1) Inserir\n");
		printf("2) Buscar\n");
		printf("3) Grau do noh\n");
		printf("4) Grau da arvore\n");
		printf("5) Pre Ordem\n");
		printf("6) In Ordem\n");
		printf("7) Pos Ordem\n");
		printf("8) Inserir com arvore[7]\n");
		printf("9) Sair\n");
		printf("O que deseja?\t");
		scanf("%d", &option);

		switch(option) {
			case 1:
				printf("Chave:\t");
				scanf("%d", &chave);
				novo = cria_Noh(chave);
				raiz = insere(raiz, novo);
				break;
			case 2:
				printf("Buscar:\t");
				scanf("%d", &x);
				buscado = busca_Binaria(raiz, x);
				break;
			case 3:
				printf("Grau de:\t");
				scanf("%d", &x);
				grau = grau_Noh(raiz, x);
				printf("Grau -> %d.\n", grau);
				break;
			case 4:
				//Imprimir o grau maximo da arvore
				break;
			case 5:
				percurso_PreOrdem(raiz);
				break;
			case 6:
				percurso_InOrdem(raiz);
				break;
			case 7:
				percurso_PosOrdem(raiz);
				break;
			case 8:
				for (i=0; i<7; i++) {
					chave = arvore[i];
					novo = cria_Noh(chave);
					raiz = insere(raiz, novo);
				}
				break;
			case 9:
				return 0;
		}
	} while (option != 9);
}




