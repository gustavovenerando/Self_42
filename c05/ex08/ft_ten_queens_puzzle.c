#include <stdio.h>
#include <unistd.h>

int ft_ten_queens_puzzle(void){
    return 0;
}

int placement_validation(char board[10][10], int x, int y){
    //Horizontal and Vertical validation
    for(int pos = 0; pos < 10; pos++) {
        if (board[x][pos] == 'Q' || board[pos][y] == 'Q')
            return 0;
    }

    int upper_diagonals = 1;
    int lower_diagonals = 1;
    for(int pos = 0; pos < 10; pos++) {
        int upper_x = x + pos;
        int lower_x = x - pos;

        //Upper Diagonals
        int upper_y = y + pos;
        if(upper_y <= 9 && upper_x <= 9){
            if (board[upper_x][upper_y] == 'Q')
                upper_diagonals = 0;
        }

        if(upper_y <= 9 && lower_x >= 0){
            if (board[lower_x][upper_y] == 'Q')
                upper_diagonals = 0;
        }

        //Lower Diagonals
        int lower_y = y - pos;
        if(lower_y >= 0 && lower_x >= 0){
            if (board[lower_x][lower_y] == 'Q')
                lower_diagonals = 0;
        }

        if(lower_y >= 0  && upper_x <= 9){
            if (board[upper_x][lower_y] == 'Q')
                lower_diagonals = 0;
        }
    }

    return upper_diagonals*lower_diagonals;
}

int main(){
    char chess_board[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(i == 7 && j == 2) chess_board[i][j] = 'Q';
            else chess_board[i][j] = '.';
            printf("%c ", chess_board[i][j]);
        }
        printf("\n");
    }

    int can_place = placement_validation(chess_board, 1 , 3);
    printf("Can place value: %d\n", can_place);

    return 0;
}
