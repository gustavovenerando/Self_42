#include <stdio.h>

int ft_is_prime(int nb){
    int res = 1;

    while(res*res < nb)
        res++;

    if(res*res == nb)
        return res;
    else
        return 0;
}

int main(){
    int res = ft_is_prime(4);
    printf("Result: %d\n", res);
}
