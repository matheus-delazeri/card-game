## Primeiros passos
Primeiramente, o jogo deverá ser compilado utilizando o comando abaixo:
```
gcc -Wall -ansi main.c cardfuncs.c -o main
```
Após compilar, basta executar o arquivo gerado (main) usando:
```
./main
```
## Como jogar?
Após executar o jogo, a sua mão da primeira rodada e a configuração atual da mesa (vazia) serão exibidas para você:

Logo abaixo, será solicitado a posição em que você deseja colocar a primeira carta da sua
mão (neste caso, a carta `[9, 3]`). Considerando que a mesa é representada por um quadrante de
um plano cartesiano, a posição da carta será dada por (x,y). Por exemplo, ao posicionar a
carta em 0 2, ela ficará na seguinte posição:

Obs.: as posições deverão ser separadas por um espaço. Exemplo: `0 3`

Siga este mesmo processo durante as 5 rodadas do jogo. Ao fim da última rodada você será perguntado se deseja realizar alguma alteração na mesa. Digite 1 para realizar uma troca ou 0 caso não queira realizar nenhuma (você poderá realizar, no máximo, 2 trocas).
Ao fim do jogo serão exibidos seus pontos totais, seguindo a tabela abaixo: