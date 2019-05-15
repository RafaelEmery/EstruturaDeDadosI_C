/*
	Enfileirar - inicio e fim, desenfileirar - inicio e fim, próximo e último, comprimento
*/

#include "deque.c"

int main() {
	Noh* deque = NULL;
	int x, op;

	srand((unsigned) time(NULL));

	do {
		printf("\n1) Enfileirar no inicio\n");
		printf("2) Enfileirar no fim\n");
		printf("3) Desenfileirar no inicio\n");
		printf("4) Desenfileirar no fim\n");
		printf("5) Proximo e ultimo\n");
		printf("6) Comprimento\n");
		printf("7) Exibir deque\n");
		printf("8) Sair\n");
		printf("\n\nO que deseja?\t");
		scanf("%d", &op);

		switch(op) {
			case 1:
				x = rand() % 100;
				deque = enfileirar_Inicio(deque, x);
				printf("Enfileirando (inicio) -> %d.\n", x);
				break;
			case 2: 
				x = rand() % 100;
				deque = enfileirar_Inicio(deque, x);
				printf("Enfileirando (fim) -> %d.\n", x);
				break;
			case 3: 
				deque = desenfileirar_Inicio(deque);
				break;	
			case 4:
				deque = desenfileirar_Fim(deque);
				break;
			case 5: 
				PrimeiroUltimo_Deque(deque);
				break;
			case 6: 
				comprimento_Deque(deque);
				break;
			case 7: 
				exibe_Deque(deque);
				break;
			case 8:
				printf("\n\nSAINDO VIADOOOO!!!\n");
				return 0;
		}
	} while (op != 8);
}