/* declaro una biblioteca nueva */

#ifndef RUSH01_H
# define RUSH01_H

/* incluyo la libreria de unistd.h */

# include <unistd.h>

/* --- Funciones en solver.c --- */

int		solve(int grid[4][4], int views[16], int pos);
int		is_safe(int grid[4][4], int row, int col, int num);
int		check_all_views(int grid[4][4], int views[16]);
int		count_visible_boxes(int line[4]);

/* --- Funciones en main.c --- */

void	init_grid(int grid[4][4]);
int		parse_input(char *input_str, int views[16]);
void	print_solution(int grid[4][4]);

/* termino de declarar las funciones de la librería "rush01.h" */

#endif
