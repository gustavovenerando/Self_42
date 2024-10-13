#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c){
    write(1, &c, 1);
}
void ft_putstr(char *str){
    while(*str != '\0'){
        // ft_putchar(*str);
        write(1, str, 1);
        str++;
    }
    ft_putchar('\n');
}

int main(){
    char sc[] = "Hello Moto";
    // printf("string is %s\n", sc);
    ft_putstr(sc);
    // printf("x is %d, y is %d\n", x, y);
}
