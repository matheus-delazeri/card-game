#include <stdlib.h>
#include <stdio.h>
#include "cards.h"

int main(){
	int cartas[TAM_DEQUE][2];
	CARTA_T mao[5];
	int pontos;

	printf("Criando baralho padrão.\n");
	criaBaralho(cartas);
	imprimeBaralhoVetor(cartas);
	
	printf("\nEmbaralhando com semente %d.\n", SEMENTE);
	embaralha(cartas, SEMENTE);
	imprimeBaralhoVetor(cartas);

	printf("\nTeste de Royal straight flush.\n");
	mao[0].valor = 1; mao[0].naipe = OUROS;
	mao[1].valor = 10; mao[1].naipe = 0;
	mao[2].valor = 11; mao[2].naipe = 0;
	mao[3].valor = 12; mao[3].naipe = 0;
	mao[4].valor = 13; mao[4].naipe = 0;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);

	printf("\nTeste de straight flush.\n");
	mao[0].valor = 9; mao[0].naipe = 0;
	mao[1].valor = 10; mao[1].naipe = 0;
	mao[2].valor = 11; mao[2].naipe = 0;
	mao[3].valor = 12; mao[3].naipe = 0;
	mao[4].valor = 13; mao[4].naipe = 0;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);

	printf("\nTeste de quadra.\n");
	mao[0].valor = 1; mao[0].naipe = 0;
	mao[1].valor = 7; mao[1].naipe = 0;
	mao[2].valor = 7; mao[2].naipe = 1;
	mao[3].valor = 7; mao[3].naipe = 2;
	mao[4].valor = 7; mao[4].naipe = 3;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);

	printf("\nTeste de full house.\n");
	mao[0].valor = 1; mao[0].naipe = 0;
	mao[1].valor = 1; mao[1].naipe = 1;
	mao[2].valor = 13; mao[2].naipe = 2;
	mao[3].valor = 13; mao[3].naipe = 3;
	mao[4].valor = 13; mao[4].naipe = 0;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);

	printf("\nTeste de flush.\n");
	mao[0].valor = 0; mao[0].naipe = 0;
	mao[1].valor = 10; mao[1].naipe = 0;
	mao[2].valor = 11; mao[2].naipe = 0;
	mao[3].valor = 12; mao[3].naipe = 0;
	mao[4].valor = 13; mao[4].naipe = 0;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);

	printf("\nTeste de sequencia.\n");
	mao[0].valor = 1; mao[0].naipe = 1;
	mao[1].valor = 2; mao[1].naipe = 0;
	mao[2].valor = 3; mao[2].naipe = 2;
	mao[3].valor = 4; mao[3].naipe = 0;
	mao[4].valor = 5; mao[4].naipe = 0;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);

	printf("\nTeste de trinca.\n");
	mao[0].valor = 1; mao[0].naipe = 0;
	mao[1].valor = 2; mao[1].naipe = 1;
	mao[2].valor = 2; mao[2].naipe = 2;
	mao[3].valor = 2; mao[3].naipe = 3;
	mao[4].valor = 5; mao[4].naipe = 0;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);

	printf("\nTeste de dois pares.\n");
	mao[0].valor = 1; mao[0].naipe = 0;
	mao[1].valor = 2; mao[1].naipe = 1;
	mao[2].valor = 2; mao[2].naipe = 2;
	mao[3].valor = 5; mao[3].naipe = 3;
	mao[4].valor = 5; mao[4].naipe = 0;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);

	printf("\nTeste de par.\n");
	mao[0].valor = 1; mao[0].naipe = 0;
	mao[1].valor = 2; mao[1].naipe = 1;
	mao[2].valor = 3; mao[2].naipe = 2;
	mao[3].valor = 3; mao[3].naipe = 3;
	mao[4].valor = 5; mao[4].naipe = 0;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);

	printf("\nTeste de mão vazia.\n");
	mao[0].valor = 1; mao[0].naipe = 0;
	mao[1].valor = 2; mao[1].naipe = 1;
	mao[2].valor = 3; mao[2].naipe = 2;
	mao[3].valor = 5; mao[3].naipe = 3;
	mao[4].valor = 6; mao[4].naipe = 0;
	pontos = contaPontos(mao);
	printf("%d pontos.\n", pontos);


	printf("\nFim do teste.\n");

	exit(0);
}
