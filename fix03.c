/*Escreva um programa que dado um vetor X de inteiros, realize a seguinte normalização dos dados (min-max) - onde min() e max() correspondem ao menor e maior do vetor, respectivamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularEscreverVetor(int *v, int n){
    for(int i = 0; i < n; i++){
        *(v + i) = rand() % 10;
        printf("%d ", *(v+i));
    }
    printf("\n");
}

void normalizarDados(int *v, int n){
    int i = 0;
    int Xmax = *(v + i);
    int Xmin = *(v + i);
    float normalizado;

//encontrando maior/menor
    for (i = 1; i < n; i++){
        if (Xmax < *(v+i)){
            Xmax = *(v+i);
        }

        if (Xmin > *(v+i)){
            Xmin = *(v+i);
        }
    }

    if(Xmax == Xmin){
        puts("A normalização nao é possivel");
    } else {

        for(int j = 0; j < n; j++){
            normalizado = (float) (*(v+j) - Xmin) / (Xmax - Xmin);
            printf("X%d' = %.2f\n", j, normalizado);
        }
    }
}

int main (int argc, char *argv[]){
    srand(time(NULL));


    //validação argc
    if (argc != 2){
        printf("Argumentação inválida. Tente %s <tamanho_vet>\n", argv[0]);
        return 1;
    }

    int n = atoi (argv[1]);
    if(n <= 0){
        puts("tamanho de vetor inválido. Tente novamente.");
        return 1;
    }

    int *X = malloc(n* sizeof(int));
    if(X == NULL){
        puts("Não foi possivel alocar a memoria, tente novamente");
        return 1;
    }

    popularEscreverVetor(X,n);
    normalizarDados(X,n);

    free(X);
    return 0;
}