/*Exercício 2 - Implemente uma inserção em árvore binária onde elementos menores que
a raiz ficam esquerda e elementos maiores que a raiz ficam direita.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arvore.h"
#define SUCESSO 0

int main(int argc, char** argv){

    Arv* arvorinha = arv_criavazia();
    char charUser;
    
    while (charUser != '0'){

        printf("Digite um caractere para inserir na árvore (0 finaliza a inserção): ");
        scanf("%c", &charUser);
        getchar();

        if (charUser != '0'){

            arvorinha = arv_insere_maior_menor(arvorinha, charUser);
        }
    }

    printf("Árvore:\n");
    arv_imprime_simetrica(arvorinha);
    printf("\n");
    
    arv_libera(arvorinha);

    return SUCESSO;
}
