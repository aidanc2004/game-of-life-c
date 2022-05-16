#include <stdio.h>
#include "board.h"

// completely fill the board with cell
void fill_board(int board[][COLS], int cell) {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            board[i][j] = cell;
}

// print out the board with an 'x' for an alive cell and ' ' for a dead one
void print_board(int board[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            putchar(board[i][j] ? 'x' : '.');
        }
        putchar('\n');
    }
}

// get the number of neighbors of a cell
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

// check if a cell is alive and is on the board
int is_alive(int board[][COLS], int i, int j) {
    return board[i][j] && in_bounds(i, j);
}

// check if a cell is in the bounds of the board
int in_bounds(int i, int j) {
    return i < ROWS && i >= 0 && j < COLS && j >= 0;
}

// check if cell should be alive or dead next generation
int update_cell(int board[][COLS], int i, int j) {
    int neighbors = check_neighbors(board, i, j);

    if (is_alive(board, i, j)) {
        return neighbors == 2 || neighbors == 3;
    } else {
        return neighbors == 3;
    }
}

// update all of the cells in current and put the updated cells in next
void update_board(int current[][COLS], int next[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            next[i][j] = update_cell(current, i, j);
        }
    }
}

// move all of the cells from one board to another
void move_board(int src[][COLS], int dst[][COLS]) {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            dst[i][j] = src[i][j];
}
