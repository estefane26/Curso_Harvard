#include <stdio.h>
#include <math.h>

int main(void){
    long cartao; //Numero do cartao
    int digito; //Armazena digitigos individuais
    int digito1; //1º digito de uma multiplicação caso der 2 digitos
    int digito2; //2º digito de uma multiplicação caso der 2 digitos
    int multiplo = 100; //variavel para extrair os numeros
    int soma = 0; //Armazena a soma dos digitos
    double result; //Armazena resultados intermediários
    long contagem; //Manipula o numero do cartao
    int multiplicacao; //Armazena o resultado da multiplicação por 2
    int verificador; //Verifica o tipo do cartao
    long incdigito; //Armazena os primeiros digitos do cartao
    int cont = 0; //Contador para o numeros de digitos do cartao
    printf("Escreva os digitos do seu cartao\n");
    scanf("%li", &cartao);
    //Inicializa a variável contagem com o valor do cartão
    contagem = cartao;
    // Loop para processar os dígitos do cartão, começando do segundo dígito a partir do final
    while(contagem > 1){
        result = contagem % multiplo;
        result = result / 10;
        digito = (int)result;
        multiplicacao = digito * 2;
        // Se a multiplicação resultar em um número maior que 9, soma os dígitos do resultado
        if (multiplicacao > 9){
            digito1 = (int) multiplicacao /10;
            digito2 = (int) multiplicacao % 10;
            soma = soma + digito1 + digito2;

        }else{
            soma = soma + multiplicacao;
        }
        // Avança dois dígitos
        contagem = contagem / 100;

    }
    // Reinicializa a variável contagem com o valor do cartão
    contagem = cartao;
    multiplo = 10; // Atualiza o valor de multiplo para 10
    // Loop para processar os dígitos do cartão, começando do primeiro dígito a partir do final
    while(contagem > 1){
        result = contagem % multiplo;
        digito = (int)result;
        contagem = contagem / 100; // Avança dois dígitos
        soma = soma + digito;
    }
    digito = (int)soma % 10; // Obtém o último dígito da soma
    contagem = cartao;  // Reinicializa a variável contagem com o valor do cartão
    // Conta o número de dígitos no número do cartão
    while (contagem > 0) {
            contagem /= 10;
            cont++;
    }
    verificador = cont - 2;
    // Calcula a posição dos primeiros dígitos do cartão
    long divisor = 1;
    // Calcula o divisor para extrair os primeiros dígitos do cartão
    for (int i = 0; i < verificador; i++) {
        divisor *= 10;
    }
    incdigito = cartao / divisor; // Extrai os primeiros dígitos do cartão
    // Verifica o tipo de cartão com base nos primeiros dígitos e no número de dígitos
    if(digito == 0 && cont == 15 && (incdigito == 34 || incdigito == 37)){
        printf("Amex");
    }else if(digito == 0 && cont == 16 && (incdigito > 50 && incdigito < 56)){
        printf("MasterCard");
    }else if(digito == 0 && cont > 12 && cont < 17 && (incdigito / 10 == 4)){
        printf("Visa");
    }else{
        printf("Invalid");
    }
}

