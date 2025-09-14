/*Peça o nome de tres colegas, completo.
Coloque os nomes em 3 linhas de uma matrize de tamanho certo.
Utilizar realocamento em matrizes.
Por fim, deve desalocar o programa de forma correta.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOMES 256
#define QTD_NOMES 3

int main() {
    char **nomes;

    // Aloca espaço para 3 ponteiros (cada um vai guardar um nome)
    nomes = malloc(QTD_NOMES * sizeof(char *));
    if (nomes == NULL) {
        printf("Erro ao armazenar nomes\n");
        return 1;
    }

    printf("Digite o nome dos tres colegas:\n");
    for (int i = 0; i < QTD_NOMES; i++) {
        char aux[TAM_NOMES];

        printf("Colega %d: ", i + 1);
        if (fgets(aux, sizeof(aux), stdin) == NULL) {
            printf("Erro ao ler nome\n");
            return 1;
        }

        aux[strcspn(aux, "\n")] = '\0'; // remove o \n

        // Aloca exatamente o tamanho do nome digitado
        nomes[i] = malloc((strlen(aux) + 1) * sizeof(char));
        if (nomes[i] == NULL) {
            printf("Erro ao alocar memoria\n");
            return 1;
        }

        strcpy(nomes[i], aux);
    }

    // Exibe os nomes armazenados
    printf("\n--- Nomes armazenados ---\n");
    for (int i = 0; i < QTD_NOMES; i++) {
        printf("%s\n", nomes[i]);
    }

    // Libera memória
    for (int i = 0; i < QTD_NOMES; i++) {
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}
