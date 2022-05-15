#ifndef BOARD_H
#define BOARD_H

#define ROWS 10
#define COLS 20

void fill_board(int board[][COLS], int cell);
void print_board(int board[][COLS]);
int check_neighbors(int board[][COLS], int i, int j);
int is_alive(int board[][COLS], int i, int j);
int in_bounds(int i, int j);
int update_cell(int board[][COLS], int i, int j);
void update_board(int current[][COLS], int next[][COLS]);
void move_board(int src[][COLS], int dst[][COLS]);

#endif
