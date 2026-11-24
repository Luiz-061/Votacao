#include <stdio.h>

void linha() {
	printf("-------------------------------------------\n");
}
void n() {
	printf("\n");
}

int main() {
	int opcao;
	int votar;
	do {
		linha();
		printf("BEM VINDO\n");
		linha();
		printf("Qual quer selecionar?\n");
		printf("1- Votar\n");
		printf("2- Apurar\n");
		printf("3- Definir quem ganhou\n");
		printf("0- Sair\n");
		printf("Escolha: ");
		scanf("%d", &opcao);
		switch(opcao) {
		case 1:
			printf("Qual candidato deseja votar?\n");
			printf("Escolha: ");
			scanf("%d", &votar);
			break;
		case 2:
			printf("Apurar\n");
			break;
		case 3:
			printf("O representante é....\n");
			break;
		case 0:
			printf("Saindo...");
			break;
		}
	} while(opcao != 0);

	return 0;
}