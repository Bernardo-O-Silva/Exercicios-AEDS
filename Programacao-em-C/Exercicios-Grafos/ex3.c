#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "listas.h"
#define SUCESSO 0
#define ERRO 1
#define NUM_SERVIDORES 10
#define NUM_MAQUINAS 8

int contaGrau(Lista *l){
	Lista *p = l;
    int contador = 0;

	while(p != NULL){
		Lista *t = p->prox;
		contador++;
		p = t;
	}

    return contador;
}

int main(int argc, char** argv){

    Lista** grafoServidores;
    int comparador, comparador2, comparador3, *numSaidos, diferenteComp, qtdSaidos, grauVertice, grauEsperado, qtdGrauCerto;
    char escolha;

    diferenteComp = 0;
    qtdSaidos = 0;
    qtdGrauCerto = 0;

    grafoServidores = (Lista**)malloc(NUM_SERVIDORES * sizeof(Lista*));
    numSaidos = (int*)malloc(NUM_SERVIDORES * sizeof(int));

    grauEsperado = (NUM_SERVIDORES - 1) + NUM_MAQUINAS;

    for (comparador = 0; comparador < NUM_SERVIDORES; comparador++){

        grafoServidores[comparador] = lst_cria();

    }

    for (comparador = 0; comparador < NUM_SERVIDORES; comparador++){

        for (comparador2 = 0; comparador2 < NUM_SERVIDORES; comparador2++){

            for (comparador3 = 0; comparador3 < qtdSaidos; comparador3++){

                if (comparador2 == numSaidos[comparador3]){

                    diferenteComp++;

                }

            }

            if (diferenteComp == 0 && comparador != comparador2){
                 
                grafoServidores[comparador] = lst_insere(grafoServidores[comparador], comparador2);
                grafoServidores[comparador2] = lst_insere(grafoServidores[comparador2], comparador);

            }

            diferenteComp = 0;

        }

        numSaidos[comparador] = comparador;
        qtdSaidos++;
           
    }

    for (comparador = 0; comparador < NUM_SERVIDORES; comparador++){

        for (comparador2 = 0; comparador2 < NUM_MAQUINAS; comparador2++){

            grafoServidores[comparador] = lst_insere(grafoServidores[comparador], comparador2);

        }


    }

    for (comparador = 0; comparador < NUM_SERVIDORES; comparador++){

        grauVertice = contaGrau(grafoServidores[comparador]);        

        if (grauVertice == grauEsperado){

            qtdGrauCerto++;

        }
        else {

            printf("Há um problema de conexão com o servidor número %d! Verifique suas conexões!\n", comparador + 1);

        }

    }
    
    if (qtdGrauCerto == NUM_SERVIDORES){

        printf("Todos os servidores estão conectados corretamente!\n");

    }

    for (comparador = 0; comparador < NUM_SERVIDORES; comparador++){  

        lst_libera(grafoServidores[comparador]);

    }
    free(grafoServidores);
    free(numSaidos);
    return SUCESSO;
}