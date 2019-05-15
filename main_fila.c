/*
	Enfileirar, desenfileirar, comprimento, próximo
*/

#include "fila.c"

int main() {
	Noh* fila = NULL;
	Noh* proximo = NULL;
	int comprimento = 0;
	int i, x, op;

	srand((unsigned) time(NULL));

	do {
		printf("\n1) Enfileirar\n");
		printf("2) Desenfileirar\n");
		printf("3) Proximo\n");
		printf("4) Comprimento\n");
		printf("5) Exibir fila\n");
		printf("6) Sair\n");
		printf("\n\nO que deseja?\t");
		scanf("%d", &op);

		switch(op) {
			case 1:
				x = rand() % 100;
				fila = Enfileirar(fila, x);
				printf("Enfileirando -> %d.\n", x);
				break;
			case 2: 
				fila = Desenfileirar(fila);
				break;
			case 3: 
				proximo = Proximo(fila);
				printf("\nProximo -> %d. \n", proximo->info);
				break;	
			case 4:
				comprimento = Comprimento(fila);
				printf("\nComprimento -> %d.\n", comprimento);
				break;
			case 5: 
				exibir_Fila(fila);
				break;
			case 6:
				printf("\n\nSAINDO VIADOOOO!!!\n");
				return 0;
		}
	} while (op != 6);
}