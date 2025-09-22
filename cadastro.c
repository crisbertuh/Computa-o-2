/*
Exercício em Sala:
Faça um programa computacional em linguagem C que resolva o seguinte problema:
Você está criando um cadastro de clientes. Você deverá armazenar os dados do primeiro
cliente, solicitando as informações para o usuário. Os dados são: nome completo, telefone
e endereço. Você deve mostrar todos os dados após a inclusão de todos os itens e criar
uma opção para atualizar o cadastro deste usuário. Ele diz qual dado quer atualizar, você
atualiza e, na sequência, mostra todos os dados do usuário novamente.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Declaração das funções auxiliares
void nome_cliente(char **nome);
void endereco_cliente(char **endereco);
void imprime_dados(char **nome, char **endereco);
void altera(char **nome, char **endereco);

#define TAM_MAX 256
//-----------------------------------FUNÇÃO PRINCIPAL-------------------------------------------
int main(){
    char *nome=NULL, *endereco=NULL;
    printf("--------------BEM VINDO------------------");
    printf("\n            REALIZE SEU CADASTRO          \n");
    nome_cliente(&nome);
    endereco_cliente(&endereco);

    imprime_dados(&nome, &endereco);
    
    altera(&nome, &endereco);
    
    imprime_dados(&nome, &endereco);
    
    free(nome);
    free(endereco);
    return 0;
}
//--------------------------FUNÇÃO PARA NOME DOS CLIENTES---------------------------------------
void nome_cliente(char **nome){
    char aux[TAM_MAX];

    printf("\nDigite seu nome completo ");
    fgets(aux, TAM_MAX, stdin);//Armazenando numa memoria auxiliar
    aux[strcspn(aux, "\n")]='\0';//Eliminando o \n --> não pula mais linhas
    //Alocando memoria
    *nome=malloc(strlen(aux)+1);
    if(*nome==NULL){
        printf("\nEro! Memoria não alocada coretamente!");//Checando se a alocação foi bem sucedida 
        exit(1);
    }
    strcpy(*nome, aux);
    
}
//--------------------------FUNÇÃO PARA ENDEREÇO DOS CLIENTES------------------------------------
void endereco_cliente(char **endereco){
    char aux[TAM_MAX];
    printf("\nQual o seu endereço? ");
    fgets(aux, TAM_MAX, stdin);
    aux[strcspn(aux, "\n")]='\0';
    
    *endereco=malloc(strlen(aux)+1);
    if(*endereco==NULL){
        printf("\nErro! Mmoria não alocada corretamente!");
        exit(1);
    }
    strcpy(*endereco, aux);
}
//-------------------------FUNÇÃO PARA IMPRIMIR DADOS--------------------------------------------
void imprime_dados(char **nome, char **endereco){
    printf("\nNome alocado é:");
    printf("\n%s", *nome);
    
    printf("\nEndereco alocado é:");
    printf("\n%s", *endereco);
}
//------------------------FUNÇÃO PARA ALTERAR DADOS-------------------------------------------------
void altera(char **nome, char **endereco){
    int a;
    int select=0;
    printf("\nVocê deseja alterar? 0 para sim e 1 ara não ");
    scanf("%d", &a);
    getchar(); // <<< ADICIONADO para limpar o \n do scanf
    
    if(a==1){
            printf("Muito obrigado pela colaboração");
    }
    
    else{
        printf("\n 0 para NOME e 1 para ENDEREÇO");
        scanf("%d", &select);
        getchar(); // <<< ADICIONADO para limpar o \n do scanf
        
        if(select==0){
            free(*nome);
            nome_cliente(nome);
        }
        else if(select==1){
            free(*endereco);
            endereco_cliente(endereco);
        }
    }
}
