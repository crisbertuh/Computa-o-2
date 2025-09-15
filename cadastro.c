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
char imprime_dados(char **nome, char *endereco);

#define TAM_MAX 256
//-----------------------------------FUNÇÃO PRINCIPAL-------------------------------------------
int main(){
    char *nome=NULL, *endereco=NULL;
    printf("--------------BEM VINDO------------------");
    printf("\n            REALIZE SEU CADASTRO          ");
    nome_cliente(&nome);
    endereco_cliente(&endereco);

    imprime_dados(&nome. &endereco);
}
//--------------------------FUNÇÃO PARA NOME DOS CLIENTES---------------------------------------
void nome_cliente(char **nome){
    char aux[TAM_MAX];

    printf("Digite seu nome completo");
    fgets(aux, TAM_MAX, stdin);//Alocando memoria
    aux[strcspn(aux, "\n")]='\0';//Eliminando o \n --> não pula mais linhas
    strcpy(*nome, aux);
}
//--------------------------FUNÇÃO PARA ENDEREÇO DOS CLIENTES------------------------------------
void endereco_cliente(char **endereco){
    char aux[TAM_MAX];
    printf("Qual o seu endereço?");
    fgets(aux, TAM_MAX, stdin);
    aux(strcspn(aux, "\n"))='\0';
    strcpy(*endereco, aux);
}
//--------------------------FUNÇÃO PARA ENDEREÇO DOS CLIENTES------------------------------------
endereco_cliente(char **nome, char **endereco){
    printf("Nome que você colocou:")
    printf("%s", nome);
    printf("endereço que você colocou:");
    printd("%s", endereco);
}
