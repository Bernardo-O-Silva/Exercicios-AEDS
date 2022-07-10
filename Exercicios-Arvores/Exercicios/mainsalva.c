/*Exercício 4 - Considere uma árvore binária, faça uma função que monte um
histograma de ocorrência dos caracteres que aparecem na árvore.
Modifique a inserção da questão 2 para aceitar valores iguais.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arvore.h"
#define SUCESSO 0
#define QTD_ALFABETO 26




int main(int argc, char** argv){

    Arv* arvrinha;
    int qtdTotal, comparador;
    char* letraSaida, charUser;

    qtdTotal = 0;
    comparador = 0;

    arvrinha = arv_criavazia();

    while (charUser != '0'){

        printf("Digite um caractere para inserir na árvore (0 finaliza a inserção): ");
        scanf("%c", &charUser);
        getchar();

        if (charUser != '0'){

            arvorinha = arv_insere_maior_menor(arvorita, charUser);
            qtdTotal++;

        }
    }    
    

    letraSaida = (char*)malloc(qtdTotal * sizeof(char));



    arv_libera(arvrinha);
    return SUCESSO;
}