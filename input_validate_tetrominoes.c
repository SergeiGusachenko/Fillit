/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate_tetrominoes.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:44:48 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/21 18:47:05 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		cout_adjacent_blocks(t_tetromino *list, int x, int y, int count)
{
	if (list->piece[y][x] == '#')
	{
		if (x != 3 && list->piece[y][x + 1] == '#')
			count++;
		if (x != 0 && list->piece[y][x - 1] == '#')
			count++;
		if (y != 3 && list->piece[y + 1][x] == '#')
			count++;
		if (y != 0 && list->piece[y - 1][x] == '#')
			count++;
	}
	return (count);
}

int		is_valid_tetromino(t_tetromino *list)
{
	int	x;
	int	y;
	int number_of_blocks;

	y = 0;
	number_of_blocks = 0;
	while (list->piece[y])
	{
		x = 0;
		while (list->piece[y][x])
		{
			number_of_blocks =
			cout_adjacent_blocks(list, x, y, number_of_blocks);
			x++;
		}
		y++;
	}
	if (number_of_blocks != 6 && number_of_blocks != 8)
		return (-1);
	return (1);
}

int		input_validate_tetrominoes(t_tetromino *list)
{
	while (list)
	{
		if (is_valid_tetromino(list) == -1)
			return (-1);
		list = list->next;
	}
	return (1);
}
