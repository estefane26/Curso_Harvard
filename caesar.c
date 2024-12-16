#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Verifica se ao menos um ou se mais de dois argumentos foram passados 
    if (argc < 2 || argc > 2) {
        printf("Utilize: .\\caesar [chave]\n");
        return 1;
    }
    //Tentativa de conversão do argumento para numero
    char *input = argv[1];
    char *endptr;
    int chave = strtol(input, &endptr, 10);
    //Verifica se é um numero e positivo
    if (*endptr != '\0' || chave <= 0) {
        printf("Utilize: .\\caesar [chave]\n");
        return 1;
    }


    char texto[200];
    int textoAscii[200];
    int textoCripto[200];
    char cripto[200];
    int calculo;
    printf("Digite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    int n = strlen(texto);
    for(int i = 0; i < n; i++){
        //Condição que verifica se é uma letra
        if(!isalpha(texto[i])){
            cripto[i] = texto[i]; //Se nao for uma letra, copia diertamente
        //Condição que verifica se é minuscula
        }else if (islower(texto[i])){
            textoAscii[i] = texto[i]; //Transforma em Ascii
            calculo = (textoAscii[i] - 97 + chave) % 26; //Realiza o calculo de caesar utilizando a tabela Ascii 
            textoCripto[i] = 97 + calculo; // Volta para a tabela Ascii com o resultado do calculo
            cripto[i] = textoCripto[i]; // Trasforma em string com a criptografia
        //Condição que verifica se é maiuscula
        }else{
            textoAscii[i] = texto[i]; //Transforma em Ascii
            calculo = (textoAscii[i] - 65 + chave) % 26; //Realiza o calculo de caesar utilizando a tabela Ascii
            textoCripto[i] = 65 + calculo; // Volta para a tabela Ascii com o resultado do calculo
            cripto[i] = textoCripto[i]; // Trasforma em string com a criptografia
        }
    }
    //Percorre e imprime o vetor de cripto
    for (int i = 0; i < n; i++){
        printf("%c", cripto[i]);
    }
    
    return 0;
}
