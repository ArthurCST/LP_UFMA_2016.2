#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/** (2º)
* Duas matrizes de ordem informado pelo usuário necessitam
* ser preenchidas com conteúdo aleatoriamente com as seguintes restrições:
*   *não pode haver elementos repetidos numa mesma linha
*   *não pode haver mais que 3 elementos repetidos na matriz inteira
*   *não pode haver mais que 6 elementos repetidos para as duas matrizes ao mesmo tempo
**/

/** ASSINATURAS **/
void preenche_matriz(int **matriz, int linhas, int colunas);
bool repeticao_linha(int **matriz, int linha, int coluna, int elemento);
bool repete_matriz(int **matriz, int linha, int coluna, int elemento);
void impreme_matriz(int **matriz, int linhas, int colunas);
/** ASSINATURAS **/

/** FUNCOES **/
void preenche_matriz(int **matriz, int linhas, int colunas)
{

    int i, j, elemento, n_elementos = linhas*colunas;

    matriz = (int**)malloc(linhas * sizeof(int*));
    for(i=0; i<linhas; i++)
    {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
        for(j=0; j<colunas; j++)
        {
            matriz[i][j] = 0;

        }
    }


    for(i=0; i<linhas; i++)
    {
        for(j=0; j<colunas; j++)
        {
            elemento = rand()%n_elementos+1;
            if(repeticao_linha(matriz, i, colunas, elemento) == false && repete_matriz(matriz, linhas, colunas, elemento)== false){
                matriz[i][j] = elemento;
            }else{
                j--;
                continue;
            }
        }
    }
    impreme_matriz(matriz, linhas, colunas);
}
bool repeticao_linha(int **matriz, int linha, int coluna, int elemento)
{
    int i=0;
    do{
        if(matriz[linha][i] == elemento)
        {
            return true;
        }
        i++;
    }while(i<coluna);
    return false;
}
bool repete_matriz(int **matriz, int linha, int coluna, int elemento)
{
    int i, j, cont = 0;
    for(i=0; i<linha; i++)
    {
        for(j=0; j<coluna; j++)
        {
            if (cont == 3){
                return true;
            }
            if(matriz[i][j] == elemento){
                cont++;
            }
        }
    }
    return false;
}
void impreme_matriz(int **matriz, int linhas, int colunas)
{
    int i, j;
    for(i=0; i<linhas; i++)
    {
        for(j=0; j<colunas; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}
/** FUNCOES **/

/** MAIN **/

void main()
{
    srand((unsigned) time(NULL));
    int **matriz1, **matriz2, linhas, colunas, linhas2, colunas2;
    printf("Informe a dimencao da matriz 1, linha e coluna respectivamente:\n");
    scanf("%d %d", &linhas ,&colunas);
    printf("Informe a dimencao da matriz 2, linha e coluna respectivamente:\n");
    scanf("%d %d", &linhas2 ,&colunas2);
    system("cls");

    preenche_matriz(matriz1, linhas, colunas);
    printf("\n\n");
    preenche_matriz(matriz2, linhas2, colunas2);

}

/** MAIN **/
