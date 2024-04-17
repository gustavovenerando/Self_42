#include <unistd.h>

int main(int argc, char *argv[]){
    char *p = argv[0];

    while(*p){
        char c = *p;
        write(1, &c, 1);
        p++;
    }

    return 0;
}

