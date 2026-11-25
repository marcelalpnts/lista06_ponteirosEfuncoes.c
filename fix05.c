/*Escreva um programa em C que apresente a média, a mediana e a moda de um vetor de inteiros
gerados aleatoriamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularVetor(int *v, int n){
    for(int i = 0; i < n; i++){
        *(v+i) = rand() % 10;
    }
}

void imprimirVetor(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",*(v+i));
    }
    printf("\n");
}

float calcMedia(int *v, int n){
    int soma = 0;
    float media = 0;

    for(int i = 0; i < n; i++){
        soma += *(v+i);
    }
    media = (float) soma / n;

    return media;
}

int main (int argc, char argv[]){

    if(argc != 2){
        printf("Entrada inválida, tente %s <tamanho>\n", argv[0]);
        return 1;
    }

    int n = atoi (argv[1]);

    if(n <= 0){
        puts("Tamanho inválido para o vetor");
        return 1;
    }

    int *v = malloc (n* sizeof(int));

    srand(time(NULL));

    free(v);
    return 0;
}