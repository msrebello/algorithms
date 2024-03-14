/* 

    @author: Matheus Rebello;
    @date: 13/03/2024;
    @name: Binary Search;

*/


#include<stdio.h>

#define NOT_FOUND -1


int list[] = {1, 3, 5, 7, 9};
int arr_length = sizeof(list) / sizeof(list[0]); // Calcula o comprimento da lista dividindo o tamanho total em bytes pelo tamanho em bytes do primeiro elemento.

int binary_search(int arr[], int target);

int main(int argc, char const *argv[])
{   
    int target = 7;

    int pos = binary_search(list, target);

    if(pos == NOT_FOUND)
        printf("Target not found!\nThat target is not on array\n");
    else
        printf("Target position: %d\n", pos);

    return 0;
}

/**
 * Realiza uma busca binária no array fornecido para encontrar o item especificado.
 * O array deve estar ordenado em ordem crescente para obter resultados corretos.
 * 
 * @param arr o array no qual será procurado o alvo
 * @param target o alvo a ser procurado
 * @return o índice do alvo se encontrado; caso contrário, retorna um valor sentinela indicando que o elemento não foi encontrado
*/

int binary_search(int arr[], int target) {

    int lower_bound = 0;
    int upper_bound = arr_length - 1;

    while (lower_bound <= upper_bound)
    {
        int middle = (lower_bound + upper_bound) / 2;
        int current_item = arr[middle];

        if(current_item == target)
            return middle;
        else if(current_item > target)
            upper_bound = middle - 1;
        else
            lower_bound = middle + 1;
    }
    
    return NOT_FOUND;
}