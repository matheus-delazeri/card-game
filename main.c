#include <stdio.h>
#include <stdlib.h>
#include "cards.h"

int main(){
	int cartas[TAM_DEQUE][2], i, tam_deque = TAM_DEQUE;
	CARTA_T mao[5];
	criaBaralho(cartas);
	embaralha(cartas, SEMENTE);

	for(i=0; i<MAO; i++){
		mao[i].valor = cartas[0][0];
		mao[i].naipe = cartas[0][1];
		tam_deque--;
		imprimeBaralhoVetor(cartas);
		ordenaBaralho(cartas, tam_deque);
		printf("Baralho ordenado\n");
	}
	for(i=0; i<MAO; i++){
		printf("[%i %i]\t", mao[i].valor, mao[i].naipe);
	}

    return 0; 
}