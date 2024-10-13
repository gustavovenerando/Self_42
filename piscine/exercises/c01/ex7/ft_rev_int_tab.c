#include <stdio.h>

void ft_rev_int_tab(int *tab, int size){
    for (int i = size - 1; i >= size/2; i--) {
        int temp = *(tab + i);
        printf("%d ", size - 1 - i);
        *(tab + i) = *(tab + size - 1 - i);
        *(tab + size - 1 - i) = temp;
    }
    printf("\n");
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", *(arr + i));
    }
    printf("\n");
}

int main(){
    int arr[] = {1,2,3,4,5};
    printArray(arr, 5);
    ft_rev_int_tab(arr, 5);
    printArray(arr, 5);
}
