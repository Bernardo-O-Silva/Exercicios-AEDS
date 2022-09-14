#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#define VAZIA -1
#define NAO_VAZIA 0
#define EXISTE 1
#define NAO_EXISTE 0 

//Inicio das Funções de Lista//
lista *criaLista(){

    return NULL;

}

lista *insereLista(lista *listaUser, int valor){

    lista *novaLista;

    novaLista = (lista*)malloc(sizeof(lista));

    novaLista->informacao = valor;
    novaLista->proximo = listaUser;
    
    return novaLista;
}

void imprimeLista(lista *listaUser){

    lista *impressaoLista;

    for (impressaoLista = listaUser; impressaoLista != NULL; impressaoLista = impressaoLista->proximo){

        printf("Valor: %d\n", impressaoLista->informacao);

    }

}

void imprimeLista(lista *listaUser){

    if (listaUser == NULL){

        return VAZIA;

    }
    else {

        return NAO_VAZIA;

    }

}

int buscaLista(lista *listaUser, int elementoProcurado){

    lista *procurado;

    for (procurado = listaUser; procurado != NULL; procurado = procurado->proximo){

        if (procurado->informacao == elementoProcurado){

            return EXISTE;

        }

    }   

    if (procurado == NULL){

        return NAO_EXISTE;

    }

}

lista *retiraLista(lista *listaUser, int elementoRetira){

    lista *listaRetira, *listaAnterior;
    int verificadorElemento, verificadorLista;

    verificadorElemento = buscaLista(listaUser, elementoRetira);
    verificadorLista = listaVazia(listaUser);

    listaRetira = listaUser;
    listaAnterior = NULL;

    if (verificadorElemento == NAO_EXISTE || verificadorLista == VAZIA){

        printf("Não foi possível remover o elemento %d.\n", elementoRetira);
        return listaUser;

    }
    else {

        while (listaRetira->informacao != elementoRetira){

            listaAnterior = listaRetira;
            listaRetira = listaRetira->proximo;

        }
        if (listaAnterior == NULL){

            listaUser = listaRetira->proximo;

        }
        else {

            listaAnterior->proximo = listaRetira->proximo;

        }

    }

    free(listaRetira);
    return listaUser;
}

void liberaLista(lista *listaUser){

    lista *listaLibera, *auxiliar;

    listaLibera = listaUser;

    while (listaLibera != NULL){

        auxiliar = listaLibera->proximo;

        free(listaLibera);

        listaLibera = auxiliar;

    }

}

//Funções Lista Circular e Duplamente Encadeada implementadas depois!//

//Fim das Funções de Lista//

//Inicio das Funções de Fila//
fila *criaFila(){

    fila *novaFila;

    novaFila = (fila*)malloc(sizeof(fila));

    fila->inicio = NULL; 
    fila->fim = NULL;

    return novaFila;
}

void insereFila(fila *filaUser, int valor){

    lista *listaFila;

    listaFila = (lista*)malloc(sizeof(lista));

    lista->informacao = valor;

    listaFila->proximo = NULL;

    if (filaUser->fim != NULL){

        filaUser->fim->proximo = listaFila;

    }
    else {

        filaUser->inicio = listaFila;
        filaUser->fim = listaFila;

    }

}

int retiraFila(fila *filaUser){

    lista *retiraListaFila;
    int valor;

    if (filaVazia(filaUser)){

        return VAZIA;

    }

    retiraListaFila = filaUser->inicio;

    valor = retiraListaFila->informacao;

    filaUser->inicio = retiraListaFila->proximo;

    if (filaUser->inicio == NULL){

        filaUser->fim == NULL;

    }

    free(retiraListaFila);
    return valor;
}

int filaVazia(fila *filaUser){

    return (filaUser->inicio == NULL);

}

void liberaFila(fila *filaUser){

    lista *listaFilaLibera *auxiliar;

    listaFilaLibera = filaUser->inicio;

    while(listaFilaLibera != NULL){

        auxiliar = listaFilaLibera->proximo;
        
        free(listaFilaLibera);

        listaFilaLibera = auxiliar;

    }

    free(filaUser);
}

int buscaFila(fila *filaUser, int elementoProcurado){

    lista *listaFilaBusca;
    int resultBusca;

    listaFilaBusca = filaUser->inicio;

    resultBusca = buscaLista(listaFilaBusca, elementoProcurado);

    listaLibera(listaFilaBusca);
    return resultBusca;
}

void imprimeFila(fila *filaUser){

    lista *impressaoFila;

    for (impressaoFila = filaUser->inicio; impressaoFila != NULL; impressaoFila = impressaoFila->proximo){

        printf("\t%d%n", impressaoFila->informacao);

    }

}
//Fim das Funções de Fila//