#include <stdio.h>
#include <unistd.h>

void print_board(int *board){
    int i = 0;
    char c;

    while(i < 10){
        c = *(board + i) + '0';
        write(1, &c, 1);
        i++;
    }
    write(1, "\n", 1);
}

int pos_diff(int a, int b){
    if(a >= b)
        return a - b;
    else 
        return b - a;
}

int placement_validation(int n_queen, int *board){
    int i = 0;

    int curr_queen_col = board[n_queen];
    while(i < n_queen){
        int queen_to_compare_col = board[i];

        int row_diff = n_queen - i; 
        int col_diff = pos_diff(curr_queen_col, queen_to_compare_col);

        if(
            curr_queen_col == queen_to_compare_col ||
            row_diff == col_diff
        ){
            return 0;
        }

        i++;
    }

    return 1;
}

void start(int *board, int n_queen, int *count){
    board[n_queen] = 0;

    while(board[n_queen] < 10){
        if(placement_validation(n_queen, board)){
            if(n_queen == 9){
                print_board(board);
                *count += 1;
            }
            else
                start(board, n_queen + 1, count);
        }
        board[n_queen]++;
    }
}

int ft_ten_queens_puzzle(void){
    int board[10];
    int count = 0;
    int n_queen = 0;

    start(board, n_queen, &count);

    return count;
}

int main(){
    int x = ft_ten_queens_puzzle();
    printf("Result: %d\n", x);
    return 0;
}
