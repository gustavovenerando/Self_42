#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n){
    int i = 0;

    if(n == 0) return 0;

    while((s1[i] || s2[i]) && (s1[i] == s2[i]) && i < n - 1){
        i++;
    }

    return s1[i] - s2[i];
}

int main(){
    char str1[] = "";
    char str2[] = "";

    int n = 0;

    int res = ft_strncmp(str1, str2, n);
    int x = strncmp(str1, str2, n);

    printf("Result: %d\n", res);
    printf("Official Result: %d\n", x);
}
