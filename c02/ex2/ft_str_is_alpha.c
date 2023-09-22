#include <stdio.h>

int char_is_alpha(char c){
    int c_int = c;
    if((c_int >= 65 && c_int <= 90) || (c_int >= 97 && c_int <= 122)) return 1;
    return 0;
}

int ft_str_is_alpha(char *str){
    int val;

    if(*str == '\0') return 1;
    // if(!*str) return 0;

    while(*str != '\0'){
        val = char_is_alpha((*str + 1));
        if(val == 0) return 0;
        str++;
    }

    return 1;
}

int main(){
    char str[] = "";
    int res = ft_str_is_alpha(str);
    printf("Result: %d\n", res);
}
