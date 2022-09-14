/**
 * @file   main.c
 * @brief  
 * @author Bernardo de Oliveira Silva, Inaue Ferreira da Silva, Nicolle Taila de Oliveira, Vitoria Ellen de Honorio
 * @date   08-23-2022
 */

/*  CABECALHOS  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listas.h"


/*  CODIGOS DE ERRO */
#define EXECUTADO_COM_EXITO     0

/*	CONSTANTES	*/
#define VERDADEIRO	(1 == 1)
#define FALSO		!VERDADEIRO
#define COMECO_BUSCA	0
#define FIM_BUSCA	1
#define NAO_PREENCHIDO	-1
#define DIST_PADRAO	-1
#define SUCESSO 0
#define MAX_RAND 2
#define MIN 3
#define MAX 10
#define AGORA 0
#define SIM 1
#define ERRO -42

/*	ESTRUTURAS	*/
struct Info_dfs {
    int explorando;
    int chega_no_destino;
    int distancia;
    int prox;
};
typedef struct Info_dfs Info_dfs;

/* 	FUNCOES     */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int	main			(int argc, char** argv);
void	grafo_maior_caminho	(Lista** grafo, int v_visitar, int limite_passos, Info_dfs* resultado);
void	grafo_ini_busca		(Info_dfs* resultado, int total_vertices, int v_destino);
void	lst_print		(Lista* lst_imprimir);

/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void    grafo_ini_busca     (Info_dfs* resultado, int total_vertices, int v_destino)
{
    int v;

    for (v = 0; v < total_vertices; v++)
    {
        resultado[v].explorando         = FALSO;
        resultado[v].chega_no_destino       = FALSO;
    }
    
    resultado[v_destino].distancia      = 0;
    resultado[v_destino].chega_no_destino   = VERDADEIRO;
}

void    grafo_maior_caminho (Lista** grafo, int v_visitar, int limite_passos, Info_dfs* resultado)
{
    int maior_distancia = DIST_PADRAO;
    Lista* v_adj;

    if ((resultado[v_visitar].chega_no_destino) && (resultado[v_visitar].distancia == 0))
        return;

    resultado[v_visitar].explorando = VERDADEIRO;

    for (v_adj = grafo[v_visitar]; v_adj != NULL; v_adj = v_adj->prox)
    {
        if (!resultado[v_adj->info].explorando)
            grafo_maior_caminho(grafo, v_adj->info, limite_passos - 1, resultado);

        if (    !resultado[v_adj->info].explorando && //Se nao esta sendo explorado
            (resultado[v_adj->info].chega_no_destino) && //Se existe um caminho pro destino
            (resultado[v_adj->info].distancia > maior_distancia) && //Se a distancia for maior q a armazenada atualmente
            ((resultado[v_adj->info].distancia + 1) < limite_passos)    ) //Se estiver dentro do limite
        {
            resultado[v_visitar].chega_no_destino   = VERDADEIRO;
            maior_distancia             = resultado[v_adj->info].distancia;
            resultado[v_visitar].prox       = v_adj->info;
        }
    }

    resultado[v_visitar].explorando = FALSO;

    if (resultado[v_visitar].chega_no_destino)
        resultado[v_visitar].distancia  = maior_distancia + 1;
}

void	lst_print	(Lista* lst_imprimir)
{
	Lista* item = lst_imprimir;

	while(item != NULL)
	{
		printf("%i -> ", item->info);
		item = item->prox;
	}

	printf("/\n");

}

Lista **criaGrafo(Lista **grafoBusca, int numVertices){//Função já pra criar o grafo aleatório

    srand(time(AGORA));//Gera uma seed pro número aleatório baseada no tempo de agora

    int comparador, comparador2, valorBinario;

    for (comparador = 0; comparador < numVertices; comparador++){

        grafoBusca[comparador] = lst_cria();

    }

    for (comparador = 0; comparador < numVertices; comparador++){

        for (comparador2 = 0; comparador2 < numVertices; comparador2++){
            
            valorBinario = rand() % MAX_RAND;

            if (valorBinario == SIM){

                grafoBusca[comparador]= lst_insere(grafoBusca[comparador], comparador2);

            }

        }

    }    

    return grafoBusca;
}

void liberaGrafo(Lista **grafoBusca, int numVertices){//Função pra liberar o grafo criado

    int comparador;

    for (comparador = 0; comparador < numVertices; comparador++){

        lst_libera(grafoBusca[comparador]);

    }

    free(grafoBusca);
}



int main(int argc, char** argv)
{
	Lista** grafo;
	Info_dfs* resultado_busca_dfs;
	int vertices, v, v1, v2, origem, destino, limite, i;

	printf("GRAFO ORIENTADO\n");
	printf("____________________________________________________________\n");
	printf("Digite quantos vertices deseja no grafo:\n");
	scanf("%i", &vertices);
	printf("Digite a origem da busca:\n");
	scanf("%i", &origem);
	printf("Digite o destino da busca:\n");
	scanf("%i", &destino);
	printf("Digite o limite de passos:\n");
	scanf("%i", &limite);
	grafo = (Lista**)malloc(vertices * sizeof(Lista*));
	resultado_busca_dfs = (Info_dfs*)malloc(vertices * sizeof(Info_dfs));

	criaGrafo(grafo, vertices);

	printf("____________________________________________________________\n");
	printf("GRAFO RESULTANTE:\n");

	for (v = 0; v < vertices; v++)
	{
		printf("vertices 'destino' a partir do vertice %i: ", v);
		lst_print(grafo[v]);
	}

	grafo_ini_busca(resultado_busca_dfs, vertices, destino);
	grafo_maior_caminho(grafo, origem, limite, resultado_busca_dfs);
	printf("____________________________________________________________\n");
	printf("CAMINHO MAIS LONGO DE %i A %i:\n", origem, destino);
	v = origem;
	printf("%i -> ", v);
	
	do {
		v = resultado_busca_dfs[v].prox;
		printf("%i -> ", v);
	} while (v != destino);

	printf("/\n");

	liberaGrafo(grafo, vertices);
	free(resultado_busca_dfs);

    return EXECUTADO_COM_EXITO;
}

/**
 * @brief FUNCAO PRINCIPAL
 *
 * @param argc NUMERO DE ARGUMENTOS
 * @param argv ARGUMENTOS
 * @return int CODIGO DE ERRO
 */

