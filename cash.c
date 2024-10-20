#include <stdio.h>
#include <math.h>
/*Nessa atividade temos como objetivo informar ao usuario
quantas moedas são necessarias de acordo com o valor informado pelo
usuario*/
int main(void){
double centavos;
printf("Faremos essa atividade de acordo com as moedas do Estados Unidos");
printf("\nDigite os centavos");
scanf("%lf", &centavos);
/*pegamos o valor informado pelo usuario e multiplicamos
por 100 para conseguirmos realizar o calculo corretamente das moedas, e para
não dar numeros decimais*/
int moedas = (int) (centavos * 100);
int result;
//pegamos apenas o numero inteiro para saber as moedas sao necessarias
result = (int) moedas/25;
printf("Precisa de  %i moedas de 25 centavos", result);
//pegamos o resto da divisão para efetuar as proximas operações com as moedas
moedas = moedas % 25;
result = (int) moedas/10;
printf("\nPrecisa de  %i moedas de 10 centavos", result);
moedas = moedas % 10;
result = (int) moedas/5;
printf("\nPrecisa de  %i moedas de 5 centavos", result);
moedas = moedas % 5;
result = (int) moedas;
printf("\nPrecisa de  %i moedas de 1 centavos", result);


}
