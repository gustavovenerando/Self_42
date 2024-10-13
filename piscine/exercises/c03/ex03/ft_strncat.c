#include <stdio.h>
#include <string.h>

int str_length(char *s){
    int i = 0;

    while(*s){
        s++;
        i++;
    }

    return i;
}

char *ft_strncat(char *dest, char *src, unsigned int nb){
    int dest_index = str_length(dest);
    
    int i = 0;
    while (*(src + i) && i < nb) {
        *(dest + dest_index + i) = *(src + i);
        i++;
    }

    *(dest + dest_index + i) = '\0';

    return dest;
}

int main(){
    char str1[30] = "ABZ";
    char test[30] = "ABZ";
    char str2[] = "AB";

    int n = 1;

    char *res = ft_strncat(str1, str2, n);
    char *x = strncat(test, str2, n);

    printf("Result: %s\n", res);
    printf("Official Result: %s\n", x);

    return 1;
}
