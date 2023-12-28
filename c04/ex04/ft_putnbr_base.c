#include <stdio.h>
#include <unistd.h>

void print_char(char c){
    write(1, &c, 1);  
}

int str_length(char *s){
    int count = 0;
    while(*s){
        count++;
        s++;
    }

    return count;
}

int count_digits(int num, int base){
    int count = 0;
    while(num){
        num = num/base;
        count++;
    }

    return count;
}

void ft_putnbr_base(int nbr, char *base){
    char str[30] = "";
    int i = 0;

    int base_int = str_length(base);
    // printf("Base escolhida: %d\n", base_int);

    int num_digits = count_digits(nbr, base_int);
    // printf("Digitos na base escolhida: %d\n", num_digits);
    
    if(nbr < 0){
        print_char('-');
        nbr = -nbr;
    }

    if(nbr < base_int && base_int == 16){
        int remainder = nbr % base_int;
        print_char(base[0]);
        print_char(base[remainder]);
        return;
    }

    while(num_digits > 1){
        int remainder = nbr % base_int;
        *(str + i) = base[remainder];
        nbr = nbr/base_int;
        num_digits--;
        i++;
    }
    *(str + i) = base[nbr];
    
    for(int j = i; j >= 0; j--){
        print_char(str[j]);
    }
}

int main(){
    char dec[] = "0123456789";
    char hex[] = "0123456789ABCDEF";
    char bin[] = "01";
    char oct[] = "01234567";

    // printf("Decimal number: ");
    // ft_putnbr_base(-1234, dec);
    // printf("\n");
    //
    // printf("Hexidecimal number: ");
    ft_putnbr_base(3, hex);
    printf("\n");
    // printf("Binary number: ");
    // ft_putnbr_base(1234, bin);
    //
    // printf("Octal number: ");
    // ft_putnbr_base(1234, oct);
}
