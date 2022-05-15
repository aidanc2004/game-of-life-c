// TODO: change functions to make it so i dont have to use constants, then i
//       can take the width and height from the program args.

#include <stdio.h>
#include "board.h"

void fill_board(int board[][COLS], int cell) {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            board[i][j] = cell;
}

void print_board(int board[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            putchar(board[i][j] ? 'x' : '.');
        }
        putchar('\n');
    }
}

int check_neighbors(int board[][COLS], int i, int j) {
    int n = 0;
    
    // this seems kinda hacky, is there a better way to do this?
    int neighbors[8][2] = {
        {i-1, j-1}, {i-1, j}, {i-1, j+1}, // * * *
        {i  , j-1},           {i  , j+1}, // * x *
        {i+1, j-1}, {i+1, j}, {i+1, j+1}  // * * *
    };
    
    for (int i = 0; i < 8; ++i)
        n += is_alive(board, neighbors[i][0], neighbors[i][1]);
    
    return n;
}

int is_alive(int board[][COLS], int i, int j) {
    return board[i][j] && in_bounds(i, j);
}

int in_bounds(int i, int j) {
    return i < ROWS && i >= 0 && j < COLS && j >= 0;
}

// change name of either update_cell or update_board, one returns void and one returns int
int update_cell(int board[][COLS], int i, int j) {
    int neighbors = check_neighbors(board, i, j);

    if (is_alive(board, i, j)) {
        return neighbors == 2 || neighbors == 3;
    } else {
        return neighbors == 3;
    }
}

void update_board(int current[][COLS], int next[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            next[i][j] = update_cell(current, i, j);
        }
    }
}

void move_board(int src[][COLS], int dst[][COLS]) {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            dst[i][j] = src[i][j];
}
