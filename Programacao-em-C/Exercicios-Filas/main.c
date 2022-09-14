//Exercício de Filas

#include <stdio.h>
#include <locale.h> //Biblioteca para fazer acentos aparecerem
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fila.h"
#define SUCESSO 0
#define ERRO 1
#define TAM_PLACA 8 + 1
#define V 0
#define F 1

int main(int argc, char** argv){

    setlocale(LC_ALL, ""); //Comando para fazer acentos aparecerem

    FilaL *FilaCarros;
    int qtdCarros, comparador, carroSaiu;
    char placa[TAM_PLACA], carroRetira[TAM_PLACA], fazerDeNovo, *auxiliar;

    FilaCarros = fila_cria_l();
    
    fazerDeNovo = 'y';
    carroSaiu = F;

    printf("Digite a quantidade de carros há no estacionamento: ");
    scanf("%d", &qtdCarros);

    for (comparador = 0; comparador < qtdCarros; comparador++){

        getchar();

        printf("Digite a placa do %dº carro (Formato: ABC-1234)!: ", comparador + 1);

        fgets(placa, TAM_PLACA, stdin);

        fila_insere_l(FilaCarros, placa);

    }

    while (fazerDeNovo == 'y'){

        getchar();

        printf("Digite a placa do carro que vai sair: ");
        fgets(placa, TAM_PLACA, stdin);

        carroSaiu = F;

        if (fila_busca_l(FilaCarros, placa) == NULL){

            fputs("\nHouve um erro, tente novamente.\n", stderr);
        
            fila_libera_l(FilaCarros);
            return ERRO;

        }

        while (carroSaiu == F){

            auxiliar = fila_retira_l(FilaCarros);    
            strcpy(carroRetira, auxiliar);

            if (strcmp(carroRetira, placa) == V && !fila_vazia_l(FilaCarros)){

                printf("Carro %s retirado com sucesso!\nSituação atual do estacionamento:\n", placa);
                fila_imprime_l(FilaCarros);

                carroSaiu = V;

                printf("Deseja remover algum outro carro? (y/n): ");
                scanf(" %c", &fazerDeNovo);

                fazerDeNovo = tolower(fazerDeNovo);

                if (fazerDeNovo != 'y' && fazerDeNovo != 'n'){

                    fputs("\nHouve um erro, tente novamente.\n", stderr);
        
                    fila_libera_l(FilaCarros);
                    return ERRO;

                }

            }
            else if(strcmp(carroRetira, placa) != V && !fila_vazia_l(FilaCarros)) {

                fila_insere_l(FilaCarros, carroRetira);                

            }
            else if(fila_vazia_l(FilaCarros)){

                printf("Carro %s retirado com sucesso!\nSituação atual do estacionamento:\n", placa);
                printf("O estacionamento está vazio, não há carros para retirar!\n");

                fila_libera_l(FilaCarros);
                return SUCESSO;
            }


        }
    
    }

    fila_libera_l(FilaCarros);
    return SUCESSO;
}