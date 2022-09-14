#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "listas.h"
#define SUCESSO 0
#define ERRO 1
#define MIN 3
#define MAX 10
#define YES 'y'
#define NO 'n'

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

    Lista** Grafo;
    int numVertices, comparador, comparador2, comparador3, *numSaidos, diferenteComp, qtdSaidos, grauVertice;
    char escolha;

    numVertices = 0;
    diferenteComp = 0;
    qtdSaidos = 0;

    while(numVertices < MIN || numVertices > MAX){

        printf("Digite o número de vértices que seu grafo terá (Mín: 3 Máx: 10): ");
        scanf("%d", &numVertices);

        if(numVertices < MIN || numVertices > MAX){

            fputs("Erro: número colocado inválido, tente novamente.\n", stderr);

        }

    }

    Grafo = (Lista**)malloc(numVertices * sizeof(Lista*));
    numSaidos = (int*)malloc(numVertices * sizeof(int));

    for (comparador = 0; comparador < numVertices; comparador++){

        Grafo[comparador] = lst_cria();

    }

    for (comparador = 0; comparador < numVertices; comparador++){

        for (comparador2 = 0; comparador2 < numVertices; comparador2++){

            for (comparador3 = 0; comparador3 < qtdSaidos; comparador3++){

                if (comparador2 == numSaidos[comparador3]){

                    diferenteComp++;

                }

            }

            if (diferenteComp == 0){

                printf("O vértice %d possui ligação com o vértice %d? (y/n): ", comparador + 1, comparador2 + 1);
                scanf(" %c", &escolha);

                escolha = tolower(escolha);

                switch(escolha){
                case YES:
                        Grafo[comparador] = lst_insere(Grafo[comparador], comparador2);
                        Grafo[comparador2] = lst_insere(Grafo[comparador2], comparador);
                        break;
                case NO:
                        break;
                default:
                        fputs("Houve um erro.\n", stderr);
                        return ERRO;
                        break;
                }

            }

            diferenteComp = 0;

        }

        numSaidos[comparador] = comparador;
        qtdSaidos++;
           
    }

    printf("Os vértices e seus graus são:\n");

    for (comparador = 0; comparador < numVertices; comparador++){

        grauVertice = contaGrau(Grafo[comparador]);        

        if (grauVertice == 0){

            printf("Vértice %d não poussui grau;\n", comparador + 1);

        }
        else {

            printf("Vértice %d: %dº grau;\n", comparador + 1, grauVertice);

        }

    }

    for (comparador = 0; comparador < numVertices; comparador++){  

        lst_libera(Grafo[comparador]);

    }
    free(Grafo);
    free(numSaidos);
    return SUCESSO;
}