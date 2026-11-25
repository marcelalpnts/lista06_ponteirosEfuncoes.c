/*Escreva uma função que some todos os elementos de um vetor de float. Utilize a função rand()
para alimentar o vetor com valores pseudo-aleatórios. A variável de somatório deve ser fornecida
por referência para a função.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularVetor(float *v, int n){

    for (int i = 0; i < n; i++){
        *(v + i) = (float)rand() / RAND_MAX * 100;
    }

}

void imprimirVetor(float *v, int n){
    for (int i = 0; i < n; i++) {
        printf("%.2f \n",*(v+i));
    }  
}

void somatorio(float *v, int n, float *s){
    *s = 0;
    for (int i = 0; i < n; i++){
        *s += *(v + i);
    }
}

int main (int argc, char *argv[]){

    if (argc != 2){
        printf("Entrada invalida, por favor faça %s <tamanho>\n", argv[0]);
        return 1;
    }

    int n = atoi (argv[1]);
    if (n <= 0){
        puts("Tamanho inválido");
        return 1;
    }

    float *v = malloc(n * sizeof(float));

    if (v == NULL){
        puts("Não foi possivel alocar memoria");
        return 1;
    }

    srand(time(NULL));
    float soma;
    popularVetor(v,n);
    imprimirVetor(v,n);
    somatorio(v,n, &soma);

    printf("O somatorio de todos os termos do vetor é %.2f\n", soma);

    free(v);
    return 0;
}