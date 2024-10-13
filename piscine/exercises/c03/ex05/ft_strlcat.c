#include <stdio.h>
#include <bsd/string.h>

int str_length(char *s){
    int i = 0;

    while(*s){
        s++;
        i++;
    }

    return i;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size){
    int str_proj = str_length(dest) + str_length(src);

    int dest_index = str_length(dest);

    int i = 0;
    while (*(src + i) && (i + dest_index < size - 1)) {
        *(dest + dest_index + i) = *(src + i);
        i++;
    }

    *(dest + dest_index + i) = '\0';


    return str_proj;
}

int main(){
    char str1[6] = "ABZ";
    char test[6] = "ABZ";
    char str2[] = "AB";

    int size_str1 = sizeof(str1)/sizeof(char);
    int size_test = sizeof(test)/sizeof(char);

    printf("Str1 bytes: %d - Test bytes: %d\n", size_str1, size_test);

    int res = ft_strlcat(str1, str2, size_str1);
    int x = strlcat(test, str2, size_test);

    printf("Result: %d - %s\n", res, str1);
    printf("Official Result: %d - %s\n", x, test);

    return 1;
}
