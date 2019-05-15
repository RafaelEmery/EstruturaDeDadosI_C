/*
	Autor: Rafael Emery
	Objetivo: Fazer uma lista simplesmente encadeada (LSE) que realize os
	seguintes procedimentos:
	- Inserção
	- Remoção
	- Busca de um elemento (ordenada)
	- Busca de um elemento (desordenada)
	- Busca pelo menor elemento

	Data: 05/12/2018
*/

//Importacao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tipo_Info int

//Definindo as estruturas
typedef struct noh {
	tipo_Info info;
	struct noh* prox;
} Tipo_Noh;

//Prototipo das funcoes
Tipo_Noh* cria_Noh(tipo_Info valor);
Tipo_Noh* insere_Noh(Tipo_Noh* Lista, tipo_Info valor);
Tipo_Noh* busca_Desordenada(Tipo_Noh* Lista, tipo_Info elemento_X);
Tipo_Noh* remove_Noh(Tipo_Noh* Lista, tipo_Info elemento_X);
Tipo_Noh* ordena_Lista(Tipo_Noh* Lista);
Tipo_Noh* busca_Menor(Tipo_Noh* Lista);
Tipo_Noh* busca_Ordenada(Tipo_Noh* Lista, tipo_Info elemento_X);
Tipo_Noh* remove_Noh_Par(Tipo_Noh* Lista);
Tipo_Noh* intercala_Listas(Tipo_Noh* Lista1, Tipo_Noh* Lista2, Tipo_Noh* Lista3);
Tipo_Noh* intercala_Listas_Inversa(Tipo_Noh* Lista1, Tipo_Noh* Lista2, Tipo_Noh* Lista3);
void destroi_Lista(Tipo_Noh* Lista);
void imprime_Lista(Tipo_Noh* Lista);
void imprime_Inversa(Tipo_Noh* Lista);
int tamanho_Lista(Tipo_Noh* Lista);

//Implementacao das funcoes
//Aloca memoria dinamicamente e atribui valor ao noh
Tipo_Noh* cria_Noh(tipo_Info valor) {

	Tipo_Noh* novo = (Tipo_Noh*) malloc(sizeof(Tipo_Noh));

	//Verificando a memoria alocada dinamicamente
	if (novo == NULL) {
		//Caso o malloc() nao funcione
		printf("Erro.\n");
		return NULL;
	}
	else {
		//Inicializando o novo noh
		novo->info = valor;
		novo->prox = NULL;
		return novo;
	}
}

//Insere o noh a lista
Tipo_Noh* insere_Noh(Tipo_Noh* Lista, tipo_Info valor) {

	Tipo_Noh* novo = cria_Noh(valor);

	//Verificando se e o primeiro noh
	if (Lista == NULL) {
		return novo;
	}
	else {
		//Aponta o prox para o primeiro noh
		novo->prox = Lista;
		return novo;
	}
}

//Realiza uma busca na lista desordenada
Tipo_Noh* busca_Desordenada(Tipo_Noh* Lista, tipo_Info elemento_X) {

	Tipo_Noh* aux = Lista;
	int i = 0;

	//Caso a lista seja vazia
	if (Lista == NULL) {
		printf("Lista vazia.\n");
		return Lista;
	}
	else {
		//Loop para fazer a busca
		while(aux->prox != NULL) {
			//Verificando os elementos
			if (elemento_X == aux->info) {
				printf("Encontrado! Elemento %d -> %d. \n", elemento_X, i+1);
				return aux;
			}
			//Percorrendo a lista
			aux = aux->prox;
			i++;
		}
		//Caso nao encontre o elemento no percurso
		printf("Nao encontrado!\n");
		return NULL;
	}
}

//Realiza uma busca do noh e o remove
Tipo_Noh* remove_Noh(Tipo_Noh* Lista, tipo_Info elemento_X) {

	Tipo_Noh* aux = Lista->prox;
	Tipo_Noh* aux_Anterior = Lista;

	//Caso esteja vazia
	if (Lista == NULL) {
		printf("Lista vazia.\n");
		return Lista;
	}
	else {
		//Percorre a lista em busca do elemento
		while (aux != NULL) {
			if (aux->info == elemento_X) {
				//Realiza a remocao
				aux_Anterior->prox = aux->prox;
				aux->prox = NULL;
				printf("Encontrado e removido!\n");
				free(aux);
				return Lista;
			}
			aux_Anterior = aux;
			aux = aux->prox;
		}
		printf("Nao encontrado!\n");
		return Lista;
	}
}

