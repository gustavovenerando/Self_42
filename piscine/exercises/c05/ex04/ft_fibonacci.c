#include <stdio.h>

int ft_fibonacci(int index){
    int fib[] = {0,1,1,2};
    if(index >= 4){
        return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
    }
    else if (index >= 0){
        return fib[index];
    }
    else{
        return -1;
    }
}

int main(){
    int res = ft_fibonacci(8);
    printf("Result: %d\n", res);
}
