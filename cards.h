#ifndef CARDS_H

#define TAM_DEQUE	52
#define SEMENTE		1
#define VALOR		0
#define	NAIPE		1
#define MAO		5

typedef enum {OUROS, ESPADAS, COPAS, BASTOS} NAIPES_T;

/* tipo a ser usado para a fila correspondente a mao do usuario */
typedef struct n {
	int valor;
	int naipe;
} CARTA_T;

void imprimeBaralhoVetor(int cartas[][2]);
void imprimeMesaMatriz(CARTA_T mesa[5][5]);
void criaBaralho(int cartas[][2]);
void criaMesa(CARTA_T mesa[5][5]);
void embaralha(int cartas[][2], unsigned int semente);
int contaPontos(CARTA_T *mao);
void ordenaBaralho(int cartas[][2], int tam_deque);


#define CARDS_H
#endif
