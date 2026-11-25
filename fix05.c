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

float calcMediana(int *v, int n){
    int *copia = malloc (n * sizeof(int));
    if (copia == NULL){
        puts("Não foi possível alocar a memoria pro vetor copia");
        return -1;
    }

    for(int i = 0; i < n; i++){
        *(copia + i) = *(v + i);
    }

    //ordenando via bubble sort
    for(int i = 0; i < n - 1; i++){ //calcula quantas passadas ele da no vetor
        for(int j = 0; j < n - 1 - i; j++){ // calcula as comparações entre os pares
            if (*(copia + j) > *(copia + j + 1)){
                int aux = *(copia + j);
                *(copia + j) = *(copia + j + 1);
                *(copia + j + 1) = aux;
            }
        }
    }

    float mediana;
    if (n % 2 != 0){ //se isso for vdd, n é impar
        mediana = *(copia + n/2);
    } else { //caso nao, é par
        mediana = ((float) *(copia + n/2) + *(copia + n/2 - 1))/2;
    }

    free(copia);
    return mediana;
}

int calcModa (int *v, int n){
    int *cont = calloc(10, sizeof(int));
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