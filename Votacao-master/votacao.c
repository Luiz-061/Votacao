#include <stdio.h>

void linha() {
	printf("-------------------------------------------\n");
}

void cadastrar_candidato(char nome[][50], int n) {
	for (int i = 0; i < n; i++) {
		printf("Preencha o nome do candidato %d: ", i + 1);
		scanf("%49s", nome[i]);
	}
}

void exibir_candidato(char nome[][50], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d - %s\n", i + 1, nome[i]);
		
	}
}

int main() {
	int opcao;
	int votar = 0;
	int votos[5] = {0};
	char nome[5][50];
	int qtd;
	float prc_vencedor = 0;

	do {
		printf("Quantos querem se voluntariar a ser representante de 2 ate 5: ");
		scanf("%d", &qtd);
		if (qtd < 2 || qtd > 5) {
			printf("Numero maior que o permitido! Tente novamente!\n");
		}
	} while (qtd < 2 || qtd > 5);

	cadastrar_candidato(nome, qtd);

	do {
		linha();
		printf("BEM VINDO\n");
		linha();
		printf("O que quer selecionar?\n");
		printf("1- Votar\n");
		printf("2- Apurar\n");
		printf("3- Definir quem ganhou\n");
		printf("0- Sair\n");
		printf("Escolha no menu: ");
		scanf("%d", &opcao);

		switch (opcao) {
			case 1: {
			    linha();
				printf("Qual candidato deseja votar?\n");
				linha();
				exibir_candidato(nome, qtd);
				linha();
				printf("Votar no: ");
				scanf("%d", &votar);

				if (votar >= 1 && votar <= qtd) {
					votos[votar - 1]++;
					printf("Voto para o candidato %d - %s\n", votar, nome[votar - 1]);
				} else {
					printf("Numero de voto invalido, tente novamente!\n");
				}
				break;
			}

			case 2: {
			    int apuracao_candidato = 0;
			    linha();
				printf("Apurando...\n");
				linha();

				for (int i = 0; i < qtd; i++) {
					printf("%s: %d votos\n", nome[i], votos[i]);
					apuracao_candidato += votos[i];
				}

				printf("O total de votos e: %d\n", apuracao_candidato);
				break;
			}

			case 3: {
				int maior = 0;
				int total_votos = 0;
				int i;
				
				for(i = 0; i < qtd; i++) {
				    total_votos = total_votos + votos[i];
				}
				
				if (total_votos == 0) {
				    linha();
				    printf("Nenhum voto foi registrado!\n");
				    break;
				}

				for (i = 1; i < qtd; i++) {
					if (votos[i] > votos[maior]) {
						maior = i;
				    } 
				}
				
				int qtd_empatados = 0;
				for (i = 0; i < qtd; i++) {
				    if (votos[i] == votos[maior]) {
				        qtd_empatados++;
				    }
				}
				
				prc_vencedor = votos[maior] + (votos[maior]*100) / total_votos;
                
                linha();
				printf("O representante e....\n");
				if (qtd_empatados > 1) {
					printf("Empate! (maior contagem: %d votos).\n", votos[maior]);
				} else {
					printf("Candidato %s com %.2f porcento dos votos!\n", nome[maior], prc_vencedor);
				}
				break;
			}

			case 0: {
				printf("Saindo...\n");
				break;

			default: {
				printf("Opcao invalida!\n");
				break;
		    }
		}
		
		}
		
	} while (opcao != 0);

	return 0;
}