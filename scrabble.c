#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*No jogo Scrabble, os jogadores criam palavras para marcar pontos e o 
número de pontos é a soma dos valores dos pontos de cada letra da palavra.*/

void Computar_pontos(char p1[], char p2[]);
int main(void){
    char p1 [20];
    char p2 [20]; 
    
    printf("Jogador 1 \n Digite a sua palavra: ");
    scanf("%19s", p1);
    printf("Jogador 2 \n Digite a sua palavra: ");
    scanf("%19s", p2);
    Computar_pontos(p1, p2);
    
}
//funçao que calcula e indica quem ganhou o jogo
    void Computar_pontos(char p1[], char p2[]){
    char maiuscula;
    int pontos [] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int ponto1 =0;
    int ponto2 =0;
    char alfabeto[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    //for para percorrer cada letra da palavra
    for (int i = 0, n = strlen(p1); i < n; i++){
        maiuscula =  toupper(p1[i]); 
        //for para percorrer o alfabeto
        for(int j = 0; j < 26; j++){
            //condicao que verifica qual letra é do alfabeto e atribui seu respetivo ponto
            if (maiuscula == alfabeto[j]){
                ponto1 = ponto1 + pontos[j];
            }
            
        }
      
    }
    for (int i = 0, n = strlen(p2); i < n; i++){
        maiuscula =  toupper(p2[i]); 
        //for para percorrer o alfabeto
        for(int j = 0; j < 26; j++){
            //condicao que verifica qual letra é do alfabeto e atribui seu respetivo ponto
            if (maiuscula == alfabeto[j]){
                ponto2 = ponto2 + pontos[j];
            }
            
        }
      
    }
    //Condição que verifica quem ganhou
    if (ponto1 == ponto2){
        printf("Empate!");
    }else if (ponto1 > ponto2){
        printf("Jogador 1 venceu!");
    }else{
        printf("Jogador 2 venceu!");
    }
    
    
    
    }
    