#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Biblioteca para pegar o tempo para gerar uma seed pro rand
#include "estruturas.h"
#define SUCESSO 0
#define ERRO 1
#define MIN 3
#define MAX 10
#define SIM 1
#define NAO 0
#define AGORA 0
#define MAX_RAND 2
#define INFINITO -255
#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define SEM_ANTECESSOR -4649

void imprimeGrafo(lista **grafoBusca, int numVertices){

    lista *copia;
    int comparador, comparador2;

    for (comparador = 0; comparador < numVertices; comparador++){

        printf("     %.02d ", comparador + 1);


        for (copia = grafoBusca[comparador]; copia != NULL; copia = copia->proximo){

            printf(" %d ", copia->informacao + 1);

        }

        printf("\n");
    }

}

lista **criaGrafo(lista **grafoBusca, int numVertices){

    int comparador, comparador2, valorBinario;

    grafoBusca = (lista**)malloc(numVertices * sizeof(lista*));

    for (comparador = 0; comparador < numVertices; comparador++){

        grafoBusca[comparador] = criaLista();

    }

    for (comparador = 0; comparador < numVertices; comparador++){

        for (comparador2 = 0; comparador2 < numVertices; comparador2++){
            
            valorBinario = rand() % MAX_RAND;

            if (valorBinario == SIM){

                grafoBusca[comparador]= insereLista(grafoBusca[comparador], comparador2);

            }

        }

    }    

    return grafoBusca;
}

void buscaLargura(lista** grafoBusca, int numVertices){

    lista *listaComp;
    fila *Queue;
    int comparador, comparador2, *antecessor, *distancia, *cor, vertice, auxiliar;

    vertice = MAX + 1;

    Queue = criaFila();
    listaComp = criaLista();

    antecessor = (int*)malloc(numVertices * sizeof(int));

    for (comparador = 0; comparador < numVertices; comparador++){

        antecessor[comparador] = SEM_ANTECESSOR;

    }

    distancia = (int*)malloc(numVertices * sizeof(int));

    for (comparador = 0; comparador < numVertices; comparador++){

        distancia[comparador] = INFINITO;

    }

    cor = (int*)calloc(numVertices, sizeof(int));

    while(vertice > numVertices || vertice < 1){

        printf("Digite o vértice onde deseja inciar: ");
        scanf("%d", &vertice);

        if(vertice > numVertices || vertice < 1){

            fputs("Erro: número colocado inválido, tente novamente.\n", stderr);

        }

    }

    vertice = vertice - 1;

    insereFila(Queue, vertice);

    distancia[vertice] = 0;

    while(!filaVazia(Queue)){

        vertice = retiraFila(Queue);

        if (cor[vertice] == BRANCO){

            cor[vertice] = CINZA;

        }

        if (cor[vertice] != PRETO){

            for (listaComp = grafoBusca[vertice]; listaComp != NULL; listaComp = listaComp->proximo){

                auxiliar = listaComp->informacao;

                insereFila(Queue, auxiliar);

                antecessor[auxiliar] = vertice;
                distancia[auxiliar] = distancia[vertice] + 1;

            }

        }

        cor[vertice] = PRETO;
    
    } 

    for (comparador = 0; comparador < numVertices; comparador++){

        printf("Vértice %d:\n", comparador + 1);
        
        switch(cor[comparador]){
        case BRANCO:
            printf("\tCor: Branca\n");
            break;
        case CINZA:
            printf("\tCor: Cinza\n");
            break;
        case PRETO:
            printf("\tCor: Preta\n");
            break;
        }
        
        if (distancia[comparador] == INFINITO){

            printf("\tDistância: Infinita\n");

        }
        else {

            printf("\tDistância: %d\n", distancia[comparador]);

        }

        if (antecessor[comparador] == SEM_ANTECESSOR){

            printf("\tAntecessor: Não possui antecessor\n");

        }
        else {

            printf("\tAntecessor: %d\n", antecessor[comparador] + 1);

        }

    }

    liberaFila(Queue);
    liberaLista(listaComp);
    free(antecessor);
    free(distancia);
    free(cor);
}

void liberaGrafo(lista **grafoBusca, int numVertices){

    int comparador;

    for (comparador = 0; comparador < numVertices; comparador++){

        liberaLista(grafoBusca[comparador]);

    }

    free(grafoBusca);
}

int main(int argc, char** argv){

    srand(time(AGORA));//Gera uma seed pro número aleatório baseada no tempo de agora

    lista **grafoBusca;
    int numVertices;

    numVertices = MAX + 1;

    while(numVertices < MIN || numVertices > MAX){

        printf("Digite o número de vértices que seu grafo terá (Mín: 3 Máx: 10): ");
        scanf("%d", &numVertices);

        if(numVertices < MIN || numVertices > MAX){

            fputs("Erro: número colocado inválido, tente novamente.\n", stderr);

        }

    }

    grafoBusca = criaGrafo(grafoBusca, numVertices);

    printf("Lista de Adjacência do Grafo:\n");

    imprimeGrafo(grafoBusca, numVertices);

    printf("\n");

    buscaLargura(grafoBusca, numVertices);

    liberaGrafo(grafoBusca, numVertices);
    return SUCESSO;
}