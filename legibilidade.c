#include <stdio.h>
#include <ctype.h>
#include <string.h>
int QtdeLetras(char texto[]);
int QtdePalavras(char texto[]);
int QtdeFrases(char texto[]);
int main(void){
    char texto[200];
    printf("Digite um texto: \n");
    fgets(texto, sizeof(texto), stdin);
    printf("\n letras: %i", QtdeLetras(texto));
    printf("\n palavras: %i", QtdePalavras(texto));
    printf("\n frases: %i", QtdeFrases(texto));
}
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

int QtdeLetras(char texto[]){
    int letras = 0; 
    for(int i = 0, n = strlen(texto); i < n; i++){
        if(isalpha(texto[i])){
            letras++;
        }
    }
    return(letras);
}
