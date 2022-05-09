//Prova de AEDS - Individual: Bernardo de Oliveira Silva

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "pilhas.h"
#define SUCESSO 0
#define FIM 0
#define INICIO 1
#define INICIALIZAR 2
#define INSERE 'I'
#define REMOVE 'R'
#define VERDADE 10
#define FALSO 9

void pilhaCopia(Pilha_vet *pilhaOrigem, Pilha_vet *pilhaDestino, int qtdElementos){

	Pilha_vet *pilhaIntermediaria;
	int comparador;
	char elemento, inimportante;

	pilhaIntermediaria = pilha_vet_cria();

	while (!pilha_vet_vazia(pilhaDestino)){

		inimportante = pilha_vet_pop(pilhaDestino);

	}

	for (comparador = 0; comparador < qtdElementos; comparador++){

		elemento = pilha_vet_pop(pilhaOrigem);
		pilha_vet_push(pilhaIntermediaria, elemento);
	
	}
	
	for (comparador = 0; comparador < qtdElementos; comparador++){

		elemento = pilha_vet_pop(pilhaIntermediaria);
		pilha_vet_push(pilhaDestino, elemento);
        pilha_vet_push(pilhaOrigem, elemento);


	}


	pilha_vet_libera(pilhaIntermediaria);
}

