#include <stdio.h>

char ft_char_to_lowercase(char c){
    char new_c = c;
    if(c >= 'A' &&  c <= 'Z'){
        new_c =  c + 'a' - 'A';
    }

    return new_c;
}

char* ft_strlowcase(char *str){
    char *str_temp = str;

    while(*str_temp != '\0'){
        char new_char = ft_char_to_lowercase(*str_temp);
        *str_temp = new_char;
        str_temp++;
    }

    return str;
}

int main(){
    char str[] = "ASLDJF";
    char* res = ft_strlowcase(str);
    printf("Result: %s\n", str);
}

