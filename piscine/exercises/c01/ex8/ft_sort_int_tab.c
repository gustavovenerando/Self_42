#include <stdio.h>

void ft_sort_int_tab(int *tab, int size) {
    int minor_idx = 0;

    for (int i = 0; i < size - 1; i++) {
        int curr_num = *(tab + i);
        int minor_num = 2147483647;

        for (int j = i; j < size; j++) {
            int verify_number = *(tab + j);

            if (verify_number < minor_num) {
                minor_idx = j;
                minor_num = verify_number;
            }
        }
        printf("minor number is: %d\n", minor_num);

        *(tab + i) = *(tab + minor_idx);
        *(tab + minor_idx) = curr_num;
    }
}

void printArray(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d, ", *(arr + i));
    }
    printf("\n");
}

int main(){
    int arr[] = {3,1,-4,2,5};
    printArray(arr, 5);
    ft_sort_int_tab(arr, 5);
    printArray(arr, 5);
}
