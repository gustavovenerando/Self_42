#include <unistd.h>

void ft_print_alphabet(){
    for(int i = 97; i <= 122; i++){
        write(1,&i,1);
    }
}

int main(){
   ft_print_alphabet();
}
