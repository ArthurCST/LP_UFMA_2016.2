#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//<Assinatura das funcoes>
    //lê conteudo do arquivo e grava em uma matriz de caracteres que sera retornada por referencia.
    char **ConteudoDoArquivo(FILE *arq);   
    //Percorrer as linhas da matriz de caracteres e imprime na tela.
    void imprimirResultado(FILE *arq, char **texto);
    //Retornar total de linhas escritas no arquivo.
    int getLinhas(FILE *arq);
//</Assinatura das funcaoes>

//<main de execucao>
void main(){
    //Atribui um ponteiro duplo para a variavel q ira receber o retorno da função de leitura
    char **texto;
    
    //abre o arquivo para leitura
    FILE *arq = fopen("test.txt","r"); 
    
    texto = ConteudoDoArquivo(arq);
    
    //reseta a posicao do cursor no arquivo
    rewind(arq);
    imprimirResultado(arq, texto);
    
    //fecha o arquivo
    fclose(arq);
    return;
}
//</main de execucao>


char **ConteudoDoArquivo(FILE *arq)
{
    
    char **result; 
    int nlin = getLinhas(arq); //total de linhas do arquivo
    int i=0; //auxiliar de iteracao
    
    rewind(arq);
    
    result = (char**) malloc(nlin * sizeof(char*)); 
    for(i = 0; i<nlin; i++){
        result[i] = (char*) malloc(300 * sizeof(char));
        fgets(result[i], 300, arq); //le uma linha inteira do arquivo ate a posicao 300 ou ate o primeiro '\n' e grava na linha de indice i na matriz result 
    }
    
    return result;
}


void imprimirResultado(FILE *arq, char **texto)
{
    int i, nlin = getLinhas(arq);
    for(i = 0; i<nlin; i++){
        puts(texto[i]); //imprime a linha do texto de indice i
    }
}

int getLinhas(FILE *arq)
{
    char linha[300];
    int num_linhas = 0; 
    while(!feof(arq)) //percorre ate o fim do arquivo
    {
        fgets(linha, 300, arq);
        num_linhas++;
    }
    return num_linhas;
}