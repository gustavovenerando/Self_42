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

int convert_to_int(char *str, char *base){
    int s_length = str_length(str);
    int num_base = str_length(base);
    int final_num = 0;

    for (int i = 0; i < s_length; i++) {
        int exp_num = s_length - i - 1;
        char curr_char = *(str + i);
        int curr_num = index_of_char(base, curr_char);
        printf("%d - %d - %d\n", num_base, exp_num, curr_num);

        final_num += curr_num*do_exp(num_base, exp_num);
    }

    return final_num;
}

int main(){
    char base[] = "0123456789ABCDEF";
    char num[] = "4E";

    int res = convert_to_int(num, base);

    printf("RESULT: %d\n", res);

    return 0;
}
