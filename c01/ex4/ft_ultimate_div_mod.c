#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b){
    int temp_a = *a;
    *a = *a/(*b);
    *b = temp_a%(*b);
}

int main(){
    int x = 10;
    int y = 2;
    printf("x is %d, y is %d\n", x, y);
    ft_ultimate_div_mod(&x, &y);
    printf("x is %d, y is %d\n", x, y);
}
