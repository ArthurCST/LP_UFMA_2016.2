#include <stdio.h>
#include <stdlib.h>

/** (1º)
* Escreva uma função que receba duas listas
* de inteiros A e B, e retorne uma terceira
* lista C que consiste na união de todos os
* elementos das listas A e B. A lista C deve
* ter todos elementos ordenados do maior para
* menor e não pode haver elementos repetidos.
**/

/** LISTAS **/
    typedef struct _DATA_ //Dado a ser armazenado
    {
        int valor;
    } DATA;

    typedef struct _NODE_ //Espacos de armaxenamento de dados nas listas principais
    {
        DATA dado;
        struct _NODE_ *prox;
    } NODE;

    typedef struct _lista_ //lista principal de armazenamento de dados informado pelo usuario
    {
        int tam;
        NODE *head;
    } LISTA;
/** LISTAS **/


/** ASSINATURAS **/
    LISTA *gerar_lista();
    LISTA *lista_ordenada();
    void inserir_dado_lista(LISTA *lista, DATA dado);
    void ordenar_vetor(int *vetor, int tam);
    void imprime_lista(LISTA *lista);
/** ASSINATURAS **/


/** FUNCOES **/
    LISTA *gerar_lista()
    {
        LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
        lista->tam = 0;
        lista->head = NULL;

        return lista;
    }

    LISTA *lista_ordenada(LISTA *listaA, LISTA *listaB)
{
    LISTA *result = gerar_lista();
    NODE *ponteiro = (NODE*) malloc(sizeof(NODE));
    DATA dado;
    int *vetor, tam = (listaA->tam + listaB->tam), i=0;

    vetor = (int*) malloc(tam * sizeof(int));

    ponteiro = listaA->head;
    while(ponteiro != NULL)
    {
        vetor[i] = ponteiro->dado.valor;
        ponteiro = ponteiro->prox;
        i++;
    }
    ponteiro = listaB->head;
    while(ponteiro != NULL)
    {
        vetor[i] = ponteiro->dado.valor;
        ponteiro = ponteiro->prox;
        i++;
    }
    ordenar_vetor(vetor, tam);
    for(i=0; i<tam; i++)
    {
        dado.valor = vetor[i];
        inserir_dado_lista(result, dado);
    }

    return result;
}
    void inserir_dado_lista(LISTA *lista, DATA dado)
    {
        NODE *noh = (NODE*) malloc(sizeof(NODE));
        noh->dado = dado;
        noh->prox = lista->head;
        lista->head = noh;
        lista->tam++;
    }

    void ordenar_vetor(int *vetor, int tam)
    {
        int i, j, aux, aux2;
        for(i=1; i<tam; i++)
        {
            aux = vetor[i];
            j = i-1;
            while(vetor[j] > aux && j>=0)
            {
                aux2 = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux2;
                j=j-1;
            }
            vetor[j+1]=aux;
        }
    }

    void imprime_lista(LISTA *lista)
    {
        NODE *noh = lista->head;
        while(noh != NULL)
        {
            printf("%d", noh->dado.valor);
            noh = noh->prox;
        }
        printf("\n\n");
    }
/** FUNCOES **/


/** MAIN **/
    void main()
    {
        LISTA *lista_A = gerar_lista();
        LISTA *lista_B = gerar_lista();
        LISTA *lista_C;

        DATA dado;

        int flag = 1;

        while(flag == 1)
        {
            printf("Informe um valor para a lista A\n");
            scanf("%d", &dado.valor);
            inserir_dado_lista(lista_A, dado);
            printf("Deseja informar outro valor? SIM=1 | NAO=2\n");
            scanf("%d", &flag);
        }
        system("cls");
        while(flag == 2)
        {
            printf("Informe um valor para a lista B\n");
            scanf("%d", &dado.valor);
            inserir_dado_lista(lista_B, dado);
            printf("Deseja informar outro valor? SIM = 2 | NAO = 3\n");
            scanf("%d", &flag);
        }
        system("cls");
        imprime_lista(lista_A);
        imprime_lista(lista_B);
        lista_C = lista_ordenada(lista_A, lista_B);
        imprime_lista(lista_C);
    }

/** MAIN **/
