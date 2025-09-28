/*
Cristiano Bertulino

Implemente um código computacional, similar ao programa anterior,
capaz de alocar dinamicamente 4 nomes digitados pelo usuário. Desta
vez, os nomes não foram pré-definidos. Desenvolva uma alternativa para
definir o tamanho dos nomes digitados pelo usuário.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIN 4
#define TAM_MAX 256
//Declaração das funções auxiliares
void limpa_matriz(char **M, int linhas);
//-------------------------------------FUNÇÃO PRINCIPAL---------------------------------
int main(){
    char **mat, nome1[TAM_MAX], nome2[TAM_MAX], nome3[TAM_MAX], nome4[TAM_MAX];
    char *nomes[]={nome1, nome2, nome3, nome4};
    int tamanho;
    //Leitura dos nomes
    printf("Vamos analizar quatro nomes e realocá-los.");
    printf("\nDigite o primeiro nome ");
    fgets(nome1, TAM_MAX, stdin);
    nome1[strcspn(nome1, "\n")]='\0';//Removendo \n e trocando por \0
    
    printf("\nDigite o segundo nome ");
    fgets(nome2, TAM_MAX, stdin);
    nome2[strcspn(nome2, "\n")]='\0';//Removendo \n e trocando por \0
    
    printf("\nDigite o terceiro nome ");
    fgets(nome3, TAM_MAX, stdin);
    nome3[strcspn(nome3, "\n")]='\0';//Removendo \n e trocando por \0
    
    printf("\nDigite o quarto nome ");
    fgets(nome4, TAM_MAX, stdin);
    nome4[strcspn(nome4, "\n")]='\0';//Removendo \n e trocando por \0
    
    printf("\nAlocando as linhas da matriz...");
    //Alocando as linhas da matriz
    mat=(char**)malloc(LIN * sizeof(char*));
    if(mat==NULL){
        printf("ERRO AO ALOCAR!");//Verificando se tem espaço ppara alocar
        return 1;
    }
    
    printf("\nAlocando as colunas da matriz..\n");
    //Alocando as colunas da matriz
    for(int i=0; i<LIN; i++){
        tamanho=strlen(nomes[i]);//Guardando tamanho dos nomes
        mat[i]=(char*)malloc(tamanho * sizeof(char));//Alocando um espaço do tamanho dos nomes
        if(mat==NULL){
        printf("ERRO AO ALOCAR!");//Verificando se tem espaço ppara alocar
        return 1;
        }
        strcpy(mat[i], nomes[i]);//Copiando conteúdo
        //Imprimindo matriz
        printf("%s\n", mat[i]);
        
    }
    
    limpa_matriz(mat, LIN);
        
    return 0;
}

void limpa_matriz(char **M, int linhas){
    if(M==NULL)
        return;
    for(int i=0; i<LIN; i++){
        if(M[i]!=NULL)
            free(M[i]);
    }
    free(M);
}
