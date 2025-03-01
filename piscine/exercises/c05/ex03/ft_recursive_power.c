#include <stdio.h>

int ft_recursive_power(int nb, int power){
    if(power == 0 && nb == 0)
        return 1;

    if(power >= 1)
        return nb * ft_recursive_power(nb, power - 1);
    else if(power == 0)
        return 1;
    else
        return 0;
}

int main(){
    int res = ft_recursive_power(2, 5);
    printf("Result: %d\n", res);
}
