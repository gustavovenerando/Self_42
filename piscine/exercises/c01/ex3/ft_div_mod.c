#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod){
    *div = a / b;
    *mod = a % b;
}

int main(){
    int x = 0;
    int y = 0;
    printf("x is %d, y is %d\n", x, y);
    ft_div_mod(20, 10, &x, &y);
    printf("x is %d, y is %d\n", x, y);
}
