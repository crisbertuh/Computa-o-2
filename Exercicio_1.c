\\Cristiano Bertuliuno

/*1. Faça um programa que carregue um vetor de seis elementos numéricos inteiros,
calcule e mostre:
• a quantidade de números pares;
• quais os números pares;
• a quantidade de números ímpares;
• quais os números ímpares.*/

#include <stdio.h>
#include <string.h>

#define POS 6

int main(){
    int vet[POS], vet_par[POS], vet_imp[POS];
    int par=0, imp=0;
    
    //Faça um programa que carregue um vetor de seis elementos numéricos inteiros
    for(int i=0; i<POS; i++){
        printf("Digite o %dº número", i+1);
        scanf("%d", &vet[i]);
    }
    
    for(int i=0; i<POS; i++){
        //a quantidade de números pares
        if(vet[i]%2==0){
            vet_par[par]=vet[i];
            par++;
        }
        //a quantidade de números ímpares
        else 
        vet_imp[imp]=vet[i];
        imp++;
    }
    //quais os números pares
    printf("\nExistem %d núeros pares, eles sao:", par);
    for(int i=0; i<par; i++)
        printf("\n%d", vet_par[i]);
    //quais os números ímares
    printf("\nExistem %d núeros impares, eles sao:", imp);
    for(int i=0; i<imp; i++)
        printf("\n%d", vet_imp[i]);
    
    
    return 0;
}

