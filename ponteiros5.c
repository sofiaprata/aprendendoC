//Dado um vetor de inteiros de tamanho N, use ponteiros para referenciar o menor e o maior elemento

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MX 100
#define TAM 2

//void preencher(int *pv, int q){
//void imprimir(int *pv, int q){

int main(){
    int n;
    int *p = NULL;

    puts("Digite a quantidade de elementos: \n");
    scanf("%d", &n);

    p = (int*) malloc(n * sizeof(int));  //malloc aloca dinamicamente a memoria

    if (!p){
        puts("Memória insuficiente!");
        exit(1);
    }

    srand(time(NULL));
    preencher(p,n);
    imprimir(p,n);

    //int *v[TAM] = {NULL, NULL};

    int **v = NULL;

    v = (int **) malloc(TAM * sizeof(int*));
    if(!v){
        puts("Memória insuficiente!");
        exit(2);
    }

    *v = p;
    *(v+1) = p;

    for(int k = 1; k<n; k++){
        *v = (**v > *(p+k))?p+k: *v; //Se ponteiro menor maior que o ponteiro seguinte, entao p + k recebe o ponteiro menor
        *(v+1) = (*(*(v+1)) < *(p+k))?p+k: *(v+1); // Se o ponteiro maior é menor que o ponteiro seguinte, então p+ k recebe o ponteiro maior
    }

        printf("Endereço do menor : %p\n", *v);
        printf("Endereço do maior : %p\n", *(v+1));

    free(p);
    free(v);

    return 0;
}


void preencher(int *pv, int q){
    
    //Deslocamento de ponteiro
    for(int k = 0; k<q; k++){
        *(pv+k) = rand() % MX;  // vai deslocando para o proximo endereço
        // ou pv[k] = rand() % MX;
    }

}

void imprimir(int *pv, int q){
    for (int k = 0;k<q; k++){
        printf("[%p] %d\n", pv+k, *(pv + k));
    }
}
