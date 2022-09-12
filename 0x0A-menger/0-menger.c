#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge
 *
 * @level: level of the Menger Sponge to draw
 *
 */
void menger(int level)
{
	int i = 0, j = 0, x = 0, y = 0;
	int size = pow(3, level);
	char print;

	if (level < 0)
		return;

	if (level == 0)
	{
		printf("#\n");
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			print = '#';
			x = i;
			y = j;
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					print = ' ';
					break;
				}
				x /= 3;
				y /= 3;
			}
			printf("%c", print);
		}
		printf("\n");
	}
}
