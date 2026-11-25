/*Modifique a questão anterior criando uma função que armazena em um vetor os endereços do
primeiro e do último elemento PAR do vetor.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularVetor(int *v, int n){
    for (int i = 0; i < n; i++){
        *(v + i) = rand() % 10;
    }
}

void imprimirVetor(int *v, int n){
    for(int i = 0; i < n; i++){
        printf("%d\n",*(v+i));
    }
}

void encontraPar(int *v, int n, int **par){
*par = NULL;
*(par + 1) = NULL;

    for (int *p = v; p < v + n; p++) {
        if (*p % 2 == 0){
            *par = p; 
            break;    
        }
    }

    for(int *u = v + n - 1; u >= v; u--){
        if (*u % 2 == 0){
            *(par + 1) = u;
            break;
        }
    }
    
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

    int *pares[2];
    encontraPar(v,n,pares);

    if (pares[0] != NULL){
        printf("Primeiro par: %d | endereço: %p | posição: %ld\n", *pares[0], (void *)pares[0], pares[0] - v);

        printf("Último par:   %d | endereço: %p | posição: %ld\n", *pares[1], (void *)pares[1], pares[1] - v);
    } else {
        puts("Não foram encontrados pares");
    }

    free(v);
    return 0;
}