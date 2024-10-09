#include <stdio.h>
/*A atividade pede que o usuario digite um numero de 1 a 8
e enquanto o usuario nao digitar o que é solicitado a piramide não é gerada.
Quando a codição for verdadeira o progama deve imprimir uma piramide de hash's
alinhada a direita com a altura solicitada ao usuario anteriormente*/
int main(void)
{
//Inicializando a Altura
int h;

//Solicitando ao usuario a altura
printf("Digite um numero de 1 a 8\n");
scanf("%i", &h);

//Condicao para verificar se é um numero de 1 a 8
while(h < 1 || h > 8){
printf("Digite um numero de 1 a 8\n");
scanf("%i", &h);
}
//A variavel s fará que imprima as hash's na qtde certa
int s = 0;
//A variavel p que "empurra" os hash's para que fiquem alinhados a direita
int p = h;
//For da linha
for(int j = 0; j < h; j++){

    s++;
    p--;
    //For para imprimir uma qtde de espaço de acordo com a variavel p
    for(int i= p; i > 0; i--){

        printf(" ");
    }
    //For para imprimir a qtde de hash na linha
    for(int k = 0; k < s; k++){
       printf("#");
    }
printf("\n");
}


}


