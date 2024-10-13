#include <stdio.h>

int str_length(char *str){
    int cont = 0;

    while(*str){
        cont++;
        str++;
    }

    return cont;
}

int convert_to_int(char *str, char *base, int num_sign){
    int s_length = str_length(str);
    int num_base = str_length(base);
    int final_num = 0;

    for (int i = 0; i < s_length; i++) {
        int exp_num = s_length - i - 1;
        char curr_char = *(str + i);
        int curr_num = 0;
        while(*base){
            if(*base == curr_char)
                break;
            else
                curr_num ++;
            base++;
        }
        int base_multplier = 1;
        for(int i = 1; i <= exp_num; i++){
            base_multplier = base_multplier*num_base;
        }

        final_num += curr_num*base_multplier;
    }

    return final_num*num_sign;
}

int validation(char *base, int base_size){
    int has_duplicates = 0;
    int has_invalid_chars;

    for (int i = 0; i < base_size - 1; i++) {
        for (int j = i + 1; j < base_size; j++) {
            if(base[i] == base[j])
                has_duplicates = 1;
        }
    }
    
    while(*base){
        if(*base == '-' || *base == '+' || *base == ' ')
            has_invalid_chars = 1;
        base++;
    }
    has_invalid_chars = 0;

    if(base_size <= 1 || has_duplicates || has_invalid_chars)
        return 0;

    return 1;
}

int char_atoi(char *str, char *dst, char *base){
    int num_has_started = 0;
    int cont_minus = 0;
    while(*str){
        int i = 0;
        int char_in_base = 0;
        while(*(base + i)){
            if(*(base + i) == *str){
                char_in_base = 1;
                break;
            }
            i++;
        }
        if(*str == '-')
            cont_minus++;
        if(*str != ' ' && *str != '-' && *str != '+' && char_in_base){
            num_has_started = 1;
            *dst = *str;
            dst++;
        }
        if(num_has_started && !char_in_base)
            break;
        str++;
    }
    *dst = '\0';
    return cont_minus;
}

int ft_atoi_base(char *str, char *base){
    int base_size = str_length(base);
    int str_size = str_length(str);

    //New str following atoi logic
    char new_str[str_size];
    int cont_minus = char_atoi(str, new_str, base);
    int num_sign;
    if (cont_minus % 2 == 0)
      num_sign = 1;
    else
      num_sign = -1;
    printf("New STR: %s\n", new_str);

    int is_valid = validation(base, base_size);
    printf("Validation result: %d\n", is_valid);
    if(!is_valid) return 0;

    return convert_to_int(new_str, base, num_sign);
}

int main(){
    char base[] = "0123456789ABCDEF";
    char num[] = " --+4EH";

    int res = ft_atoi_base(num, base);

    printf("RESULT: %d\n", res);

    return 0;
}
