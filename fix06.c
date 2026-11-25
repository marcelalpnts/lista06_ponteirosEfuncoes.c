/*Calcule o erro médio quadrático entre dois vetores A e B de dimensão n. Pesquise a equação.
Construa uma função para cálculo do erro.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularVetor(int *v, int n){
    for(int i = 0; i < n; i++){
        *(v + i) = rand() % 10;
    }
}

void imprimirVetor(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", *(v + i));
    }
    printf("\n");
}

float ErroMedioQuadratico(int *a, int *b, int n, float *error){
    int subtracao = 0;
    int somatorio = 0;

    for(int i = 0; i < n; i++){
        subtracao = (*(a + i) - *(b + i));
        subtracao = subtracao * subtracao;
        somatorio += subtracao;
    }

    *error = (float) somatorio / n;
}
int main(int argc, char *argv[]){
    // validando argc
    if (argc != 2) {
        printf("Entrada errada. Por favor tente novamente no formato: %s <tamanho_n>\n", argv[0]);
        return 1;
    }

    // atribuindo n via atoi
    int n = atoi(argv[1]);
    if(n <= 0){
        puts("Tamanho inválido, tente novamente");
        return 1;
    }

    srand(time(NULL));

    // alocando memoria para vetores A e B
    int *A = malloc(n* sizeof(int));
    int *B = malloc(n* sizeof(int));

    if(A == NULL){
        puts("Memoria não alocada");
        return 1;
    }

    if(B == NULL){
        puts("Memoria não alocada");
        free(A);
        return 1;
    }

    popularVetor(A,n);
    puts("Imprimindo vetA");
    imprimirVetor(A,n);
    popularVetor(B,n);
    puts("Imprimindo vetB");
    imprimirVetor(B,n);

    float erroMedioQ;

    ErroMedioQuadratico(A, B, n, &erroMedioQ);

    printf("O erro medio quadrático é %.2f\n", erroMedioQ);

    free(A);
    free(B);

    return 0;
}