int main(int argc, char** argv){

    setlocale(LC_ALL,"");
    int numeroDigitado, qtdNumerosDigitados, comparador, comparador2, comparaWhile, qtdInsere;
    int qtdRemove, jaInseriu, contador;    
    char *ordemAtualVagoes, *ordemDesejadaVagoes, elemento, inimportante, inimportante2, compPilhas;
    char compPilhas2, inimportante3, copiaReversa;
    Pilha_vet *pilhaAtual, *pilhaDesejada, *pilhaDesejadaCopiada, *pilhaAtualCopiada, *pilhaReversa;
    Pilha_lst *saida, *elementosAindaNaoRemov, *saida2;

    numeroDigitado = INICIO;
    qtdNumerosDigitados = 0;
    comparador = 0;
    comparaWhile = VERDADE;
    qtdInsere = 0;
    jaInseriu = 0;
    qtdRemove = 0;
    contador = 0;

    pilhaAtual = pilha_vet_cria();
    pilhaDesejada = pilha_vet_cria();
    pilhaDesejadaCopiada = pilha_vet_cria();
    saida = pilha_lst_cria();
    pilhaAtualCopiada = pilha_vet_cria();
    elementosAindaNaoRemov = pilha_lst_cria();
    pilhaReversa = pilha_vet_cria();
    saida2 = pilha_lst_cria();

    ordemAtualVagoes = (char*)malloc(INICIALIZAR * sizeof(int));
    ordemDesejadaVagoes = (char*)malloc(INICIALIZAR * sizeof(int));


    while (numeroDigitado != FIM){
        
        if (contador == 0){
            printf("Digite o número total de vagões: ");
            scanf(" %d", &numeroDigitado);
                
        }
        else if (contador != 0){

            numeroDigitado = FIM;

        }
        
        if (numeroDigitado != FIM){

            ordemAtualVagoes = (char*)realloc(ordemAtualVagoes, (numeroDigitado + 1) * sizeof(char));
            ordemDesejadaVagoes = (char*)realloc(ordemDesejadaVagoes, (numeroDigitado + 1) * sizeof(char));

            getchar();

            printf("Digite a ordem atual dos vagões: ");
            fgets(ordemAtualVagoes, (numeroDigitado + 1), stdin);

            while(!pilha_vet_vazia(pilhaAtual)){

                inimportante = pilha_vet_pop(pilhaAtual);

            }
            while(!pilha_vet_vazia(pilhaDesejada)){

                inimportante2 = pilha_vet_pop(pilhaDesejada);

            }
            while(!pilha_vet_vazia(pilhaDesejadaCopiada)){

                inimportante = pilha_vet_pop(pilhaDesejadaCopiada);

            }
            while(!pilha_vet_vazia(pilhaAtualCopiada)){

                inimportante2 = pilha_vet_pop(pilhaAtualCopiada);

            }
            while(!pilha_vet_vazia(pilhaReversa)){

                inimportante = pilha_vet_pop(pilhaReversa);

            }
            while(!pilha_lst_vazia(saida)){

                inimportante2 = pilha_lst_pop(saida);

            }
            while(!pilha_lst_vazia(elementosAindaNaoRemov)){

                inimportante2 = pilha_lst_pop(elementosAindaNaoRemov);

            }

            for (comparador2 = 0; comparador2 < numeroDigitado; comparador2++){

                elemento = ordemAtualVagoes[comparador2];

                pilha_vet_push(pilhaAtual, elemento);


            }

            getchar();

            printf("Digite a ordem desejada dos vagões: ");
            fgets(ordemDesejadaVagoes, (numeroDigitado + 1), stdin);

            for (comparador2 = 0; comparador2 < numeroDigitado; comparador2++){

                elemento = ordemDesejadaVagoes[comparador2];


                pilha_vet_push(pilhaDesejada, elemento);


            }

            pilhaCopia(pilhaDesejada, pilhaDesejadaCopiada, numeroDigitado);
            pilhaCopia(pilhaAtual, pilhaAtualCopiada, numeroDigitado);

            while (comparaWhile == VERDADE){
                
                 if (qtdInsere >= numeroDigitado){

                    jaInseriu++;

                }
                
                if (jaInseriu == 0){
                  
                    compPilhas = pilha_vet_pop(pilhaDesejadaCopiada);

                }
                
                compPilhas2 = pilha_vet_pop(pilhaAtualCopiada);

                if (compPilhas == compPilhas2 && jaInseriu == 0){

                    pilha_lst_push(saida, INSERE);
                    qtdInsere++;
                    pilha_lst_push(saida, REMOVE);
                    qtdRemove++;
                    
                    if (!pilha_vet_vazia(pilhaAtual)){

                        inimportante3 = pilha_vet_pop(pilhaAtual);

                    }
                    

                    pilhaCopia(pilhaAtual, pilhaAtualCopiada, numeroDigitado);

                }
                else if (compPilhas != compPilhas2){
                    
                    pilha_lst_push(saida, INSERE);
                    qtdInsere++;

                    if (jaInseriu == 0){

                        pilhaCopia(pilhaAtual, pilhaAtualCopiada, numeroDigitado);

                    }
                   

                    pilha_lst_push(elementosAindaNaoRemov, compPilhas);

                }
                if (pilha_vet_vazia(pilhaDesejadaCopiada)){

                    copiaReversa = pilha_lst_pop(elementosAindaNaoRemov);
                    pilha_vet_push(pilhaReversa, copiaReversa);
                    copiaReversa = pilha_vet_pop(pilhaReversa);
                    pilha_vet_push(pilhaDesejadaCopiada, copiaReversa);


                    jaInseriu++;

                }
                if (jaInseriu > 0){
                    

                    pilha_lst_push(saida, REMOVE);
                    qtdRemove++;

                    if (!pilha_vet_vazia(pilhaAtual)){

                        inimportante3 = pilha_vet_pop(pilhaAtual);

                    }

                    pilhaCopia(pilhaAtual, pilhaAtualCopiada, numeroDigitado);
                    
                    jaInseriu = 0;

                }

                

                if (pilha_vet_vazia(pilhaAtual)){

                    comparaWhile = FALSO;

                }
                else if (qtdInsere >= numeroDigitado){

                    comparaWhile = FALSO;

                }

            }

            pilha_lst_push(saida, REMOVE);

            printf("\n\nSAÍDA:\n\n");
            
            qtdInsere = 0;
            qtdRemove = 0;

            while (!pilha_lst_vazia(saida)){

                elemento = pilha_lst_pop(saida);

                if (elemento == INSERE){
                    
                    qtdInsere++;

                }

                if (elemento == REMOVE){

                    qtdRemove++;

                }

                pilha_lst_push(saida2, elemento);



            }

            pilha_lst_imprime(saida2);
            

            if (qtdInsere != qtdRemove){

                printf("\nImpossible");

            }

            printf("\n\n");

            contador++;

        }
    }


    free(ordemAtualVagoes);
    free(ordemDesejadaVagoes);
    pilha_vet_libera(pilhaAtual);
    pilha_vet_libera(pilhaDesejada);
    pilha_vet_libera(pilhaDesejadaCopiada);
    pilha_lst_libera(saida);
    pilha_vet_libera(pilhaAtualCopiada);
    pilha_lst_libera(elementosAindaNaoRemov);
    pilha_vet_libera(pilhaReversa);
    pilha_lst_libera(saida2);
    return SUCESSO;
}