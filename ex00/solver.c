/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:43:48 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/20 20:43:53 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	check_col_views(int grid[4][4], int views[16])
{
	int	i;
	int	j;
	int	line[4];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			line[j] = grid[j][i];
		if (count_visible_boxes(line) != views[i])
			return (0);
		j = -1;
		while (++j < 4)
			line[j] = grid[3 - j][i];
		if (count_visible_boxes(line) != views[i + 4])
			return (0);
	}
	return (1);
}

static int	check_row_views(int grid[4][4], int views[16])
{
	int	i;
	int	j;
	int	line[4];

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			line[j] = grid[i][j];
		if (count_visible_boxes(line) != views[i + 8])
			return (0);
		j = -1;
		while (++j < 4)
			line[j] = grid[i][3 - j];
		if (count_visible_boxes(line) != views[i + 12])
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
		return (check_col_views(grid, views) && check_row_views(grid, views));
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
