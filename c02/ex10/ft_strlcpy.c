#include <stdio.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size){
    unsigned int i = 0;
    size -= 1;

    while(*(src + i) && (i < size)){
        *(dest + i) = *(src + i);
        i++;
    }

    *(dest + i) = '\0';
    
    return i;
}

int main(){
    char dest[] = "";
    char src[] = "salut";
    int res = ft_strlcpy(dest, src, 6);
    printf("Result: %d --- dest: %s\n", res, dest);
}
