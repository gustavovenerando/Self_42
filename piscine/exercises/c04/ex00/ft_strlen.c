#include <stdio.h>

int ft_strlen(char *str){
    int cont = 0;
    while(*str){
        cont++;
        str++;
    }

    return cont;
}

int main(){
    char test[] = "Aloha";
    int res = ft_strlen(test);
    printf("Result: %d\n", res);
}
