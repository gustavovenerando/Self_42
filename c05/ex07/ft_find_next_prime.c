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

int ft_find_next_prime(int nb){
    while(!ft_is_prime(nb)){
        nb++;
    }

    return nb;
}

int main(){
    int res = ft_find_next_prime(8);
    printf("Result: %d\n", res);
}
