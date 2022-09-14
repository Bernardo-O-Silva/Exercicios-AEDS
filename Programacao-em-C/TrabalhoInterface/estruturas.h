//Definição Lista Encadeada//
typedef struct lista_s {

    int informacao;
    struct lista_s *proximo;

} lista;

/*
//Definição Lista Duplamente Encadeada// Não utilizada ainda!
typedef struct listaDupla_s {

    int informacao;
    struct listaDupla_s *anterior;
    struct listaDupla_s *proximo;

} listaDupla;
*/

//Definição Fila de Lista//
typedef struct fila_s {

    lista *inicio;
    lista *fim;

} fila;

lista *criaLista();
lista *insereLista(lista *listaUser, int valor);
void imprimeLista(lista *listaUser);
int buscaLista(lista *listaUser, int elementoProcurado);
lista *retiraLista(lista *listaUser, int elementoRetira);
void liberaLista(lista *listaUser);
fila *criaFila();
void insereFila(fila *filaUser, int valor);
int retiraFila(fila *filaUser);
int filaVazia(fila *filaUser);
void liberaFila(fila *filaUser);
int buscaFila(fila *filaUser, int elementoProcurado);
void imprimeFila(fila *filaUser);