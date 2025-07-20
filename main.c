/* incluyo la librería que he creado previamente */

#include "rush01.h"

/* init grid para establecer el numero de filas y columnas que posee la matriz */

void	init_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			col++;
		}
		row++;
	}
}

/* creo una cadena y le digo que lo maximo son 16 (4x4) */

int	parse_input(char *input_str, int views[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input_str[i] && count < 16)
	{
		if (input_str[i] >= '1' && input_str[i] <= '4')
		{
			views[count] = input_str[i] - '0';
			count++;
		}
		else if (input_str[i] != ' ')
			return (0);
		i++;
		if (input_str[i] == ' ')
			i++;
	}
	if (count != 16 || input_str[i] != '\0')
		return (0);
	return (1);
}

/* imprimir la solución del cuadrado de 4x4*/

void	print_solution(int grid[4][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = grid[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		row++;
	}
}



int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	views[16];

	init_grid(grid);
	if (argc != 2 || !parse_input(argv[1], views))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (solve(grid, views, 0))
	{
		print_solution(grid);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
