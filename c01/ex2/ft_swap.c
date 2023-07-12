#include <stdio.h>

void ft_swap(int *a, int *b){
    int temp_a = *a;
    *a = *b;
    *b = temp_a;
}

int main(){
    int x = 10;
    int y = 15;
    printf("x is %d, y is %d\n", x, y);
    ft_swap(&x, &y);
    printf("x is %d, y is %d\n", x, y);
}
