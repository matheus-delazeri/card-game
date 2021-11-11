#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cards.h"

int main()
{
	bool pos_valida, troca_valida = false;
	int cartas[TAM_DEQUE][2], i, x, y, rodada = 0, tam_deque = TAM_DEQUE, ver;
	int pos_x, pos_y, pontos_total = 0;
	CARTA_T mao[5], mesa[5][5], linha[5];
	criaBaralho(cartas);
	criaMesa(mesa);
	embaralha(cartas, SEMENTE);

	while (rodada < 1)
	{
		printf("\n           [ RODADA %i ]        \n", rodada + 1);
		for (i = 0; i < MAO; i++)
		{
			mao[i].valor = cartas[0][0];
			mao[i].naipe = cartas[0][1];
			tam_deque--;
			ordenaBaralho(cartas, tam_deque);
		}
		printf("\n             SUA MÃO               \n");
		printf("-----------------------------------\n");
		for (i = 0; i < MAO; i++)
		{
			printf(" [%i %i] ", mao[i].valor, mao[i].naipe);
		}
		printf("\n-----------------------------------\n");
		imprimeMesaMatriz(mesa);
		for (i = 0; i < MAO; i++)
		{
			pos_valida = false;
			while (!pos_valida)
			{
				printf("\n-> Escolha a posição (x y) na matriz para a carta [%i %i]: ", mao[i].valor, mao[i].naipe);
				if (scanf("%d %d", &pos_x, &pos_y) == 2)
				{
					if ((pos_x < 5 && pos_x >= 0) && (pos_y < 5 && pos_y >= 0))
					{
						if (mesa[pos_x][pos_y].valor == 0 && mesa[pos_x][pos_y].naipe == 0)
						{
							mesa[pos_x][pos_y].valor = mao[i].valor;
							mesa[pos_x][pos_y].naipe = mao[i].naipe;
							pos_valida = true;
							imprimeMesaMatriz(mesa);
						}
						else
						{
							printf("\n Opss... Esta posição já está ocupada por outra carta! Tente novamente\n");
						}
					}
					else
					{
						printf("\n Digite uma posição válida");
					}
				}
				else
				{
					limpaScanf();
					printf("\n Digite apenas valores numéricos");
				}
			}
		}
		rodada++;
	}
	printf("\n-> Fim da última rodada\n");
	imprimeMesaMatriz(mesa);
	while (!troca_valida)
	{
		printf("\n-> Você deseja realizar alguma troca? Sim [1] / Não [0]: ");
		if (scanf("%d", &ver) == 1 && (ver == 1 || ver == 0))
		{
			switch (ver)
			{
			case 1:
				fazTroca(mesa);
				imprimeMesaMatriz(mesa);
				while(!troca_valida){
					printf("\n-> Você deseja realizar mais uma troca? Sim [1] / Não [0]: ");
					if (scanf("%d", &ver) == 1 && (ver == 1 || ver == 0))
					{
						switch (ver)
						{
						case 1:
							fazTroca(mesa);
							troca_valida = true;
							break;

						case 0:
							break;
						}
					}
					else
					{
						limpaScanf();
						printf("\n Digite 1 ou 0\n");
					}
				}
				troca_valida = true;
				break;

			case 0:
				troca_valida = true;
				break;
			}
		}
		else
		{
			limpaScanf();
			printf("\n Digite 1 ou 0\n");
		}
	}
	printf("\n-> Abaixo está a mesa final\n");
	imprimeMesaMatriz(mesa);
	/* Conta pontos das linhas horizontais*/
	for(y=0;y<5;y++){
		for(x=0;x<5;x++){
			linha[x] = mesa[x][y];
		}		
		ordenaAscendente(linha);
		pontos_total += contaPontos(linha);
	}
	/* Conta pontos das linhas verticais*/
	for(x=0;x<5;x++){
		for(y=0;y<5;y++){
			linha[y] = mesa[x][y];
		}		
		ordenaAscendente(linha);
		pontos_total += contaPontos(linha);
	}
	/* Conta pontos da diagonal principal*/
	for(i=0;i<5;i++){
		linha[i] = mesa[i][i];
	}
	ordenaAscendente(linha);
	pontos_total += contaPontos(linha);
	/* Conta pontos da diagonal secundaria*/
	for(i=4;i>=0;i--){
		linha[i] = mesa[i][4-i];
	}
	ordenaAscendente(linha);
	pontos_total += contaPontos(linha);

	printf("\n-> A soma de pontos total é: [ %i ]\n\n", pontos_total);

	return 0;
}