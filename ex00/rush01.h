/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumacias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 21:05:33 by jumacias          #+#    #+#             */
/*   Updated: 2025/07/20 21:05:39 by jumacias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

int		solve(int grid[4][4], int views[16], int pos);
int		is_safe(int grid[4][4], int row, int col, int num);
int		check_all_views(int grid[4][4], int views[16]);
int		count_visible_boxes(int line[4]);
int		parse_input(char *input_str, int views[16]);
void	init_grid(int grid[4][4]);
void	print_solution(int grid[4][4]);

#endif
