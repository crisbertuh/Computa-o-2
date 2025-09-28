\\Crstiano Bertulino
/*Desenvolva um programa computacional capaz de alocar,
dinamicamente, uma matriz de strings onde cada linha da matriz contenha
exatamente, os seguintes nomes definidos abaixo. A matriz deve,
primeiramente ser alocada e, depois, os nomes devem ser inseridos na
matriz.
    |R|E|N|A|T|A| |C|O|E|L|H|O|\0|
    |F|A|B|I|O| |P|I|R|E|S|\0|
    |R|E|N|A|T|O|\0|
    |M|A|R|C|E|L|O| |O|L|I|V|E|I|R|A|\0|
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TAM_MAX 256
#define LIN 4

void libera_matriz(char **M, int m);

int main(){
    char **mat;
    char nome1[]="RENATA COELHO";
    char nome2[]="FABIO PIRES";
    char nome3[]="RENATO";
    char nome4[]="MARCELO OLIVEIRA";
    char *nomes[]={nome1, nome2, nome3, nome4};
    
    mat=(char**)malloc(4 * sizeof(char*));
    
    for(int i=0; i<LIN; i++){
        size_t tamanho=strlen(nomes[i])+1;
        
        mat[i]=(char*)malloc(tamanho * sizeof(char));
        
        strcpy(mat[i], nomes[i]);
        printf("%s\n", mat[i]);
    }
    
    libera_matriz(mat, LIN);
    
    return 0;
}

void libera_matriz(char **M, int m){
    if(M==NULL)
        return;
    for(int i=0; i<LIN; i++){
        if(M[i]!=NULL)
            free(M[i]);
        
    }
    free(M);
}
