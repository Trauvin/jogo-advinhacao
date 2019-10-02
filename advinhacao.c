#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMERO_DE_TENTATIVAS 3; // CONST que não funciona

int main() {
		// while com verificador
	int jogarnovamente;
	while(jogarnovamente) {
		// cabeçalho
		printf("\n\n");
		printf("          P  /_\\  P                              \n");
		printf("         /_\\_|_|_/_\\                            \n");
		printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
		printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
		printf("    |\" \"  |  |_|  |\"  \" |                     \n");
		printf("    |_____| ' _ ' |_____|                         \n");
		printf("          \\__|_|__/                              \n");
		printf("\n\n");
		
		int chute;
		int inicial;
		int final;
		int acertou;
		double pontos = 1000;   
		int nivel;
		int totaltentativas;
		
		printf("**ATENÇÃO**: Você escolhe o intervalo de números que queres tentar acertar! \n\n");
		printf("Ex: 0 a 100. Onde o primeiro número representa o inicio, e o segundo o fim! \n\n\n");
		printf("Escolha o número inicial do intervalo: \n");

		scanf("%d", &inicial);
		
		printf("Digite o segundo número: \n");
		scanf("%d", &final);
		printf("O intervalo vai compreender de %d à %d \n", inicial, final);
		// gerando um número secreto aleatório
		srand(time(0)); 
		int numero_secreto = rand() % (final - inicial);

		
		printf("Qual o nível de dificuldade? \n");
		printf("(1) Fácil, (2) Médio, (3) Difícil \n \n");
		printf("Escolha: ");

		scanf("%d", &nivel);
		printf("Numero secreto %d \n", numero_secreto);

		switch(nivel) {
			case 1:
				totaltentativas = 20;
				break;
			case 2:
				totaltentativas = 15;
				break;
			case 3:
				totaltentativas = 6;
				break;
			default:
				totaltentativas = 3;
				break;
		}
		// loop para o usuario ter tentativas de acordo com nível
		for(int i = 1; i <= totaltentativas; i++) {
			printf("Tentiva %d de %d \n", i, totaltentativas);
			scanf("%d", &chute);

			if(chute < 0) {
				printf("Números negativos são inválidos! \n");
				i--;
				continue;
			}
			

			int acertou = chute == numero_secreto;

			if (acertou) {
		       	break;
			} 
			else if(chute > numero_secreto) {
				printf("O chute foi maior que o número secreto!\n");
			} else {
				printf("O chute foi menor que o número secreto!\n");
			}
			// sistema de pontos
			// pode usar abs, porém prefiro o if;
			double pontosperdidos = (chute - numero_secreto) / 2.0;
			if(chute < numero_secreto) {
				pontosperdidos = (chute - numero_secreto) / -2.0;
			}
			
			pontos = pontos - pontosperdidos;

			
		}

		printf("\n");
		if(acertou) {
			printf("             OOOOOOOOOOO               \n");
			printf("         OOOOOOOOOOOOOOOOOOO           \n");
			printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
			printf("    OOOOOO      OOOOO      OOOOOO      \n");
			printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
			printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
			printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
			printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
			printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
			printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
			printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
			printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
			printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
			printf("         OOOOOO         OOOOOO         \n");
			printf("             OOOOOOOOOOOO              \n");
			printf("\nParabéns! Você acertou!\n");
			printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
		} else {

		printf("       \\|/ ____ \\|/    \n");   
		printf("        @~/ ,. \\~@      \n");   
		printf("       /_( \\__/ )_\\    \n");   
		printf("          \\__U_/        \n");

			printf("\nVocê perdeu! Tente novamente!\n\n");
		}
		
		printf("====================== \n");
		printf("Obrigado por jogar! \n");
		printf("====================== \n");
		
		// onde a mágica acontece
		printf("Deseja jogar novamente? 1: para sim, 0: para não \n");
		scanf("%d", &jogarnovamente);
	}
}


