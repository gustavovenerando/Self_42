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

char *ft_strcat(char *dest, char *src){
    int dest_index = str_length(dest);
    printf("Length value: %d\n", dest_index);
    
    int i = 0;
    while (*(src + i)) {
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

    char *res = ft_strcat(str1, str2);
    char *x = strcat(test, str2);

    printf("Result: %s\n", res);
    printf("Official Result: %s\n", x);

    return 1;
}
