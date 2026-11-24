#include <stdio.h>

void linha() {
	printf("-------------------------------------------\n");
}

char cadastrar_candidato(char nome[][50], int n){
  
   
   for(int i = 0; i < n; i++){
       printf("Preencha o nome do candidato %d: ", i + 1);
       scanf("%s", &nome[i]);
   }
}
char exibir_candidato(char nome[][50],int n){
    for(int i = 0; i < n; i++){
        printf("%d- %s \n", i + 1, nome[i]);
    }
}

int main() {
	int opcao;
	int votar;
	int votos[5];
	char nome[5][50];
	int qtd;
	do{
	    printf("Quantos querem se voluntariar a ser representante de 2 até 5: \n");
	    scanf("%d", &qtd);
	    if(qtd < 2 || qtd > 5){
	        printf("Numero maior do que permitido! Tente novamente!\n");
	    }
	}while(qtd < 2 || qtd > 5);
	cadastrar_candidato(nome, qtd);
	do {
		linha();
		printf("BEM VINDO\n");
		linha();
		printf("Qual quer selecionar?\n");
		printf("1- Votar\n");
		printf("2- Apurar\n");
		printf("3- Definir quem ganhou\n");
		printf("0- Sair\n");
		printf("Escolha no menu: ");
		scanf("%d", &opcao);
		switch(opcao) {
		case 1:
			printf("Qual candidato deseja votar?\n");
			exibir_candidato(nome, qtd);
			printf("Votar no: ");
			scanf("%d", &votar);
			if(votar >= 1 && votar <= qtd){
			    votos[qtd - 1]++;
			    printf("Voto para o candidato %d- %s\n", votar, nome[votar - 1]);
			}else {printf("Numero de voto invalido, tente novamente!");}
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