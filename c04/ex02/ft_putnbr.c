#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c){
    write(1,&c,1);
}

long long int reverse_num(int n){
    //Problema é que revertando o numero, ele fica mto maior que o max para 4bytes (2147483647) < 7463847412
    //Assim é preciso de 8 bytes para guardar este número, por isso num_rev precisa ser um long long int
    
    int remainder;
    long long int num_rev = 0;
    long long int new_n = n;
    if(new_n < 0) new_n = - new_n;

    while(new_n){
        remainder = new_n % 10;
        num_rev = num_rev * 10 + remainder;
        new_n /= 10;
    }

    return num_rev;
}

void ft_putnbr(int nb){
    char num_char;

    if(nb < 0){
        ft_putchar('-');
    }

    long long int num_rev = reverse_num(nb);

    while(num_rev){
        num_char = num_rev % 10 + '0';
        ft_putchar(num_char);
        num_rev /= 10;
    }
}


int main(){
    ft_putnbr(-2147483648);
    printf("\n");
}
