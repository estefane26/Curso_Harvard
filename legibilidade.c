#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int QtdeLetras(char texto[]);
int QtdePalavras(char texto[]);
int QtdeFrases(char texto[]);

int main(void){

    char texto[200];
    printf("Digite um texto: \n");
    fgets(texto, sizeof(texto), stdin);
    int p = QtdePalavras(texto);
    int f = QtdeFrases(texto);
    int l = QtdeLetras(texto);
    //Calculo de  Coleman-Liau
    double L = (double)l / p * 100.0;
    double S = (double)f / p * 100.0;
    double result = 0.0588 * L - 0.296 * S - 15.8;
    /*Verifica se está no intervalo de 1 a 16
    se estiver um valor menor que 1 é passado como nivel 1
    se estiver um valor maior que 16 é passado como nivel 16+
    e arrendonda o numero para o mais proximo */ 
    if(result < 1){
        printf("Nivel: 1");
    }else if (result > 16){
        printf("Nivel: 16+");
    }else{
        result = round(result);
        printf("Nivel: %i", (int)result);
    }
}
// Função para retornar a quantidade de palavras
/*A logica consiste em pegar o texto e utilizar a condição de verificar o que
é um caractere de espaço e assim fazer a contagem das palavras, lembrando
que a quantidade de palavras é a quantidade de espaços mais um*/ 
    int QtdePalavras(char texto[]){
    int palavras = 0;
    for(int i = 0, n = strlen(texto); i < n; i++){
        if(texto[i] == ' '){
            palavras++;
        }
    }
    palavras++;
    return(palavras);
}

//Função para retornar a qunatidade de frases
/*A função verifica quantas pontuções é existente no texto
e assim calcula a quantidade de frases*/
int QtdeFrases(char texto[]){
    int frases = 0;
    for(int i = 0, n = strlen(texto); i < n; i++){
        if (texto[i] == '.'){
            frases++;
        }
        if (texto[i] == '!'){
            frases++;
        }
        if (texto[i] == '?'){
            frases++;
        } 
    }
    return(frases);
}
//Função para retornar a quantiade de frases
/*Verifica se o que foi fornecido no texto é uma letra do alfabeto, 
e faz a contagem de letras*/
int QtdeLetras(char texto[]){
    int letras = 0; 
    for(int i = 0, n = strlen(texto); i < n; i++){
        if(isalpha(texto[i])){
            letras++;
        }
    }
    return(letras);
}
