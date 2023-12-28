#include <stdio.h>

int is_number(char c){
    if(c >= '0' && c <= '9') return 1;
    return 0;
}

int ft_atoi(char *str){
    int count_minus = 0;
    int count_is_number = 0;
    int num = 0;
    int sign;

    while(*str){
        if(is_number(*str)){
            num = num*10 + *str - 48;
            count_is_number++;
        }
        else if(count_is_number > 0) break;

        if(*str == '-') count_minus++;

        str++;
    }
    if(count_minus % 2 == 0) sign = 1;
    else sign = -1;

    return num*sign;
}

int main(){
    char s[] = "  ---+12358a345";
    int res = ft_atoi(s);

    printf("Result: %d\n", res);
}
