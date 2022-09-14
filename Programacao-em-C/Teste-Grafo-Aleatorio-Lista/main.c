#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "listas.h"
#include <time.h>//Biblioteca para pegar o tempo para gerar uma seed pro rand
#define SUCESSO 0
#define ERRO 1
#define MIN 3
#define MAX 10
#define SIM 1
#define NAO 0
#define AGORA 0
#define MAX_RAND 2

void imprimeGrafo(Lista **grafo, int numVertices){

    Lista *copia;
    int comparador, comparador2;

    for (comparador = 0; comparador < numVertices; comparador++){

        printf("     %.02d ", comparador + 1);


        for (copia = grafo[comparador]; copia != NULL; copia = copia->prox){

            printf(" %d ", copia->info + 1);

        }

        printf("\n");
    }

}



int main(int argc, char** argv){

    Lista **grafo;
    int numVertices, comparador, comparador2, *grauVertices, valorBinario;

    srand(time(AGORA));//Gera uma seed pro número aleatório baseada no tempo de agora

    numVertices = 0;

    while (numVertices <= MIN){

        numVertices = rand() % MAX;

    }

    /*
    while(numVertices < MIN || numVertices > MAX){

        printf("Digite o número de vértices que seu grafo terá (Mín: 3 Máx: 60): ");
        scanf("%d", &numVertices);

        if(numVertices < MIN || numVertices > MAX){

            fputs("Erro: número colocado inválido, tente novamente.\n", stderr);

        }

    }

    getchar();
    */

    grauVertices = (int*)calloc(numVertices, sizeof(int));

    grafo = (Lista**)malloc(numVertices * sizeof(Lista*));

    for (comparador = 0; comparador < numVertices; comparador++){

        grafo[comparador] = lst_cria();

    }

    for (comparador = 0; comparador < numVertices; comparador++){

        for (comparador2 = 0; comparador2 < numVertices; comparador2++){
            
            valorBinario = rand() % MAX_RAND;

            if (valorBinario == SIM){

                grafo[comparador]= lst_insere(grafo[comparador], comparador2);

            }

        }

    }

    /*
    for (comparador = 0; comparador < numVertices; comparador++){

        for (comparador2 = 0; comparador2 < numVertices; comparador2++){

            if(grafo[comparador2][comparador] == SIM){

                grauVertices[comparador]++;

            }

        }

    }
    */

    printf("Lista de Adjacência do Grafo:\n");

    imprimeGrafo(grafo, numVertices);

    /*
    printf("Os vértices e seus graus são:\n");

    for (comparador = 0; comparador < numVertices; comparador++){

        if (grauVertices[comparador] == 0){

            printf("Vértice %d não poussui grau;\n", comparador + 1);

        }
        else {

            printf("Vértice %d: %dº grau;\n", comparador + 1, grauVertices[comparador]);
        
        }

    }
    */

    for (comparador = 0; comparador < numVertices; comparador++){

        free(grafo[comparador]);

    }

    free(grafo);
    return SUCESSO;
}