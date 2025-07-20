#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

// --- Functions in solver.c ---

int	solve(int grid[4][4], int views[16], int pos);
int	is_safe(int grid[4][4], int row, int col, int num);
int	check_all_views(int grid[4][4], int views[16]);
int	count_visible_boxes(int line[4]);

// --- Functions in main.c ---

void	init_grid(int grid[4][4]);
int	parse_input(char *input_str, int views[16]);
void	print_solution(int grid[4][4]);

#endif
