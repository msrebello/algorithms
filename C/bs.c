/* 

    @author: Matheus Rebello;
    @date: 13/03/2024;
    @name: Binary Search;

*/


#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND -1

int attempts = 0;

int *allocate_int_array(int s);
int binary_search(int arr[], int target, int s);

int main(int argc, char const *argv[]) {   
    int size;

    printf("Tamanho para array: ");
    scanf("%d", &size);

    if (size < 1) {
        printf("Tamanho invalido!\n");
        return 1;
    }

    int *arr = allocate_int_array(size);

    if (arr == NULL) {
        printf("Não foi possivel alocar o array!\n");
        return 1;
    }

    int target;

    printf("Digite o alvo (elemento) a ser encontrado no array: ");
    scanf("%d", &target);

    int pos = binary_search(arr, target, size);

    if(pos == NOT_FOUND) {
        printf("Elemento não encontrado!\n"
            "O alvo digitado não esta contido no array!!\n");
    } else {
        printf("Alvo encontrado!\n"
            "Posicao do alvo no array: %d\n"
            "Numero de tentativas ate encontrar o alvo: %d\n", pos, attempts);
    }

    return 0;
}

/*
    Aloca dinamicamente memória para um array de inteiros 
    de tamanho 'size', preenche-o com valores sequenciais 
    e retorna um ponteiro para o array.
*/

int *allocate_int_array(int s) {
    int *v = malloc(s * sizeof(int));

    if (!v) {
        return NULL;
    }

    int i;
    printf("Elementos do array: [");

    for (i = 0; i < s; i++) {
        v[i] = i * 4;
        printf(i < s - 1 ? "%d " : "%d", v[i]);
    }

    printf("]\n");
    
   return v;
}

/**
 * Realiza uma busca binária no array fornecido para encontrar o item especificado.
 * O array deve estar ordenado em ordem crescente para obter resultados corretos.
 * 
 * @param arr o array no qual será procurado o alvo
 * @param target o alvo a ser procurado
 * @return o índice do alvo se encontrado; caso contrário, retorna um valor sentinela indicando que o elemento não foi encontrado
*/

int binary_search(int arr[], int target, int s) {

    int low = 0;
    int high = s - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == target) {
            attempts++;
            return mid;
        } else if(arr[mid] < target) {
            attempts++;
            low = mid + 1;
        } else {
            attempts++;
            high = mid - 1;
        }    
    }
    
    return NOT_FOUND;
}