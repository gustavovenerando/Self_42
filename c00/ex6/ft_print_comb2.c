#include <unistd.h>

void ft_putchar(char c){
    write(1,&c,1);
}

void ft_commas(void){
    ft_putchar(',');
    ft_putchar(' ');
}

void ft_space(void){
    ft_putchar(' ');
}

void ft_second_number(int fn_fd, int fn_sd){
    int sn_first_digit = '0';

    while(sn_first_digit <= '9'){
        int sn_second_digit = '0';

        while(sn_second_digit <= '9'){
            if(sn_first_digit >= fn_fd && sn_second_digit > fn_sd){
                ft_putchar(fn_fd);
                ft_putchar(fn_sd);
                ft_space();
                ft_putchar(sn_first_digit);
                ft_putchar(sn_second_digit);
                ft_commas();
            }
            sn_second_digit++;
        }
        sn_first_digit++;
    }
}

void ft_print_comb2(void){
    int fn_first_digit = '0';
    
    while(fn_first_digit <= '9'){
        int fn_second_digit = '0';

        while(fn_second_digit <= '9'){
            ft_second_number(fn_first_digit,fn_second_digit);
            fn_second_digit++;
        }
        fn_first_digit++;
    }
}

int main(){
   ft_print_comb2();
}
