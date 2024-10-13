#include <unistd.h>

int main(int argc, char *argv[]){
    int curr_arg = 1;
    while(curr_arg < argc){
        char *p = argv[curr_arg];
        while(*p){
            char c = *p;
            write(1, &c, 1);
            p++;
        }
        write(1, "\n", 1);
        curr_arg++;
    }
}
