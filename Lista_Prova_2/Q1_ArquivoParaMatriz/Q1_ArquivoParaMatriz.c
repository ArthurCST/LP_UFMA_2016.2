#include <stdio.h>
#include <stdlib.h>

char **ConteudoDoArquivo(FILE *arq);
void imprimeResultado(FILE *arq, char **texto);
int getLinhas(FILE *arq);

void main(){
    char **texto;
    
    FILE *arq = fopen("test.txt","r");
    
    texto = ConteudoDoArquivo(arq);

    if(arq == NULL){
        printf("Aquivo inexistente!!");
    }else{
        
        imprimeResultado(arq, texto);
    }
    fclose(arq);
    
}


char **ConteudoDoArquivo(FILE *arq)
{
    
    char **result;
    int nlin = getLinhas(arq);
    int i=0;
    
    result = (char**) malloc(nlin * sizeof(char*)); 
    for(i = 0; i<nlin; i++){
        result[i] = (char*) malloc(300 * sizeof(char));
        fgets(result[i], 300, arq);
    }
    
    return result;
}


void imprimeResultado(FILE *arq, char **texto)
{
    int i, lin = getLinhas(arq);;
    for(i=0; i<lin; i++)
    {   
        printf("%d: %s", i+1 ,texto[i]);
    }
}

int getLinhas(FILE *arq)
{
    char linha[300];
    int num_linhas = 0; 
    while(!feof(arq))
    {
        fgets(linha, 300, arq);
        num_linhas++;
    }
    return num_linhas;
}
