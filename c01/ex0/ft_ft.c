#include <stdio.h>

void ft_ft(int *nbr){
    *nbr = 42;
}

int main(){
    int n = 3;
    printf("n is equal to: %d\n", n);
    ft_ft(&n);
    printf("n is equal to: %d\n", n);
}
