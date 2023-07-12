#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c){
    write(1, &c, 1);
}

int ft_reverse_num(int num){
    int reverse_num = 0, remainder;

    while(num != 0){
        remainder = num % 10;
        reverse_num = reverse_num * 10 + remainder;
        num = num/10;
    }

    return reverse_num;
}

void ft_putnbr(int nb){
    int reverse_num = ft_reverse_num(nb);

    if(reverse_num < 0){
        reverse_num = -reverse_num;
        ft_putchar('-');
    }

    while (reverse_num > 0) {
        int num = reverse_num % 10;
        int c_num = '0' + num;
        ft_putchar(c_num);
        reverse_num /= 10;
  }
}

int main(){
}
