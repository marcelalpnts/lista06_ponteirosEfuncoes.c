/*Escreva um programa em C que binarize os elementos de uma matriz M , criando a matriz S*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularMatriz(int *m, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            *(m + i*n + j) = rand() % 10;
        }
    }
}

void imprimirMatriz(int *m, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ",*(m + i*n + j));
        }
        printf("\n");
    }
}

void binarizarMatriz(int *m, int *s, int n, int t){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (*(m + i*n + j) > t){
                *(s+ i*n+j) = 1;
            } else {
                *(s + i*n + j) = 0;
            }
        }
    }
}

int main (int argc, char *argv[]){

    if (argc != 3){
        printf("Entrada inválida. Tente no formato %s <tamanho_matriz> <limiar_t>\n");
        return 1;
    }

    // criando o tamanho das matrizes e de t

    int n = atoi (argv[1]);
    int t = atoi (argv[2]);

    if (n <= 0){
        puts("Entrada inválida. Tente novamente");
        return 1;
    }

    srand(time(NULL));

    int *M = malloc (n*n * sizeof(int));
    int *S = malloc (n*n * sizeof(int));

    if(M == NULL){
        puts("Não foi possivel alocar memoria. Tente novamente.");
        free(S);
        return 1;
    }

    if(S == NULL){
        puts("Não foi possível alocar memoria. Tente novamente");
        free(M);
        return 1;
    }

    popularMatriz(M,n);
    puts("Imprimindo Matriz M");
    imprimirMatriz(M,n);
    binarizarMatriz(M,S,n,t);
    puts("Imprimindo Matriz Binarizada");
    imprimirMatriz(S,n);

    free(M);
    free(S);
    return 0;
}