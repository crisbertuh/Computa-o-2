/*
Faça um programa computacional que grave nome da pessoa em um arquivo.
Toda vez que o programa for executado, deve-se substituir o nome da pessoa
por outra.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 256

int main(){
    char *nome=NULL;
    char aux[TAM_MAX];
    int corrige=0, i=0;
    size_t novo_nome;//Tamanho da string é compatível com o tamanho maximo da maquina, sempre positivo.

    printf("\nQual o nome a ser grarvado? ");
    fgets(aux, TAM_MAX, stdin);//Armazenando nome no auxiliar
    aux[strcspn(aux, "\n")]='\0';//Removendo o \n e colocando um \0 no lugar.
    
    nome=(char *)malloc(strlen(aux)+1);//Procurando um espaço na memória com o tamanho do auxiliar (e mais o \0)
    if(nome==NULL){
        printf("\nFalha ao realocar memória");
        return 1;
    }
    strcpy(nome, aux);//Copiando a auxiliar para o nome
    printf("\nNome alocado foi: \n'%s' --> no espaço de memória: %zu", nome, strlen(nome)+1);//imprimido 
    
    while(i==0){
        printf("\nDeseja corrigir o nome? 0 para NÂO e 1 para SIM ");
        scanf("%d ", &corrige);
        if(corrige==0)
            i=1;//Se não quiser corrigir encerra o while
        else{
            printf("\nQual o novo nome? ");
            fgets(aux, TAM_MAX, stdin);
            aux[strcspn(aux, "\n")]='\0';
            novo_nome=strlen(aux)+1;
            
            char *temp=realloc(nome, novo_nome);//Procurando um espaço na memória com o tamanho da nova auxiliar (e mais o \0)
            if(temp==NULL){
                printf("\nFalha ao realocar memória");
                return 1;
            }
            nome=temp;//Nome com mesmo TAMANHO de novo_nome
            strcpy(nome, aux);
        }
        
    }
    
    free(nome);
    return 0;
}
