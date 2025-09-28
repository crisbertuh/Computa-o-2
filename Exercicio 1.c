\Cristiano Bertulino

/*1. Faça um programa computacional que possua 2 funções distintas que:
a. Determine se um número é par. Protótipo: int eh_par(int);
b. Calcule a média de 2 números, Protótipo: float media(float, float);*/

#include <stdio.h>

int eh_par(int *x);
float media(float m);

int main(){
    int num1=0, num2=0, par=0, imp=0;
    float media=0;
    
    printf("Digite o primeiro numero\n");
    scanf("%d", &num1);
    eh_par(&num1);
    if(eh_par==0)
        par++;
    else
    imp++;
    printf("Digite o segundo numero\n");
    scanf("%d", &num2);
    eh_par(&num2);
    if(eh_par==0)
        par++;
    else
    imp++;
    
    return 0;
}

int eh_par(int *x){
    if(*x%2==0)
        return 1;
    else
    return 0;
}
