#include "sandpiles.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * sandpilesSumFun - sums two sandpiles and topples until sum is stable
 *
 * @grid1: first 3x3 grid
 * @grid2: second 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int col, row;
	int flags[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	/* sum the two grids */
	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			grid1[row][col] += grid2[row][col];
		}
	}

	while (checkStablility(grid1, flags))
	{
		/* print before toppling */
		printf("=\n");
		print_grid(grid1);

		/* every flag, topple cell */
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (flags[row][col] == 1)
				{
					toppleCell(grid1, row, col);
				}
			}
		}
	}
}

/**
 * checkStablility - checks if grid is stable
 *
 * @grid: 3x3 grid
 * @flags: 3x3 grid indicating unstable cells
 *
 * Return: 1 if grid is stable, 0 otherwise
 */
int checkStablility(int grid[3][3], int flags[3][3])
{
	int check = 0;
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (grid[row][col] > 3)
			{
				check = 1;
				flags[row][col] = 1;
			}
			else
			{
				flags[row][col] = 0;
			}
		}
	}
	return (check);
}

/**
 * toppleCell - topples a cell
 *
 * @grid: 3x3 grid that holds cell to topple
 * @row: row of cell to topple
 * @col: column of cell to topple
 *
 */
void toppleCell(int grid[3][3], int row, int col)
{
	grid[row][col] -= 4;

	if (row - 1 >= 0)
	{
		grid[row - 1][col] += 1;
	}
	if (row + 1 < 3)
	{
		grid[row + 1][col] += 1;
	}
	if (col - 1 >= 0)
	{
		grid[row][col - 1] += 1;
	}
	if (col + 1 < 3)
	{
		grid[row][col + 1] += 1;
	}
}

/**
 * print_grid - Print 3x3 grid
 *
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
