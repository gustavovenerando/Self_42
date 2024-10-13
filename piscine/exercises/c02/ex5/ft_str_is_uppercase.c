#include <stdio.h>

int ft_char_is_uppercase(char c){
    int c_int = c;
    if(c_int >= 65 && c_int <= 90) return 1;
    return 0;
}

int ft_str_is_uppercase(char *str){
    if(*str == '\0') return 1;

    while(*str != '\0'){
        if(!ft_char_is_uppercase(*str)) return 0;
        str++;
    }

    return 1;
}

int main(){
    char str[] = "ALSDfH";
    int res = ft_str_is_uppercase(str);
    printf("Result: %d\n", res);
}
