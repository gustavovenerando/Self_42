#include <unistd.h>
#include <stdio.h>

// Only one byte
typedef unsigned char byteT;

void write_char(char c){
    write(1, &c, 1);
}

int char_is_printable(char c){
    if(c >= 32 && c <= 126) return 1;
    return 0;
}

int str_length(char *s){
    int i = 0;
    while(*s != '\0'){
        i++;
        s++;
    }

    return i;
}

void print_in_hex(byteT c){
    char hex[] = "0123456789abcdef";
    int remainder = c % 16;
    int division = c / 16;

    //First hex character
    write_char(hex[division]);

    //Second hex character
    write_char(hex[remainder]);
}

void print_address(void *s){
    byteT *pb = (byteT*)&s;

    //Addresses/pointers have 8 bytes
    for (int i = 7; i >= 0; i--) {
        print_in_hex(*(pb + i));
    }
    write_char(':');
    write_char(' ');
}

void print_hex_words(void *s, int n){
    char *new_s = (char*)s;
    for(int i = 0; i < n; i++){
        if(i%2 == 0 && i != 0) write_char(' ');
        print_in_hex(*(new_s + i));
    }
    write_char(' ');
}

void print_words(void *s, int n){
    char *new_s = (char*)s;
    for(int i = 0; i < n; i++){
        char curr_char = *(new_s + i);
        if(!char_is_printable(curr_char)) write_char('.');
        else write_char(curr_char);
    }
}

void* ft_print_memory(void *addr, unsigned int size){
    if(size == 0){
        write_char('\0');
        return addr;
    }

    int last_line = size/16;
    int n = 16;
    int j;

    for (int i = 0; i < size; i += 16) {
        if(last_line == j) n = size % 16;

        print_address(addr + i);
        print_hex_words(addr + i, n);
        print_words(addr + i, n);
        write_char('\n');

        j++;
    }

    return addr;
}

int main(){
    char str_test[] = "Coucou, \nbonjour a tous. Now only english, you know right.";

    ft_print_memory((void *)str_test, str_length(str_test));
    // printf("Address of first character is: %p", &str_test);

    // int int_test = 1025;
    // char *p = (char *)&int_test;
    //
    // printf("First byte to char: %d, Address: %p\n", *p, p);
    // p++;
    // printf("Second byte to char: %d, Address: %p\n", *p, p);
    // p++;
    // printf("Third byte to char: %d, Address: %p\n", *p, p);
    // p++;
    // printf("Fourth byte to char: %d, Address: %p\n", *p, p);

}
