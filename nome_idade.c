#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE* abre_arquivo(FILE* arquivo, char sel);
FILE* fecha_arquivo(FILE* arquivo);

int main()
{
    char nome[30];
    int idade;
    int erro;
    int opcao;
    FILE* arq = NULL;

    // abre o arquivo
    arq = abre_arquivo(arq, 'r');
    if (arq == NULL)
    {
        printf("\n Erro na abertura do arquivo.\n");
        //exit(0);
    }
    else{
        printf("\t-----------Menu---------\t");
        printf("\nPressione 1 para adicionoar um nome e idade");
        printf("\nPressione 2 para ler, sair e salvar o aquivo.");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                arq = fecha_arquivo(arq);
                arq = abre_arquivo(arq, 'a');
                printf("\nQual o nome? ");
                getchar();
                fgets(nome, 30, stdin);
                nome[strcspn(nome, "\n")]='\0';

                printf("Qual a idade? ");
                scanf("%d", &idade);

                fprintf(arq, "%s\t%d\n", nome, idade);
                arq = fecha_arquivo(arq);
                break;

            case 2:
                arq = abre_arquivo(arq, 'r');

                while (!feof(arq)){
                    if(fscanf(arq, "%s\t%d\n", nome, &idade) != 2){
                    printf("\nErro na leitura do nome e idade.");
                    exit(0);
                    }
                    printf("Nome: %s, idade: %d\n",nome, idade);
                    arq = fecha_arquivo(arq);
                    }
                break;

                }

        }
    return 0;
}

FILE* abre_arquivo(FILE* arquivo, char sel){
    switch(sel){
        case 'w':
            arquivo=fopen("arquivo.txt", "w");
            break;
        case 'r':
            arquivo = fopen("arquivo.txt", "r");
            break;
        case 'a':
            arquivo = fopen("arquivo.txt", "a");
            break;
        default:
            printf("Erro ao abrir o arquivo!");
            return NULL;
        
    }
    return arquivo;

}

FILE* fecha_arquivo(FILE* arquivo){

    arquivo=fclose("arquivo,txt");
    return NULL;

}
