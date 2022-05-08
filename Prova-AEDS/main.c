//Prova de AEDS - Individual: Bernardo de Oliveira Silva

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "pilhas.h"
#define SUCESSO 0
#define FIM 0
#define INICIO 1

int main(int argc, char** argv){

    setlocale(LC_ALL,"");
    int numeroDigitado, qtdNumerosDigitados, comparador, comparador2;    
    char *ordemAtualVagoes, *ordemDesejadaVagoes, elemento;
    Pilha_vet *pilhaAtual, *pilhaDesejada;

    numeroDigitado = INICIO;
    qtdNumerosDigitados = 0;
    comparador = 0;

    pilhaAtual = pilha_vet_cria();
    pilhaDesejada = pilha_vet_cria();

    while (numeroDigitado != FIM){

        printf("Digite o número total de vagões: ");
        scanf("%d", &numeroDigitado);
                
        ordemAtualVagoes = (char*)realloc(ordemAtualVagoes, (numeroDigitado + 1) * sizeof(int));
        ordemDesejadaVagoes = (char*)realloc(ordemDesejadaVagoes, (numeroDigitado + 1) * sizeof(int));


        printf("Digite a ordem atual dos vagões: ");
        fgets(ordemAtualVagoes, numeroDigitado, stdin);

        for (comparador2 = 0; comparador2 < numeroDigitado; comparador2++){

            elemento = ordemAtualVagoes[comparador];

            pilha_vet_push(pilhaAtual, elemento);

            pilha_vet_imprime(pilhaAtual);//TESTE

        }


        printf("Digite a ordem desejada dos vagões: ");
        fgets(ordemAtualVagoes, numeroDigitado, stdin);


        

    }












    free(ordemAtualVagoes);
    free(ordemDesejadaVagoes);
    return SUCESSO;
}