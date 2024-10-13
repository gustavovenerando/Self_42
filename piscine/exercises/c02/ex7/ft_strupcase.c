#include <stdio.h>

char ft_char_to_uppercase(char c){
    char new_c = c;
    if(c >= 'a' &&  c <= 'z'){
        new_c =  c - 'a' + 'A';
    }

    return new_c;
}

char* ft_strupcase(char *str){
    char *str_temp = str;

    while(*str_temp != '\0'){
        char new_char = ft_char_to_uppercase(*str_temp);
        *str_temp = new_char;
        printf("New_c: %c --- New_char_string: %c\n", new_char, *str_temp);
        str_temp++;
    }

    return str;
}

int main(){
    char str[] = "alsdfh";
    char* res = ft_strupcase(str);
    printf("Result: %s\n", str);
}
