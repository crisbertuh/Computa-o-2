//CRISTIANO BERTULINO - Exercício 5
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 60
//Declaração das funções auxiliares
FILE* abre_arquivo(char caminho[19], char sel);
void fecha_arquivo(FILE* arquivo);

int main()
{
    /*
    1. Pedir 3 nomes e 3 CPFs.
    2. Abrir o arquivo binário para escrita.
    3. Gravar todos os dados no arquivo.
    4. Fechar o arquivo.
    5. Abrir o arquivo para leitura.
    6. Ler dados do arquivo.
    7. Mostrar na tela.
    8. fechar o arquivo.
    */

    FILE* dados_pessoais;
    char nome[TAM], cpf[11];

    printf("\t------------MENU-----------\t");
    //1. Pedir 3 nomes e 3 CPFs.
    printf("\nDigite o nome completo e o CPF de 3 pessoas.");
    //2. Abrir o arquivo binário para escrita.
    dados_pessoais = abre_arquivo("Dados_pessoais.bin", 'b');
    if(dados_pessoais==NULL){
        printf("\n\nErro ao abrir o arquivo!");
        return 1;
    }
    //3. Gravar todos os dados no arquivo.
    for(int i=0; i<3; i++){
        printf("\nQual o nome da %dª pessoa?: ", i+1);
        getchar();//Limpando buffer
        fgets(nome, TAM, stdin);//Lendo nomes
        nome[strcspn(nome, "\n")]='\t';//Trocando \n por um TAB

        printf("\nQual o CPF da %dª pessoa? (MÁXIMO DE 11 CARACTERES) ", i+1);
        getchar();//Limpando buffer
        fgets(cpf, 11, stdin);//Lendo CPF
        cpf[strcspn(cpf, "\n")]='\0';//Trocando \n por \0

        fwrite(nome, sizeof(char), TAM, dados_pessoais);
        fwrite(cpf, sizeof(char), TAM, dados_pessoais);
    }
    // 4. Fechar o arquivo.
    fecha_arquivo(dados_pessoais);
    //5. Abrir o arquivo para leitura.
    dados_pessoais = abre_arquivo("Dados_pessoais.bin", 'c');
    if (dados_pessoais == NULL) {
        printf("\nErro ao abrir o arquivo para leitura.");
        return 1;
    }

    printf("\n--- Dados Lidos do Arquivo ---");
    // 6. Ler e 7. Mostrar na tela (loop infinito até o EOF)
    int i = 0;
    // O fread retorna o número de elementos lidos com sucesso.
    while(fread(nome, sizeof(char), TAM, dados_pessoais) == TAM &&
          fread(cpf, sizeof(char), TAM, dados_pessoais) == TAM)
    {
        i++;
        printf("\n%dª Pessoa:", i);
        // Note que o caractere de TAB que você inseriu no nome será impresso.
        printf("\nNome: %s", nome); 
        printf("\tCPF: %s", cpf); 
    }

    // 8. fechar o arquivo.
    fecha_arquivo(dados_pessoais);

    return 0;
}

FILE* abre_arquivo(char caminho[19], char sel){
    FILE* arquivo;
    switch(sel){
        case 'w':
            arquivo=fopen(caminho, "w");
            break;
        case 'r':
            arquivo = fopen(caminho, "r");
            break;
        case 'a':
            arquivo = fopen(caminho, "a");
            break;
        case 'b':    
            arquivo=fopen(caminho, "wb");
            break;
        case 'c':
            arquivo = fopen(caminho, "rb");
            break;
        default:
            printf("\nErro ao abrir o arquivo! Selecione a opção correta.");
            return NULL;
    }
    return arquivo;
}

void fecha_arquivo(FILE* arquivo){
    fclose(arquivo);
}
