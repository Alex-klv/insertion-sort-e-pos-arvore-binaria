#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 100

//ÁRVORE BINÁRIA

typedef struct noda{
    int num;
    struct noda *esquerda;
    struct noda *direita;
}arvore;

//Função de criar um no novo
arvore* novonode(int valor) {
    arvore* node = (arvore*) malloc(sizeof(arvore));
    node->num = valor;
    node->esquerda = NULL;
    node->direita = NULL;
    return node;
}

//Função de inserir no novos na arvore
arvore* inserir(arvore* raiz, int valor) {
    if (raiz == NULL) {
        return novonode(valor);
    }
    if (valor < raiz->num) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->num) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

//Função da arvore em pos ordem
void posOrdem(arvore* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->num);
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
    }
}

int lista[N], comp = 0;

int main(){

    clock_t tempo;
    setlocale(LC_ALL, "Portuguese_Brazil");
    srand(time(NULL));

    int modulo;
    int a, b, igual;
    arvore *raiz = NULL;

    printf("========== INTEGRANTES DO GRUPO ==========\n\n");

    printf("Nome: Deyvy Anthony Rocha Claudino Gomes \n");
    printf("Matrícula: 2024 0291 2852 \n\n");

    printf("Nome: Alexander Kalev Almeida Frazão\n");
    printf("Matrícula: 2024 0256 6776 \n\n");

    printf("Últimos dois dígitos foram: 2 e 6 \n     ");

    modulo = 8 % 3;

    printf("Resultado da operação: %d\n", modulo);
    printf("\n              INSERTION SORT      \n");
    printf("===========================================\n\n");

    getchar(); // espera o usuario apertar enter para continuar 

    printf("Vetor desordenado:");

    for(a = 0; a < N; ){
        
        int Nrandom = rand() % 1000 + 1;
        igual = 0;
        
        for(b = 0; b < a; b++){
            if(lista[b] == Nrandom){
                igual = 1;
                break;
            }
        }
        
        if(igual == 0){
            
            lista[a] = Nrandom;
            raiz = inserir(raiz, lista[a]);
            a++;
        }
    }
    
    for(a = 0; a < N; a++){
        
        printf("%d ", lista[a]);
    }

    getchar(); // espera o usuario apertar enter para continuar

    insertionSort(lista, N);

    printf("\n\n\nVetor ordenado:");

    tempo = clock();
    for(a = 0; a < N; a++){

        printf(" %d", lista[a]);
    }
    printf("\n\nQuantidades de comparações: %d", comp);
    
    tempo = clock() - tempo;
    
    printf("\n\nO tempo gasto na execução da ordenação foi de: %f ms\n", ((float)tempo) / CLOCKS_PER_SEC * 1000);
    
    printf("\n\n        ÁRVORE BINÁRIA EM POS-ORDEM    \n");
    printf("===========================================\n\n");
    getchar();
    printf("ÁRVORE EM POS-ORDEM\n\n");
    posOrdem(raiz);
    printf("\n\n===========================================");
}


//INSERTION SORT

void insertionSort(int *lista, int tamanho){ 

    int i, j, aux;

    for(i = 0; i < tamanho-1; i++){

        comp++;

        if(lista[i] > lista[i + 1]){

            aux = lista[i+1];
            lista[i+1] = lista[i]; lista[i] = aux;
            j = i-1; 

            while(j >= 0){

                if(aux < lista[j]){

                    lista[j+1] = lista[j]; lista[j] = aux; 
                }
                else{
                    break;
                }
                j = j-1;
            }
        }

    }

}