//Usa o metodo bubblesort para ordenar a lista
//Porém, esse método sobrescreve os elementos dentro dos nohs
// * NAO TESTADO *
Tipo_Noh* ordena_Lista(Tipo_Noh* Lista) {

	Tipo_Noh* ptr_Atual = Lista; //Sera o elemento analisado
	Tipo_Noh* ptr_Prox = Lista->prox; //Sera o posterior ao elemento
	int n = tamanho_Lista(Lista); //n recebe o tamanho da lista
	int aux = 0; //aux para fazer o swap dos elementos
	int i, j;

	if (Lista == NULL) {
		printf("Lista vazia.\n");
		return NULL;
	}
	else {
		for (i=0; i<n; i++) {
			for(j=0; j<n-1; j++) {
				if (ptr_Atual->info > ptr_Prox->prox) { //FOR OU WHILE (AUX->PROX != NULL) ?????
					//Realiza o swap dos elementos
					aux = ptr_Atual->info;
					ptr_Atual->info = ptr_Prox->info;
					ptr_Prox->info = aux;
				}
				//Percorrendo os ponteiros e passando para o proximo par
				ptr_Atual = ptr_Atual->prox;
				ptr_Prox = ptr_Prox->prox;
			}
			//Reinicializando os ponteiros para voltar para o comeco da lista
			ptr_Atual = Lista;
	 		ptr_Prox = Lista->prox;
		}
		return Lista;
	}
}
//  _	_	_
//  |	|	|
//  |	|	|
//  V 	V 	V
//Para ordenar decrescente, basta inverter o ">" para colocar os menores no fim

//Encontra o menor noh da lista
Tipo_Noh* busca_Menor(Tipo_Noh* Lista) {

	//O menor recebe o primeiro elemento da lista
	Tipo_Noh* menor = Lista->prox;
	Tipo_Noh* aux = Lista->prox;

	if (Lista == NULL) {
		printf("Lista vazia.\n");
		return NULL;
	}
	else if (aux->prox == NULL) {
		return menor;
	}
	else {
		//Loop que percorre a lista e compara o aux com o menor
		while (aux != NULL) {
			if (aux->info < menor->info) {
				menor = aux;
			}
			aux = aux->prox;
		}
		return menor;
	}
}

//Considerando que a lista esteja ordenada, realiza a busca (mais otimizada)
Tipo_Noh* busca_Ordenada(Tipo_Noh* Lista, tipo_Info elemento_X) {

	Tipo_Noh* ant = Lista;
	Tipo_Noh* pont = Lista->prox;

	if (Lista == NULL) {
		printf("Lista vazia.\n");
		return NULL;
	}
	else {
		while (pont != NULL) {
			if (pont->info == elemento_X) {
				printf("Encontrado. Noh retornado!\n");
				return pont;
			}
			else if (pont->info > elemento_X) {
				printf("Nao encontrado! Porem retornando o que seria anterior!\n");
				return ant;
			}
			else {
				ant = pont;
				pont = pont->prox;
			}
		}
		printf("Nao encontrado!\n");
		return NULL;
	}
}

//Remove todos os nohs pares da lista
Tipo_Noh* remove_Noh_Par(Tipo_Noh* Lista) {

	Tipo_Noh* ant = Lista;
	Tipo_Noh* pont = Lista->prox;
	int i = 0;

	printf("*** LISTA ANTIGA ***\n");
	imprime_Lista(Lista);

	//Caso a lista esteja vazia
	if (Lista == NULL) {
		printf("Lista vazia.\n");
		return NULL;
	}
	//Caso a lista so tenha um noh
	else if (Lista->prox == NULL) {
		//Nada ira acontecer pois i=1 eh impar!
		return Lista;
	}
	else {
		while (pont != NULL) {
			if (i % 2 != 0) {
				ant = pont;
				pont = pont->prox;
				i++;
			}
			//Caso seja par
			else {
				//Caso seja o ultimo
				if (pont->prox == NULL) {
					ant->prox = NULL;
					free(pont);
					i++;
					return Lista;
				}
				else {
					//Remocao de um elemento de meio
					ant->prox = pont->prox;
					ant = pont;
					pont = pont->prox;
					ant->prox = NULL;
					i++;
				}
			}
		}
		return Lista;
	}
}

