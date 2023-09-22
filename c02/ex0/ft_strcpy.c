#include <stdio.h>

char *ft_strcpy(char *dest, char *src) {
    int i = 0;
    while (*(src + i)) {
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest + i) = '\0';

    return dest;
}

int main(){
    char c[] = "Hello";
    char x[] = "Hehee";

    printf("string 1: %s, string 2: %s\n", c, x);
    char *y = ft_strcpy(x, c);
    printf("string 1: %s, string 2: %s\n", c, y);

}
