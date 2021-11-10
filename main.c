#include <stdio.h>
#include <stdlib.h>
#include "cards.h"

int main(){
	int cartas[TAM_DEQUE][2], i, j, rodada = 0, tam_deque = TAM_DEQUE;
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
		printf("\n-----------------------------------\n");
		printf("\n               MESA                \n");
		printf("-----------------------------------\n");
		for(i=0;i<5;i++){
			for(j=0; j<5; j++){
				printf(" [%i %i] ", mesa[i][j].valor, mesa[i][j].naipe);
			}
			printf("\n");
		}
		rodada++;
	}

    return 0; 
}