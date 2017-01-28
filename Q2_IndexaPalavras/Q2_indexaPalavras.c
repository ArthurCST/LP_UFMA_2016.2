#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ler_palavras(FILE *arq);
int getLinhas(FILE *arq);
void imprimirResultado(FILE *arq, char **texto);

void main()
{
    
    char **texto;
    
    //abre o arquivo para leitura
    FILE *arq = fopen("test.txt","r"); 
    
    texto = ler_palavras(arq);
    
    //reseta a posicao do cursor no arquivo
    rewind(arq);
    imprimirResultado(arq, texto);
    
    //fecha o arquivo
    fclose(arq);
    return;
}

char **ler_palavras(FILE *arq)
{
    char ch;
    char *palavra;
    char **index;
    int i;
    index = (char*) malloc(255 * sizeof(char));
    for(i = 0; i<getLinhas(arq); i++)
    {
        index[i] = (char*) malloc(300 * sizeof(char));
    }
    int posicao=0, indexLetra=0; //auxiliar de iteracao
    palavra = (char*) malloc(255 * sizeof(char));
    rewind(arq);
    while((ch = fgetc(arq))!= EOF)
    {
        if(ch == ' ' || ch == '\n'){ 
            palavra[indexLetra] = '\0';
            printf("\n");
            index[posicao] = palavra;
            free(palavra);
            indexLetra = 0;
            posicao++;
        }else{
            palavra[indexLetra] = ch;
            printf("%c", ch);
            indexLetra++;
        }
            
    }
    return index;
}

int getLinhas(FILE *arq)
{
    int num_linhas = 0; 
    char ch;
    while(!feof(arq)) //percorre ate o fim do arquivo
    {
        ch = fgetc(arq);
        if(ch == ' '|| ch == '\n')
        {
            num_linhas++;
        }
        
    }
    return num_linhas;
}

void imprimirResultado(FILE *arq, char **texto)
{
    int i, nlin = getLinhas(arq);
    for(i = 0; i<nlin; i++){
        puts(texto[i]); //imprime a linha do texto de indice i
    }
}

