#include <stdio.h>

int ft_strlen(char *str){
    int cont = 0;
    while(*str != '\0'){
        cont++;
        str++;
    }
    return cont;
}

int main(){
    char sc[] = "Hello Moto";
    int len = ft_strlen(sc);
    printf("string has %d chars\n", len);
    // printf("x is %d, y is %d\n", x, y);
}
