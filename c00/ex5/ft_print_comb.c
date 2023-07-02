#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c){
    write(1,&c,1);
}

void ft_print_comb(void){
    int first_digit = '0';
    int first_loop = 0; 

    while(first_digit <= '7'){
        int second_digit = '1' + first_loop;
        int second_loop = 0; 

        while(second_digit <= '8'){
            int third_digit = '2' + second_loop + first_loop;

            while(third_digit <= '9'){
                ft_putchar(first_digit);
                ft_putchar(second_digit);
                ft_putchar(third_digit);
                if(first_digit == '7' && second_digit == '8' && third_digit == '9'){
                    return;
                } 
                ft_putchar(',');
                ft_putchar(' ');
                third_digit++;
            }

            second_digit++;
            second_loop++;
        }

        first_digit++;
        first_loop++;
    }
}

int main(){
   ft_print_comb();
}
