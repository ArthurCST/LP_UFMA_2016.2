#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool existencia(FILE *arq, char *palavra);
void substituir(FILE *arq, char *palavra, char *nova_palavra, int tamanho);
void imprimir_arquivo(FILE *arq);
int tamanho_do_arquivo(FILE *arq);


void main()
{
    char *nome_do_arquivo, *palavra, *nova_palavra;
    int tamanho;

    nome_do_arquivo = (char*) malloc(200 * sizeof(char));
    palavra = (char*) malloc(200 * sizeof(char));
    nova_palavra = (char*) malloc(200 * sizeof(char));

    puts("Digite o nome do arquivo que deseja editar:");
    scanf("%s", nome_do_arquivo);

    FILE *arq = fopen(nome_do_arquivo,"r+");

    if(arq == NULL)
    {
        system("clear");
        printf("Arquivo \"%s\" informado nao existe!!\n\n\n", nome_do_arquivo);
        return;
    }else
    {
        tamanho = tamanho_do_arquivo(arq);
        system("clear");
        printf("----------[ %s ]----------\n\n", nome_do_arquivo);
            imprimir_arquivo(arq);
        printf("\n----------[ %s ]----------\n\n\n", nome_do_arquivo);

        puts("Digite a palavra a ser editada:");
        scanf("%s", palavra);

        if(existencia(arq, palavra) == true)
        {
            puts("Digite a nova palavra: [Certifique que seja do mesmo tamanho da antiga]");
            scanf("%s", nova_palavra);

            system("clear");
            printf("----------[ %s ]----------\n\n", nome_do_arquivo);
                imprimir_arquivo(arq);
            printf("\n----------[ %s ]----------\n\n\n", nome_do_arquivo);
                substituir(arq, palavra, nova_palavra, tamanho);
            printf("-------[NOVO - %s ]-------\n\n", nome_do_arquivo);
                imprimir_arquivo(arq);
            printf("\n-------[NOVO - %s ]-------\n\n\n", nome_do_arquivo);


        }else
        {
            system("clear");
            printf("----------[ %s ]----------\n\n", nome_do_arquivo);
                imprimir_arquivo(arq);
            printf("\n----------[ %s ]----------\n\n\n", nome_do_arquivo);
            printf("A palavra \"%s\" informada nao existe no arquivo \"%s\"!!\n\n\n", palavra, nome_do_arquivo);
            return;
        }
    }
    fclose(arq);

}

bool existencia(FILE *arq, char *palavra)
{
    rewind(arq);
    int cont=0 , i=0;
    char ch;

    while(!feof(arq))
    {
        ch = fgetc(arq);
        if(cont == strlen(palavra))
        {
            return true;
        }else if(ch == palavra[i])
        {
            i++;
            cont++;
        }else
        {
            i = 0;
            cont = 0;
        }
    }
    return false;
}

void substituir(FILE *arq, char *palavra, char *nova_palavra, int tamanho)
{
    rewind(arq);

    char linha[1000];
	char *aux = NULL;
	bool contem; /*Bandeira que verifica se existe uma ocorrência do padrão*/
	int distancia = 0;

	/*Iterando enquanto não é o fim do arquivo*/
	while(!feof(arq)) {
		contem = false; /*Não existe uma ocorrência*/

		/*Lendo um linha do arquivo até o uma quebra de linha*/
		fgets(linha, 255, arq);

		/*Itera enquanto há ocorrências do padrão na string*/
		while(strstr(linha, palavra) != NULL) {
			contem = true; /*Existe uma ocoorrência*/

			/*Localizando a posição do padrão*/
			aux = strstr(linha, palavra);

			/*Trocando a palavra pela string do usuário*/
			strncpy(aux, nova_palavra, strlen(nova_palavra));
		}

		/*Se houve alguma mudança na string*/
		if(contem == true) {
			/*Definindo o cursor para DISTANCIA do início do arquivo(SEEK_SET)*/
			fseek(arq, distancia, SEEK_SET);
			/*Adicionando a nova string no lugar da antiga no arquivo*/
			fputs(linha, arq);
		}
		/*Calculando o distância do cursor para o início do arquivo*/
		distancia += strlen(linha);
	}
}

void imprimir_arquivo(FILE *arq)
{
    rewind(arq);
    char ch = fgetc(arq);

    while(ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(arq);
    }
}


int tamanho_do_arquivo(FILE *arq)
{
    int tamanho=0;

    char ch = fgetc(arq);

    while(ch != EOF)
    {
        tamanho++;
        ch = fgetc(arq);
    }

    return tamanho;
}
