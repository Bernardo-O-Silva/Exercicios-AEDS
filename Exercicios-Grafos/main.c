#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SUCESSO 0
#define ERRO 1
#define MIN 3
#define MAX 10
#define SIM 1
#define NAO 0
#define YES 'y'
#define NO 'n'

int main(int argc, char** argv){

    int **grafoOrient, numVertices, comparador, comparador2, *grauVertices;
    char escolha;

    numVertices = 0;

    while(numVertices < MIN || numVertices > MAX){

        printf("Digite o número de vértices que seu grafo terá (Mín: 3 Máx: 10): ");
        scanf("%d", &numVertices);

        if(numVertices < MIN || numVertices > MAX){

            fputs("Erro: número colocado inválido, tente novamente.\n", stderr);

        }

    }

    getchar();

    grauVertices = (int*)calloc(numVertices, sizeof(int));

    grafoOrient = (int**)malloc(numVertices * sizeof(int*));

    for (comparador = 0; comparador < numVertices; comparador++){

        grafoOrient[comparador] = (int*)malloc(numVertices * sizeof(int));

    }

    for (comparador = 0; comparador < numVertices; comparador++){

        for (comparador2 = 0; comparador2 < numVertices; comparador2++){

            printf("O vértice %d possui ligação com o vértice %d? (y/n): ", comparador + 1, comparador2 + 1);
            scanf(" %c", &escolha);

            escolha = tolower(escolha);

            switch(escolha){
            case YES:
                    grafoOrient[comparador][comparador2] = SIM;
                    break;
            case NO:
                    grafoOrient[comparador][comparador2] = NAO;
                    break;
            default:
                    fputs("Houve um erro.\n", stderr);
                    return ERRO;
                    break;
            }

        }

    }

    for (comparador = 0; comparador < numVertices; comparador++){

        for (comparador2 = 0; comparador2 < numVertices; comparador2++){

            if(grafoOrient[comparador2][comparador] == SIM){

                grauVertices[comparador]++;

            }

        }

    }

    printf("Os vértices e seus graus são:\n");

    for (comparador = 0; comparador < numVertices; comparador++){

        if (grauVertices[comparador] == 0){

            printf("Vértice %d não poussui grau;\n", comparador + 1);

        }else {

            printf("Vértice %d: %dº grau;\n", comparador + 1, grauVertices[comparador]);
        
        }

    }


    for (comparador = 0; comparador < numVertices; comparador++){

        free(grafoOrient[comparador]);

    }

    free(grafoOrient);
    return SUCESSO;
}