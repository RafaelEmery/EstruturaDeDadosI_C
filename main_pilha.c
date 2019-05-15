/*
	Empilhar, desempilhar, topo e altura!!!
*/

#include "pilha.c"	

int main() {
	Noh* pilha = NULL;
	Noh* topo = NULL;
	int x = 0;
	int altura = 0;
	int i, op;

	srand((unsigned) time(NULL));

	do {
		printf("1) Empilhar\n");
		printf("2) Desempilhar\n");
		printf("3) Topo\n");
		printf("4) Altura\n");
		printf("5) Exibir pilha\n");
		printf("6) Sair\n");
		printf("\n\nO que deseja?\t");
		scanf("%d", &op);

		switch(op) {
			case 1:
				x = rand() % 100;
				pilha = Empilhar(pilha, x);
				printf("Empilhando -> %d.\n", x);
				break;
			case 2: 
				pilha = Desempilhar(pilha);
				break;
			case 3: 
				topo = Topo(pilha);
				printf("Topo -> %d. \n", topo->info);
				break;	
			case 4:
				altura = Altura(pilha);
				printf("Altura -> %d.\n", altura);
				break;
			case 5: 
				exibir_Pilha(pilha);
				break;
			case 6:
				printf("Saindooooo\n");
				return 0;
		}
	} while (op != 6);
}