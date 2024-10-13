#include <unistd.h>

int main(int argc, char *argv[]){
    int last_arg = argc - 1;
    while(last_arg > 0){
        char *p = argv[last_arg];
        while(*p){
            char c = *p;
            write(1, &c, 1);
            p++;
        }

        write(1, "\n", 1);
        last_arg--;
    }
}
