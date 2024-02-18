#include <stdio.h>

int ft_iterative_power(int nb, int power){
    if(power == 0 && nb == 0)
        return 1;
    if(power < 0) 
        return 0;

    int res = 1;
    while(power){
        res *= nb;
        power--;
    }

    return res;
}

int main(){
    int res = ft_iterative_power(0, 0);
    printf("Result: %d\n", res);
}
