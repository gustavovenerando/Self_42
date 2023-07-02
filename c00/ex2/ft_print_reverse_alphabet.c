#include <unistd.h>

void ft_print_reverse_alphabet(){
    for(int i = 122; i >= 97; i--){
        write(1,&i,1);
    }
}

int main(){
   ft_print_reverse_alphabet();
}
