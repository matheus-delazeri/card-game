#include <stdio.h>
#include <stdlib.h>
#include "cards.h"

int main(){
	int cartas[TAM_DEQUE][2], i, rodada = 0, tam_deque = TAM_DEQUE;
	int pos_horizontal, pos_vertical;
	CARTA_T mao[5], mesa[5][5];
	criaBaralho(cartas);
	criaMesa(mesa);
	embaralha(cartas, SEMENTE);

	while(rodada<5){
		for(i=0; i<MAO; i++){
			mao[i].valor = cartas[0][0];
			mao[i].naipe = cartas[0][1];
			tam_deque--;
			ordenaBaralho(cartas, tam_deque);
		}
		printf("\n             SUA MÃO               \n");
		printf("-----------------------------------\n");
		for(i=0; i<MAO; i++){
			printf(" [%i %i] ", mao[i].valor, mao[i].naipe);
		}
		imprimeMesaMatriz(mesa);	
		for(i=0;i<MAO;i++){
			printf("\n Em que posição da matriz você deseja posicionar a carta [%i %i]? ", mao[i].valor, mao[i].naipe);
			scanf("%d %d", &pos_horizontal, &pos_vertical);
			mesa[pos_horizontal][pos_vertical].valor = mao[i].valor;
			mesa[pos_horizontal][pos_vertical].naipe = mao[i].naipe;
		}
		rodada++;
	}

    return 0; 
}