//Funcao recebe duas listas e retorna uma terceira intercalada
Tipo_Noh* intercala_Listas(Tipo_Noh* Lista1, Tipo_Noh* Lista2, Tipo_Noh* Lista3) {
	Tipo_Noh* aux = Lista3->prox; //Variavel auxiliar para apontar para a lista 3
	int i = 0; //Contador para definir se eh impar ou par

	// Lista1 = Lista1->prox;
	// Lista2 = Lista2->prox;

	while (Lista1 != NULL && Lista2 != NULL) {
		if (i % 2 == 0) {
			aux->prox = Lista1;
			aux = aux->prox; //Percorrendo a Lista 3
			Lista1 = Lista1->prox; //Percorrendo a Lista 1
		}
		else {
			aux->prox = Lista2;
			aux = aux->prox;
			Lista2 = Lista2->prox;
		}
		i++;
	}
	//Caso a Lista 1 seja maior
	if (Lista1 != NULL) {
		aux->prox = Lista1; //Aponta aux para o resto da lista
	}
	//Caso a Lista 2 seja maior
	else if (Lista2 != NULL) {
		aux->prox = Lista2;
	}
	return Lista3; //Retorna um ponteiro para Lista 3
}

//Funcao intercala as listas inversamente
//Recebe
Tipo_Noh* intercala_Listas_Inversa(Tipo_Noh* Lista1, Tipo_Noh* Lista2, Tipo_Noh* Lista3) {
	Tipo_Noh* aux;
	int i = 0; //Contador para definir se eh impar ou par

	while (Lista1 != NULL && Lista2 != NULL) {
		if (i % 2 == 0) {
			//Insere o noh da lista 1 no inicio de lista 3
			aux = Lista1;
			Lista1 = aux->prox;
			aux->prox = Lista3;
			Lista3 = aux;
		}
		else {
			//Insere o noh da lista 2 no inicio da lista 3
			aux = Lista2;
			Lista2 = aux->prox;
			aux->prox = Lista3;
			Lista3 = aux;
		}
		i++;
	}
	//Caso a Lista 1 seja maior
	if (Lista1 != NULL) {
		while (Lista1 != NULL) {
			aux = Lista1;
			Lista1 = aux->prox;
			aux->prox = Lista3;
			Lista3 = aux;
		}
	}
	//Caso a Lista 2 seja maior
	else if (Lista2 != NULL) {
		while (Lista2 != NULL) {
			aux = Lista2;
			Lista2 = aux->prox;
			aux->prox = Lista3;
			Lista3 = aux;
		}
	}
	return Lista3; //Retorna um ponteiro para Lista 3
}


//Destroi a lista - remove todos os nohs
void destroi_Lista(Tipo_Noh* Lista) {

	Tipo_Noh* aux = Lista->prox;

	if (Lista == NULL) {
		printf("Lista vazia. Destruicao completa!\n");
	}
	else {
		Lista->prox = aux->prox;
		aux->prox = NULL;
		free(aux);
		printf("Destruindo... %d.\n", aux->info);
	}
}

//Imprime a lista
void imprime_Lista(Tipo_Noh* Lista) {

	Tipo_Noh* aux = Lista;

	//Caso a lista seja vazia
	if (Lista == NULL) {
		printf("Lista vazia.\n");
	}
	else {
		//Percurso que imprime os elementos e suas posicoes
		while (aux != NULL) {
			printf("%d. \t", aux->info);
			aux = aux->prox;
		}
	}
}

//Imprime a lista de maneira inversa
void imprime_Inversa(Tipo_Noh* Lista) {

	Tipo_Noh* aux = Lista->prox;

	if (aux->prox != NULL) {
		imprime_Inversa(aux);
		printf("%d. \t", aux->info);
	}
	else {
		printf("%d. \t", aux->info);
	}
}

//Funcao que retorna o tamanho da lista
int tamanho_Lista(Tipo_Noh* Lista) {

	Tipo_Noh* aux = Lista;
	int i = 0;

	//Caso a lista seja vazia
	if (Lista == NULL) {
		printf("Lista vazia.\n");
		return 0;
	}
	else {
		//Percurso que imprime os elementos e suas posicoes
		while (aux != NULL) {
			aux = aux->prox;
			i++;
		}
		return i;
	}
}

