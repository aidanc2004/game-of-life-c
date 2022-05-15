#include <stdio.h>
#include "board.h"

int main() {
    int current[ROWS][COLS];
    int next[ROWS][COLS];

    fill_board(current, 0);
    fill_board(next, 0);

    // create glider
    current[5][5] = 1;
    current[4][4] = 1;
    current[5][6] = 1;
    current[4][6] = 1;
    current[3][6] = 1;
    
    while (1) {
        print_board(current);

        update_board(current, next);

        move_board(next, current);

        getchar();
    }
    
    return 0;
}
