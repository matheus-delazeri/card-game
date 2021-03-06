#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cards.h"

/* funcao simples para impressão do vetor de baralho */
void imprimeBaralhoVetor(int cartas[][2])
{
	int i;
	for (i = 0; i < TAM_DEQUE; i++)
		printf("[%i %i]", cartas[i][0], cartas[i][1]);
	printf("\n");
	return;
}

void imprimeMesaMatriz(CARTA_T mesa[5][5])
{
	int y, x, aux;
	printf("\n                MESA                \n");
	printf("-------------------------------------\n");
	for (y = 0; y < 5; y++)
	{
		if (y == 0)
		{
			for (aux = 0; aux < 5; aux++)
			{
				printf("      %i", aux);
			}
			printf("\n");
		}
		for (x = 0; x < 5; x++)
		{
			if (x == 0)
			{
				printf(" %i ", y);
			}
			printf(" [%i %i] ", mesa[x][y].valor, mesa[x][y].naipe);
		}
		printf("\n");
	}
	printf("-------------------------------------\n");
	return;
}

void fazTroca(CARTA_T mesa[5][5])
{

	bool troca_valida = false;
	int pos_x, pos_y, x_novo, y_novo, valor_antigo, naipe_antigo;

	while (!troca_valida)
	{
		printf("\n-> Digite a posição (x y) em que a carta se encontra: ");
		if (scanf("%d %d", &pos_x, &pos_y) == 2)
		{
			if ((pos_x < 5 && pos_x >= 0) && (pos_y < 5 && pos_y >= 0))
			{
				printf("\n-> A carta selecionada é: [%i %i]", mesa[pos_x][pos_y].valor, mesa[pos_x][pos_y].naipe);
				while (!troca_valida)
				{
					printf("\n-> Onde esta carta deverá ser posicionada (x y)? ");
					if (scanf("%d %d", &x_novo, &y_novo) == 2)
					{
						if ((x_novo < 5 && x_novo >= 0) && (y_novo < 5 && y_novo >= 0))
						{
							valor_antigo = mesa[pos_x][pos_y].valor;
							naipe_antigo = mesa[pos_x][pos_y].naipe;
							mesa[pos_x][pos_y].valor = mesa[x_novo][y_novo].valor;
							mesa[pos_x][pos_y].naipe = mesa[x_novo][y_novo].naipe;
							mesa[x_novo][y_novo].valor = valor_antigo;
							mesa[x_novo][y_novo].naipe = naipe_antigo;
							printf("\n-> As cartas [%i %i] e [%i %i] trocaram de posições\n ", mesa[pos_x][pos_y].valor, mesa[pos_x][pos_y].naipe, mesa[x_novo][y_novo].valor, mesa[x_novo][y_novo].naipe);
							troca_valida = true;
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
	return;
}

void limpaScanf()
{
	int ch;
	while (((ch = fgetc(stdin)) != '\n') && (ch != EOF))
	{
		;
	}
	return;
}

/* funcao simples que preenche o vetor de baralho com as 52 cartas padrao */
void criaBaralho(int cartas[][2])
{
	long int i, j = 0;
	NAIPES_T n;
	/* geracao do baralho ordenado */
	for (n = OUROS; n <= BASTOS; n++)
	{
		for (i = 1; i <= 13; i++)
		{
			cartas[j][VALOR] = i;
			cartas[j][NAIPE] = n;
			j++;
		}
	}
	return;
}

void criaMesa(CARTA_T mesa[5][5])
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			mesa[i][j].valor = 0;
			mesa[i][j].naipe = 0;
		}
	}
	return;
}

/* funcao que embaralha as cartas de acordo com uma semente para a funcao srand */
/* OBS: o uso da mesma semente irá gerar embaralhamento igual */
void embaralha(int cartas[][2], unsigned int semente)
{
	int i, j, aux_v, aux_n;
	/* EMBARALHAMENTO */
	srand(semente);
	for (i = 0; i < TAM_DEQUE; i++)
	{
		j = (unsigned long int)rand() % TAM_DEQUE;
		aux_v = cartas[i][VALOR];
		aux_n = cartas[i][NAIPE];
		cartas[i][VALOR] = cartas[j][VALOR];
		cartas[i][NAIPE] = cartas[j][NAIPE];
		cartas[j][VALOR] = aux_v;
		cartas[j][NAIPE] = aux_n;
	}
	printf("-> O baralho foi embaralhado\n");
	return;
}

/* funcao que conta os pontos de uma mao (5 cartas) passada para ela. */
/* OBS: a mao deve estar ordenada por valor ascendente. Naipes não precisam estar ordenados */
int contaPontos(CARTA_T *mao)
{
	int cont = 0, flush = 0, straight = 0, royalStraight = 0;
	int cont2 = 0, i;

	/* verifica Flush */
	for (i = 0; i < MAO - 1; i++)
	{
		if (mao[i].naipe == mao[i + 1].naipe)
			cont++;
	}
	if (cont == 4)
		flush = 1; /* é um flush */

	/* verifica Royal Straight */
	if (mao[0].valor == 1 && mao[1].valor == 10 && mao[2].valor == 11 && mao[3].valor == 12 && mao[4].valor == 13)
		royalStraight = 1; /* é um royal straight */

	if (flush && royalStraight) /* mão é um royal straight flush */
		return 100;

	/* verifica Straight simples */
	for (i = 0, cont = 0; i < MAO - 1; i++)
	{
		if (mao[i].valor == (mao[i + 1].valor - 1))
			cont++;
	}
	if (cont == 4)
		straight = 1; /* é um straight simples */

	if (flush && straight) /* mão é um straight flush */
		return 75;

	if (royalStraight || straight) /* mão é um straight */
		return 15;

	if (flush) /* mão é flush */
		return 20;

	/* verifica pares, trincas e quadras */
	i = cont = cont2 = 0;
	while ((i < MAO - 1) && (mao[i].valor != mao[i + 1].valor))
		i++;
	while ((i < MAO - 1) && (mao[i].valor == mao[i + 1].valor))
	{
		cont++;
		i++;
	}
	while ((i < MAO - 1) && (mao[i].valor != mao[i + 1].valor))
		i++;
	while ((i < MAO - 1) && (mao[i].valor == mao[i + 1].valor))
	{
		cont2++;
		i++;
	}
	/* se foi encontrada algum par, trinca, four ou full house, é necessário */
	/* fazer cont e cont2 conter numero correto de cartas iguais encontradas */
	if (cont > 0) /* normalizando valor do primeiro contador */
		cont++;
	if (cont2 > 0) /* normalizando valor do segundo contador */
		cont2++;
	/* após normalizaçao, cont e cont2 podem ser usados para verificacao */
	switch (cont + cont2)
	{
	case 5: /* mão é um full house */
		return 25;
	case 4: /* four ou dois pares */
		if (cont == 4 || cont2 == 4)
			return 50;
		else
			return 5;
	case 3: /* trinca */
		return 10;
	case 2: /* par simples */
		return 2;
	}
	return 0;
}

void ordenaBaralho(int cartas[][2], int tam_deque)
{
	int i;
	for (i = 0; i < tam_deque; i++)
	{
		/* Avança as cartas 1 posição para frente, tendo em vista que a carta do topo saiu */
		cartas[i][0] = cartas[i + 1][0];
		cartas[i][1] = cartas[i + 1][1];
		/* Zera a posição a frente, fazendo com que os espaços "sobrando" no deque sejam preenchidos com [0, 0] */
		cartas[i + 1][0] = 0;
		cartas[i + 1][1] = 0;
	}
	return;
}

void ordenaAscendente(CARTA_T *linha)
{
	CARTA_T copia_linha[5];
	int i, j;
	for (i = 0; i < 5; i++)
	{
		copia_linha[i].valor = linha[i].valor;
		copia_linha[i].naipe = linha[i].naipe;
	}
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (copia_linha[j].valor > copia_linha[i].valor)
			{
				int tmp_valor = copia_linha[i].valor;
				int tmp_naipe = copia_linha[i].naipe;
				copia_linha[i].valor = copia_linha[j].valor;
				copia_linha[i].naipe = copia_linha[j].naipe;
				copia_linha[j].valor = tmp_valor;
				copia_linha[j].naipe = tmp_naipe;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		linha[i].valor = copia_linha[i].valor;
		linha[i].naipe = copia_linha[i].naipe;
	}
}