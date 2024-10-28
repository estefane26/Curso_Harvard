#include <stdio.h>
#include <math.h>

int main(void){
    int pComeco; //população inicial
    int pFinal; //população final
    int cont = 0; // conatdor dos anos necessarios
    //Loop para garantir que a população inicial seja pelo menos 9
    do{
        printf("Digite o valor da populacao inicial\n");
        scanf("%i", &pComeco);
    }while(pComeco < 9);
    //Loop para garantir que a população final seja maior que a inicial
    do{
        printf("Digite o valor da populacao final\n");
        scanf("%i", &pFinal);
    }while(pFinal <= pComeco);
    //Loop para calcular o número de anos até a população inicial atingir ou ultrapassar a população final
    while(pFinal > pComeco){
        pComeco = pComeco + floor(pComeco/3) - floor(pComeco/4);
        cont++;
    }
    printf("%i anos\n", cont);
}

