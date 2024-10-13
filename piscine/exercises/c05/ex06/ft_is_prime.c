#include <stdio.h>

int ft_is_prime(int nb){
    if(nb == 1 || nb == 0) return 0;
    int temp = nb - 1;
    while(temp >= 2){
        if(nb % (temp) == 0)
            return 0;
        temp--;
    }

    return 1;
}

int main(){
    int res = ft_is_prime(2);
    printf("Result: %d\n", res);
}
