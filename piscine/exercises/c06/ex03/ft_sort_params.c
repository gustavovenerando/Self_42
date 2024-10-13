#include <stdio.h>
#include <unistd.h>

void print_str(char *str){
    while(*str){
        char c = *str;
        write(1, &c, 1);
        str++;
    }

    write(1, "\n", 1);
}

void sort_arr(int argc, char **argv){
    int i = 0;
    char *tmp;
    int j;

    while(i < argc - 1){
        j = 0;
        while(argv[i][j] == argv[i + 1][j]) 
            j++;

        if(argv[i][j] > argv[i + 1][j]){
            tmp = argv[i];
            argv[i] = argv[i + 1];
            argv[i + 1] = tmp;
            i = 0;
        }
        
       i++; 
    }
}

int main(int argc, char **argv){
    sort_arr(argc, argv);

    int i = 1;
    while(i < argc){
        print_str(argv[i]);
        i++;
    }
}
