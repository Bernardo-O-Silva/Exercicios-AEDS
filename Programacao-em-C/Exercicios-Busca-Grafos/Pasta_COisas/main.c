#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

/*
//COISAS DA NICOLLE
struct Lista {
    int num_vert;
    struct Lista* prox;
};

struct Fila {
    struct Lista* ini;
    struct Lista* fim;
};

typedef Fila Fila;
typedef Lista Lista;

Fila* fila_cria_l() {

    Fila* local = (Fila*)malloc(sizeof(Fila));
    local->ini = local->fim = NULL;

    return local;
}
int fila_vazia_l(Fila* local) {
    int aux;
    if (local->ini == NULL) {
        return aux = 1;
    }
    else {
        return SUCESSO;
    }
}
void fila_insere_l(Fila* local, int elemento) {

    Lista* tmp = (Lista*)malloc(sizeof(Lista));

    tmp->num_vert = elemento;
    tmp->prox = NULL;

    if (local->fim != NULL) {
        local->fim->prox = tmp;
    }
    else {
        local->ini = tmp;
    }

    local->fim = tmp;
}
int fila_retira_l(Fila* local) {
    Lista* tmp;
    int elemento;

    if (fila_vazia_l(local) == FALHA) {
        printf("\nFila vazia - 1 retornado (FALHA)");
        return FALHA;
    }

    tmp = local->ini;
    elemento = tmp->num_vert;
    local->ini = tmp->prox;

    if (local->ini == NULL) {
        local->fim = NULL;
    }
    free(tmp);
    return elemento;
}
void fila_imprime_l(Fila* local) {
    Lista* tmp;
    for (tmp = local->ini; tmp != NULL; tmp = tmp->prox) {
        printf("%d\n", tmp->num_vert);
    }
}
void fila_libera_l(Fila* local) {
    Lista* tmp = local->ini;

    while (tmp != NULL) {
        Lista* tmp2 = tmp->prox;
        free(tmp);
        tmp = tmp2;
    }
    free(local);
}
//COISAS DA NICOLLE
*/





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
/*
void buscaGrafo(lista **grafoBusca, fila *Queue, int numeroVertices, int verticeAtual,int *antecessor, int *distancia, int *cor){

    lista *copia;
    int qtdConexoes, auxiliar, comparador;

    qtdConexoes = 0;

    for (copia = grafoBusca[verticeAtual]; copia != NULL; copia = copia->proximo){

        insereFila(Queue, copia->informacao);

        qtdConexoes++;

    }    

    cor[verticeAtual] = CINZA;

    for (comparador = 0; comparador < qtdConexoes; comparador++){

        auxiliar = retiraFila(Queue);

        buscaGrafo(grafoBusca, Queue, numeroVertices, auxiliar, antecessor, distancia, cor);        


    }

    //
    if (!filaVazia(Queue)){

        auxiliar = retiraFila(Queue);

        buscaGrafo(grafoBusca, Queue, numeroVertices, auxiliar, antecessor, distancia, cor);

    }
    //

    cor[verticeAtual] = PRETO;

}
*/

int main(int argc, char** argv){

    lista **grafoBusca, *listaComp;
    fila *Queue;
    int numVertices, comparador, comparador2, valorBinario, vertice, *antecessor, *distancia, *cor, qtdCoresPretas, auxiliar;

    srand(time(AGORA));//Gera uma seed pro número aleatório baseada no tempo de agora

    numVertices = 0;
    vertice = MAX + 1;
    qtdCoresPretas = 0;

    Queue = criaFila();
    listaComp = criaLista();

    while(numVertices < MIN || numVertices > MAX){

        printf("Digite o número de vértices que seu grafo terá (Mín: 3 Máx: 10): ");
        scanf("%d", &numVertices);

        if(numVertices < MIN || numVertices > MAX){

            fputs("Erro: número colocado inválido, tente novamente.\n", stderr);

        }

    }

    getchar();

    antecessor = (int*)malloc(numVertices * sizeof(int));

    for (comparador = 0; comparador < numVertices; comparador++){

        antecessor[comparador] = SEM_ANTECESSOR;

    }

    distancia = (int*)malloc(numVertices * sizeof(int));

    for (comparador = 0; comparador < numVertices; comparador++){

        distancia[comparador] = INFINITO;

    }

    cor = (int*)calloc(numVertices, sizeof(int));

    grafoBusca = (lista**)malloc(numVertices * sizeof(lista*));

    for (comparador = 0; comparador < numVertices; comparador++){

        grafoBusca[comparador] = criaLista();

    }

    for (comparador = 0; comparador < numVertices; comparador++){

        for (comparador2 = 0; comparador2 < numVertices; comparador2++){
            
            //valorBinario = rand() % MAX_RAND;

            if (comparador2 == comparador + 1){

                valorBinario = SIM;


            }
            //else if (comparador == numVertices - 1 && comparador2 == 0){

                //valorBinario = SIM;

            //}
            else {

                valorBinario = NAO;

            }


            if (valorBinario == SIM){

                grafoBusca[comparador]= insereLista(grafoBusca[comparador], comparador2);

            }

        }

    }

    printf("Lista de Adjacência do Grafo:\n");

    imprimeGrafo(grafoBusca, numVertices);

    printf("\n");

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

        imprimeFila(Queue);

        vertice = retiraFila(Queue);
        printf("Vertice wow %d\n", vertice);

        if (cor[vertice] == BRANCO){

            cor[vertice] = CINZA;

        }

        if (cor[vertice] != PRETO){

            for (listaComp = grafoBusca[vertice]; listaComp != NULL; listaComp = listaComp->proximo){

                auxiliar = listaComp->informacao;

                insereFila(Queue, auxiliar);

                imprimeFila(Queue);


                antecessor[auxiliar] = vertice;
                distancia[auxiliar] = distancia[vertice] + 1;

            }

        }


        cor[vertice] = PRETO;

    
        printf("Fim\n");

    } 

    /*
    insereFila(Queue, 35);

    printf("Bizarro\n");

    imprimeFila(Queue);
    */


    //buscaGrafo(grafoBusca, Queue, numVertices, vertice, antecessor, distancia, cor);

    for (comparador = 0; comparador < numVertices; comparador++){

        printf("Vértice %d:\n", comparador + 1);
        printf("\tCor: %d\n", cor[comparador]);

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

    /*
    for (comparador = 0; comparador < 10; comparador++){


        insereFila(Queue, comparador);


    }

    imprimeFila(Queue);

    printf("\n");

    int teste;

    for (comparador = 0; comparador < 5; comparador++){

        teste = retiraFila(Queue);

    }
    imprimeFila(Queue);
    */

    //while (qtdCoresPretas != numVertices){

    /*
    for (comparador = 0; comparador < numVertices; comparador++){

        listaComp = lst_busca(grafoBusca[comparador], comparador);            

        if (listaComp != NULL){

            fila_insere_l(Queue, comparador);

        }

    }


    //}
    */




    for (comparador = 0; comparador < numVertices; comparador++){

        free(grafoBusca[comparador]);

    }

    free(grafoBusca);
    liberaFila(Queue);
    free(antecessor);
    free(distancia);
    free(cor);
    liberaLista(listaComp);
    return SUCESSO;
}