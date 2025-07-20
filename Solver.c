/* incluyo la librería que he creado previamente */

#include "rush01.h"

int	count_visible_boxes(int line[4])
{
	int	i;
	int	max_height;
	int	visible_count;

	i = 0;
	max_height = 0;
	visible_count = 0;
	while (i < 4)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

int	check_all_views(int grid[4][4], int views[16])
{
	int	i;
	int	line[4];

	i = -1;
	while (++i < 4)
	{
		line[0] = grid[0][i];
		line[1] = grid[1][i];
		line[2] = grid[2][i];
		line[3] = grid[3][i];
		if (count_visible_boxes(line) != views[i])
			return (0);
		line[0] = grid[3][i];
		line[1] = grid[2][i];
		line[2] = grid[1][i];
		line[3] = grid[0][i];
		if (count_visible_boxes(line) != views[4 + i])
			return (0);
	}
	i = -1;
	while (++i < 4)
	{
		line[0] = grid[i][0];
		line[1] = grid[i][1];
		line[2] = grid[i][2];
		line[3] = grid[i][3];
		if (count_visible_boxes(line) != views[8 + i])
			return (0);
		line[0] = grid[i][3];
		line[1] = grid[i][2];
		line[2] = grid[i][1];
		line[3] = grid[i][0];
		if (count_visible_boxes(line) != views[12 + i])
			return (0);
	}
	return (1);
}

int	is_safe(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

int	solve(int grid[4][4], int views[16], int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
	{
		return (check_all_views(grid, views));
	}
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, views, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
