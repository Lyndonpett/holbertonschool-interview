#ifndef SANDPILES_H
#define SANDPILES_H


void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int checkStablility(int grid[3][3], int flags[3][3]);
void toppleCell(int grid[3][3], int row, int col);
static void print_grid(int grid[3][3]);


#endif
