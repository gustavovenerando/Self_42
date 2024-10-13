#include <stdio.h>

int char_is_alphanumeric(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c>=48 && c<=57)) return 1;
    return 0;
}

char char_to_uppercase(char c) {
    char new_c = c;
    if (c >= 'a' && c <= 'z') {
        new_c = c - 'a' + 'A';
    }

    return new_c;
}

char char_to_lowercase(char c) {
    char new_c = c;
    if (c >= 'A' && c <= 'Z') {
        new_c = c - 'A' + 'a';
    }

    return new_c;
}

char* ft_strcapitalize(char *str){
    char *str_temp = str;

    while(*str_temp != '\0'){
        char curr = *str_temp;
        char new_char = curr;
        char last = '\0';
        if(str_temp - 1) last = *(str_temp - 1);

        if(!char_is_alphanumeric(last)) new_char = char_to_uppercase(*str_temp);
        else{
            if(char_is_alphanumeric(curr)) new_char = char_to_lowercase(*str_temp);
        }

        *str_temp = new_char;

        str_temp++;
    }

    return str;
}

int main(){
    char str[] = "salut, comment tu vas ? 42mots quarante-deux; ciquante+et+un";
    char *res = ft_strcapitalize(str);
    printf("Result: %s\n", str);
}
