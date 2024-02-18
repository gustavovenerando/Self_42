#include <stdio.h>

int ft_interative_factorial(int nb){
    if(nb == 0) return 1;
    if(nb < 0) return 0;
    int res = 1;
    while(nb){
        res *= nb;
        nb -= 1;
    }

    return res;
}

int main(){
    int res = ft_interative_factorial(-1);
    printf("Result: %d\n", res);
}
