#include <math.h>
#include <stdio.h>

int str_length(char *str){
    int cont = 0;

    while(*str){
        cont++;
        str++;
    }

    return cont;
}

int index_of_char(char *base, char c){
    int cont = 0;
    while(*base){
        if(*base == c) break;
        else cont ++;
        base++;
    }

    return cont;
}

int do_exp(int num, int exp_num){
    if(exp_num == 0) return 1;

    int final_num = 1;

    for(int i = 1; i <= exp_num; i++){
        final_num = final_num*num;
    }

    return final_num;
}

int convert_to_int(char *str, char *base, int num_sign){
    int s_length = str_length(str);
    int num_base = str_length(base);
    int final_num = 0;

    for (int i = 0; i < s_length; i++) {
        int exp_num = s_length - i - 1;
        char curr_char = *(str + i);
        int curr_num = index_of_char(base, curr_char);

        final_num += curr_num*do_exp(num_base, exp_num);
    }

    return final_num*num_sign;
}

int check_duplicates(char *base, int base_size){
    for (int i = 0; i < base_size - 1; i++) {
        for (int j = i + 1; j < base_size; j++) {
            if(base[i] == base[j]) return 1;
        }
    }

    return 0;
}

int check_chars(char *base){
    while(*base){
        if(*base == '-' || *base == '+' || *base == ' ') return 1;
        base++;
    }
    return 0;
}

int str_base_validation(char *str, char *base, int base_size, int str_size){
    for (int i = 0; i < str_size; i++) {
        int has_char = 0;
        for (int j = 0; j < base_size; j++) {
            if(str[i] == base[j]){
                has_char = 1;
                break;
            }
        }

        if(!has_char) return 0;
    }

    return 1;
}

int validation(char *str, char *base, int base_size, int str_size){
    int has_duplicates = check_duplicates(base, base_size);
    int has_invalid_chars = check_chars(base);
    int is_valid_str_base = str_base_validation(str, base, base_size, str_size);

    if(base_size <= 1 || has_duplicates || has_invalid_chars || !is_valid_str_base) return 0;

    return 1;
}

int is_char_in_base(char *base, char c){
    while(*base){
        if(*base == c) return 1;
        base++;
    }

    return 0;

}

void char_atoi(char *str, char *dst, char *base, int *num_sign){
    int num_has_started = 0;
    int cont_minus = 0;
    while(*str){
        int char_in_base = is_char_in_base(base, *str);
        if(*str == '-') cont_minus++;
        if(*str != ' ' && *str != '-' && *str != '+' && char_in_base){
            num_has_started = 1;
            *dst = *str;
            dst++;
        }

        if(num_has_started && !char_in_base){
            break;
        }

        str++;
    }

    *dst = '\0';
    
    if(cont_minus%2 == 0) *num_sign = 1;
    else *num_sign = -1;
}

int ft_atoi_base(char *str, char *base){
    int base_size = str_length(base);
    int str_size = str_length(str);

    //New str following atoi logic
    char new_str[str_size];
    int num_sign;
    char_atoi(str, new_str, base, &num_sign);
    int new_str_size = str_length(new_str);
    printf("New STR: %s\n", new_str);

    //Validation
    int is_valid = validation(new_str, base, base_size, new_str_size);
    printf("Validation result: %d\n", is_valid);
    if(!is_valid) return 0;

    return convert_to_int(new_str, base, num_sign);
}

int main(){
    char base[] = "0123456789ABCDEF";
    char num[] = " --+  4EH";

    int res = ft_atoi_base(num, base);

    printf("RESULT: %d\n", res);

    return 0;
}
