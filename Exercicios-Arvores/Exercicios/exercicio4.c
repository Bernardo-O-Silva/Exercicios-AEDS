/*Exercício 4 - Considere uma árvore binária, faça uma função que monte um
histograma de ocorrência dos caracteres que aparecem na árvore.
Modifique a inserção da questão 2 para aceitar valores iguais.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "arvore.h"
#define SUCESSO 0
#define QTD_ALFABETO 26

int main(int argc, char** argv){

    Arv* arvrinha;
    int* valores, comparador, comparador2, letraAlfabeto;
    char charUser;
    
    letraAlfabeto = 65;

    arvrinha = arv_criavazia();

    valores = (int*)calloc(QTD_ALFABETO, sizeof(int));

    while (charUser != '0'){

        printf("Digite um caractere para inserir na árvore (0 finaliza a inserção): ");
        scanf("%c", &charUser);
        charUser = toupper(charUser);
        getchar();

        if (charUser != '0'){

            arvrinha = arv_insere_maior_menor(arvrinha, charUser);

        }
    }    
    
    arv_letras(arvrinha, valores);

    for (comparador = 0; comparador < QTD_ALFABETO; comparador++){

        printf("%c: ", letraAlfabeto);

        for (comparador2 = 0; comparador2 < valores[comparador]; comparador2++){

            printf("*");

        }

        printf("\n");

        letraAlfabeto++;

    }



    free(valores);
    arv_libera(arvrinha);
    return SUCESSO;
}