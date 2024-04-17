/* 

    @author: Matheus Rebello;
    @date: 16/04/2024;
    @name: Recursive Array Sum;

*/

#include <stdio.h>
#include <stdlib.h>

int *allocate_int_array(int s);
int sumr(int v[], int n);


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
        printf("Não foi possivel alocar o array com o tamanho de entrada!\n");
        return 1;
    }

    printf("Soma dos elementos do array: %d\n", sumr(arr, size));
    free(arr);

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

    printf("Elementos do array: [");
    int i;
    for (i = 0; i < s; i++) {
        v[i] = i;
        printf(i < s - 1 ? "%d " : "%d", v[i]);
    }
    printf("]\n");
    
   return v;
}

// Calcula a soma dos elementos do array 'v' de forma recursiva.
int sumr(int v[], int n) {
    if (n == 0) { // caso base
        return v[0];
    } else {
        return v[n - 1] + sumr(v, n - 1); // soma recursiva
    }
}