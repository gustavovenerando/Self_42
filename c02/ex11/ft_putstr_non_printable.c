#include <unistd.h>

int char_is_printable(char c){
    if(c >= 32 && c <= 126) return 1;
    return 0;
}

void char_dec_to_hex(char c, char *dest){
    int hex_remainder = c % 16;
    int hex_factor = c / 16;

    if(hex_remainder <= 9){
        dest[1] = '0' + hex_remainder;
    }
    else{
        dest[1] = 'a' + (hex_remainder - 10);
    }

    dest[0] = '0' + hex_factor;
}

void ft_putstr_non_printable(char *str){
    while(*str){
        char hex_string[] = "00";
        char *hex_p = hex_string;
        char back_slash = '\\'; 

        if(char_is_printable(*str)){
            write(1, str, 1);
            str++;
            continue;
        }

        char_dec_to_hex(*str, hex_string);
        write(1, &back_slash, 1);

        while (*hex_p) {
            write(1, hex_p, 1);
            hex_p++;
        }

        str++;
    }

}

int main(){
    char str_test[] = "Coucou\ntu vas bien ?";
    ft_putstr_non_printable(str_test);
}
