/* AULA SOBRE ALOCAÇÃO DINÂMICA DE MEMÓRIA 1/SET
--------------------------------------------------------------------
--> A diferença de um ponteiro e uma variável é o '*':
    int variavel;
    int* ponteir;.
--------------------------------------------------------------------------------------------
--> Para inicializar o ponteriro não precisa de asterisco '*'.
    ponteiro = &variavel;
--> para atribuir um valor precisa de asterisco '*'.
    *ponteiro = 5;
--> Para mostrar o endereço/variável em hexadecimal utiliza-se %p.
--------------------------------------------------------------------------------------------
    ALOCAÇÃO DINÂMICA
    Vamos criar um ponteiro que seja um vetor.
    Vamos preenchê-lo de 1 a 5.
    Vamos recria-lo para suportar mais números (de 1 a 10).
          --> Utilizar malloc (biblioteca <stdlib.h>).
---------------------------------------------------------------------------------------------
*/

#include <stdio.c>
#include <stdlib.h>

int main(){
  //Forma correta int* vet=NULL;
  int* vet, aux;
  //Alocando uma memória no ponteiro/vetor. --> 5 posições em vet.
  vet=(int*) malloc(5 * sizeof(int));
  if(vet==NULL){
    printf("\nProblema ao alocar memoria.");
    return 0;
  }
  aux=vet;//Guardando a primeira posição do vetor.
//--------------------------------------------------------------------------------------------  
  /* JEITO PRIMITIVO DE PREENCHER (AINDA SEM ALOCAÇÃO DE MEMORIA).
  vet[0]=1;
  vet[1]=2;
  vet[2]=3;      TRABALHO COMO SE FOSSE UM VETOR E NÃO PERCO A REFERÊNCIA.
  vet[3]=4;
  vet[4]=5;
  printf("Valores de vet[%d, %d, %d, %d, %d]", vet[0], vet[1], vet[2], vet[3], vet[4]);*/
//---------------------------------------------------------------------------------------------
  //Atribui 1 a cinco em vet
  for(int i=0; i<5; i++){
      *vet=i;//Muda o endereço do ponteiro   --> CUIDADO!!! CADA VEZ QUE EU MUDO O ENDEREÇO DE MEMORIA EU MUDO A REFERENCIA (POSIÇÃO DO VET[0]).
      vet++;//Incrementa a posição do vetor  --> JEITO PRIMITIVO: POSSO ARRUMAR FAZENDO vet--; CINCO VEZES.
  }
  printf("Valores de vet[%d, %d, %d, %d, %d]", vet[0], vet[1], vet[2], vet[3], vet[4]);
  //NÃO CONSEGUIMOS DESALOCAR A MEMÓRIA.
  aux=(int*) realloc(aux, 10*sizeof(int));//Realocando a posição inical de vet salva em aux. --> CUIDADO!!! PODE ESTAR NA POSIÇÃO QUE NÃO FOI REALOCADA.
  for(int i=0; i<5; i++){
      vet++;//Andando vet até chegar na quinta posição.
  }
  for(int i=5; i<10; i++){
    *vet=i;//Preenchendo a partir da sexta posição.
    vet++;
  }

  free(vet);//Uma forma de liberar a umtima memória alocada.
  return 0
}
