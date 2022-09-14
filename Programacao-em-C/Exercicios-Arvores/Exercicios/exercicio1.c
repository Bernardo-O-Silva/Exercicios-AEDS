//Exercício 1 - Implemente os três tipos de percurso em árvores binárias.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "arvore.h"
#define SUCESSO 0
#define ELEMENTO_POR_NO 3

int main(int argc, char** argv){

    Arv* arvorezita;
    int qtdElementos, comparador, contEleNo, contElementos;
    char elemento;

    contElementos = 0;

    arvorezita = arv_criavazia();
    
    qtdElementos = ELEMENTO_POR_NO;

    for (comparador = 0; comparador < qtdElementos; comparador += 3){

        for (contEleNo = 0; contEleNo < ELEMENTO_POR_NO; contEleNo++){

            if (comparador == 0 && contEleNo == 0){

                printf("Digite o nó: ");
                scanf("%c", &elemento);
                arvorezita = arv_insere(arvorezita, elemento);
                contElementos++;

            }
            else if (contEleNo == 1 && contElementos < qtdElementos){
                
                getchar();
                printf("Digite o elemento da esquerda desse nó: ");
                scanf("%c", &elemento);
                arvorezita = arv_insere(arvorezita, elemento);
                contElementos++;

            }            
            else if (contElementos < qtdElementos){

                getchar();
                printf("Digite o elemento da direita desse nó: ");
                scanf("%c", &elemento);
                arvorezita = arv_insere(arvorezita, elemento);
                contElementos++;

            }

        }

    }

    printf("Pré Ordem: ");
    arv_imprime_preordem(arvorezita);
    printf("\n");
    printf("Pós Ordem: ");
    arv_imprime_posordem(arvorezita);
    printf("\n");
    printf("Simétrica: ");
    arv_imprime_simetrica(arvorezita);
    printf("\n");


    arv_libera(arvorezita);
    return SUCESSO;
}