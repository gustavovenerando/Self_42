#include <stdio.h>
#include <unistd.h>

void print_char(char c){
    write(1, &c, 1);
}

int base_int(char *base){
    int cont = 0;
    while(*base){
        base++;
        cont++;
    }

    return cont;
}

int has_duplication(char *base, int base_size){
    for(int i = 0; i < base_size - 1; i++){
        for(int j = i + 1; j < base_size; j++){
            if(base[i] == base[j]) return 1;
        }
    }

    return 0;
}

int base_validation(char *base){
    int base_size = base_int(base);
    int has_dup_values = has_duplication(base, base_size);
    if(base_size <= 1 || has_dup_values) return 0;
    while(*base){
        if(*base == '+' || *base == '-') return 0;
        base++;
    }

    return 1;
}

void ft_putnbr_base(int nbr, char *base){
    int remainder = 0;
    int base_num = base_int(base);

    if(!base_validation(base)) return;

    if(nbr < 0){
        print_char('-');
        nbr = -nbr;
    }

    if(nbr > base_num){
        ft_putnbr_base(nbr/base_num, base);
    }

    remainder = nbr % base_num;
    print_char(base[remainder]);
}

int main(){
    char base[] = "0123456789ABCDEF";

    ft_putnbr_base(-42, base);
    printf("\n");
}
