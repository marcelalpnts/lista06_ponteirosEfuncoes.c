/*Escreva um programa em C que informe se o somatório da diagonal principal de matriz N x N
gerada é par ou ı́mpar.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popularMatriz(int *m, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            *(m + i*n+j) = rand() %11;

        }
    }
}

void imprimirMatriz(int *m, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            printf("%d ", *(m+i*n+j));
        }
        printf("\n");
    }

}

int somarDiagPrincipal(int *m, int n){
    int somatorio = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                somatorio += *(m + i*n + j);
            }
        }
    }

    return somatorio;
}

int main (int argc, char *argv[]){

            //validar argc
        if (argc != 2){
            printf("Entrada inválida. Forma correta: %s <tamanho>\n", argv[0]);
            return 1;
        }

            //conseguindo o tamanho das linhas e colunas
    int n = atoi (argv[1]);
        if(n <= 0) {
            puts("Tamanho não aceito, tente novamente");
            return 1;
        }

    //alocando a memoria da matriz
    
    int *m = malloc (n*n*sizeof(int));

    if(m == NULL){
        puts("Não foi possível alocar a memoria");
        return 1;
    }

    srand(time(NULL));
    int soma;

    popularMatriz(m,n);
    imprimirMatriz(m,n);

    soma = somarDiagPrincipal(m,n);
    printf("\nO somatorio da diagonal é %d\n", soma);

    if(soma % 2 == 0){
        puts("O somatório da diagonal principal é par");
    } else {
        puts("O somatorio da diagonal principal é impar");
    }

    free(m);
    return 0;
}