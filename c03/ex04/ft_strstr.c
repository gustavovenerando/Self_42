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

char *ft_strstr(char *str, char *to_find){
    int i = 0;
    int j = 0;
    int found = 0;

    int length = str_length(to_find);

    while(*(str + i)){
        if(str[i] == to_find[j]){
            j++;
        }
        else{
            j = 0;
        }

        if(j == length){
            found = 1;
            break;
        }

        i++;
    }

    if(found == 0) return NULL;

    return str + i - (j - 1);
}

int main(){
    char str1[] = "DFAZBZA";
    char test[] = "DFAZBZA";
    char str2[] = "FAB";

    char *res = ft_strstr(str1, str2);
    char *x = strstr(test, str2);

    printf("Result: %s\n", res);
    printf("Official Result: %s\n", x);

    return 1;
}