//Funcao principal que ira rodas as funcoes definidas e implementadas acima
int main() {

	Tipo_Noh* Lista = NULL;
	Tipo_Noh* Lista1 = NULL;
	Tipo_Noh* Lista2 = NULL;
	Tipo_Noh* Lista3 = NULL;
	Tipo_Noh* noh_Buscado = NULL;
	Tipo_Noh* noh_BuscadoOrdenada = NULL;
	Tipo_Noh* noh_Menor = NULL;
	tipo_Info valor = 0;
	tipo_Info elemento_X = 0;
	int i;
	int op;

	srand((unsigned)time(NULL));

	do {
		printf("\n\n\n-----------------------------------------\n");
		printf("\n1) Gerar lista (10 elementos)\n");
		printf("2) Imprimir lista\n");
		printf("3) Imprimir inversamente\n");
		printf("4) Buscar elemento (desordenada)\n");
		printf("5) Remover elemento\n");
		printf("6) Ordenar a lista\n"); //Falta ordenar ---> Extra
		printf("7) Buscar elemento (ordenada)\n"); //Considerar que ela ja vem ordenada
		printf("8) Buscar o menor elemento\n");
		printf("9) Destroi a lista\n"); //Dando erro
		printf("10) Intercala duas listas\n");
		printf("11) Intercala duas listas (inversamente)\n");
		printf("12) Remove nohs pares\n");
		printf("13) Sair\n\n");
		printf("-----------------------------------------\n");
		printf("O que deseja fazer?\t");
		scanf("%d", &op);

		switch(op) {

			//Manipulacoes da LSE e suas funcoes
			case 1:
				//Loop para gerar uma lista de 10 nohs
				for (i=0; i<10; i++) {
					valor = rand() % 100;
					Lista = insere_Noh(Lista, valor);
					printf("\nInserindo... %d -> %d. \n", i+1, valor);
				}
				printf("\nLista gerada!\n");
				break;
			case 2:
				printf("\n-----------------------------------------\n");
				imprime_Lista(Lista);
				break;
			case 3:
				printf("\n-----------------------------------------\n");
				imprime_Inversa(Lista);
				break;
			case 4:
				printf("Entre com o elemento que deseja buscar: \t");
				scanf("%d", &elemento_X);
				noh_Buscado = busca_Desordenada(Lista, elemento_X);
				break;
			case 5:
				printf("Entre com o elemento que deseja remover: \t");
				scanf("%d", &elemento_X);
				Lista = remove_Noh(Lista, elemento_X);
				break;
			case 6:
				Lista = ordena_Lista(Lista);
				imprime_Lista(Lista);
				break;
			case 7:
				noh_BuscadoOrdenada = busca_Ordenada(Lista, elemento_X);
				break;
			case 8:
				noh_Menor = busca_Menor(Lista);
				printf("O menor elemento e %d.\n", noh_Menor->info);
				break;
			case 9:
				printf("\n-----------------------------------------\n");
				for (i=0; i<10; i++) {
					//Executa funcao dez vezes
					destroi_Lista(Lista);
				}
				printf("\n*Digite 1 ou 12.\n");
				break;
			case 10:
				for (i=0; i<10; i++) {
					valor = rand() % 100;
					Lista1 = insere_Noh(Lista1, valor); //Inserindo na lista 1
					valor = rand() % 100;
					Lista2 = insere_Noh(Lista2, valor); //Inserindo na lista 2
				}
				printf("\n-----------------------------------------\n");
				imprime_Lista(Lista1);
				printf("\n-----------------------------------------\n");
				imprime_Lista(Lista2);
				//Chamando a funcao para intercalar a lista
				Lista3 = intercala_Listas(Lista1, Lista2, Lista3);
				printf("\n-----------------------------------------\n");
				imprime_Lista(Lista3);
				break;
			case 11:
				system("cls");
				//Funcao que ira remover todos os nohs pares da lista
				Lista = remove_Noh_Par(Lista);
				break;
			case 12:
				for (i=0; i<10; i++) {
					valor = rand() % 100;
					Lista1 = insere_Noh(Lista1, valor); //Inserindo na lista 1
					valor = rand() % 100;
					Lista2 = insere_Noh(Lista2, valor); //Inserindo na lista 2
				}
				printf("\n-----------------------------------------\n");
				imprime_Lista(Lista1);
				printf("\n-----------------------------------------\n");
				imprime_Lista(Lista2);
				//Chamando a funcao para intercalar a lista
				Lista3 = intercala_Listas_Inversa(Lista1, Lista2, Lista3);
				printf("\n-----------------------------------------\n");
				imprime_Lista(Lista3);
			case 13:
				return 0;
		}
	} while (op != 13);
}
