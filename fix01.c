/*Escreva um programa em C que informe o endereço do primeiro elemento PAR de um vetor de
inteiros.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularVetor(int *v, int n){
    for (int i = 0; i < n; i++){
        *(v + i) = rand() % 100;
    }
}

void imprimirVetor(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("%d\n",*(v+i));
    }
}

int *encontraPar(int *v, int n){

    for (int *p = v; p < v + n; p++) {
        if (*p % 2 == 0){
            return p;
        }
    }

    return NULL;
    
}

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("uso inválido, por favor fazer: %s <tamanho>\n", argv [0]);
        return 1;
    }
    // validando argv
    int n = atoi(argv[1]);
    if (n <= 0){
        puts("Tamanho invalido");
        return 1;
    }
    // alocando memoria para o vetor

    int *v = malloc(n * sizeof(int));
    if (v == NULL){
        puts("sem memoria");
        return 1;
    }

    srand(time(NULL));
    popularVetor(v, n);
    imprimirVetor(v,n);

    int *ptrPar = encontraPar(v, n);

    if(ptrPar){
    printf("Endereço: %p | Valor: %d | Posição: %ld\n",(void *)ptrPar,*ptrPar,ptrPar - v);
}

    else {
        puts("Não foi encontrado numero par");
    }

    free(v);
    return 0;
}