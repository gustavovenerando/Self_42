#include <stdio.h>

int ft_strcmp(char *s1, char *s2){
    int i = 0;

    while((s1[i] != '\0' || s2[i] != '\0')&& s1[i] == s2[i]){
        i++;
    }

    return s1[i] - s2[i];
}

int main(){
    char str1[] = "ABZ";
    char str2[] = "AB";

    int res = ft_strcmp(str1, str2);

    printf("Result: %d\n", res);
}
