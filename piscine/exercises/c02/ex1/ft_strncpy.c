#include <stdio.h>

int ft_strlen(char *src){
    int i = 0;
    while(*src != '\0'){
        i++;
        src++;
    } 
    return i;
}

char *ft_strncpy(char *dest, char *src, unsigned int n) {
    int i = 0;
    int str_len = ft_strlen(src);

    while(i < n && i <= str_len){
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
    char *y = ft_strncpy(x, c, 12);
    printf("string 1: %s, string 2: %s\n", c, y);

}
