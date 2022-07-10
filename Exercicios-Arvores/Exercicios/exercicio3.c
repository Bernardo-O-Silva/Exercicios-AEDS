/*Exercício 3 - Dada uma árvore binária, faça uma função para contar o número de
folhas, o número de nós com um filho e o número de nós com dois filhos. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arvore.h"
#define SUCESSO 0
#define POSSIVEIS_OPCOES 3
#define NUM_FILHO 0
#define NUM_NO_UM 1
#define NUM_NO_DOIS 2

int main(int argc, char** argv){

    Arv* arvorita;
    int* contagemTotal;
    char charUser; 

    arvorita = arv_criavazia();

    contagemTotal = (int*)calloc(POSSIVEIS_OPCOES, sizeof(int));

    while (charUser != '0'){

        printf("Digite um caractere para inserir na árvore (0 finaliza a inserção): ");
        scanf("%c", &charUser);
        getchar();

        if (charUser != '0'){

            arvorita = arv_insere_maior_menor(arvorita, charUser);
        }
    }    

    arv_conta(arvorita, contagemTotal);

    printf("Número de folhas: %d\n", contagemTotal[NUM_FILHO]);
    printf("Número de nós com 1 filho: %d\n", contagemTotal[NUM_NO_UM]);
    printf("Numero de nós com 2 filhos: %d\n", contagemTotal[NUM_NO_DOIS]);


    arv_libera(arvorita);
    free(contagemTotal);
    return SUCESSO;
}