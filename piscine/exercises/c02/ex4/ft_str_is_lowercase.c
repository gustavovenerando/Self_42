#include <stdio.h>

int ft_char_is_lowercase(char c){
    int c_int = c;
    if(c_int >= 97 && c_int <= 122) return 1;
    return 0;
}

int ft_str_is_lowercase(char *str){
    if(*str == '\0') return 1;

    while(*str != '\0'){
        if(!ft_char_is_lowercase(*str)) return 0;
        str++;
    }

    return 1;
}

int main(){
    char str[] = "sadfa4sd";
    int res = ft_str_is_lowercase(str);
    printf("Result: %d\n", res);
}
