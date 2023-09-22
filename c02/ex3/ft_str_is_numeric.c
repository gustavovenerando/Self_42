#include <stdio.h>

int ft_char_is_numeric(char c){
    int c_int = c;
    if(c_int >= 48 && c_int <= 57) return 1;
    return 0;
}

int ft_str_is_numeric(char *str){
    if(*str == '\0') return 1;

    while(*str != '\0'){
        if(!ft_char_is_numeric(*str)) return 0;
        str++;
    }

    return 1;
}

int main(){
    char str[] = "";
    int res = ft_str_is_numeric(str);
    printf("Result: %d\n", res);
}
