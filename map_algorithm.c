/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:45:01 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/21 18:45:02 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**insert(char **map, t_tetromino *list, int y_map, int x_map)
{
	int	x_piece;
	int	y_piece;

	y_piece = 0;
	while (list->piece[y_piece])
	{
		x_piece = 0;
		while (list->piece[y_piece][x_piece])
		{
			if (list->piece[y_piece][x_piece] != '.')
				map[y_map + y_piece][x_map + x_piece] = list->symbol;
			x_piece++;
		}
		y_piece++;
	}
	return (map);
}

char		**clean(char **map, t_tetromino *list, int y_map, int x_map)
{
	int	x_piece;
	int	y_piece;

	y_piece = 0;
	while (list->piece[y_piece])
	{
		x_piece = 0;
		while (list->piece[y_piece][x_piece])
		{
			if (list->piece[y_piece][x_piece] != '.')
				map[y_map + y_piece][x_map + x_piece] = '.';
			x_piece++;
		}
		y_piece++;
	}
	return (map);
}

int			is_available(char **map, char **piece, int y_map, int x_map)
{
	int	x_piece;
	int	y_piece;

	y_piece = 0;
	while (piece[y_piece])
	{
		if (map[y_map + y_piece] == 0)
			return (-1);
		x_piece = 0;
		while (piece[y_piece][x_piece])
		{
			if (map[y_map + y_piece][x_map + x_piece] == 0)
				return (-1);
			if (piece[y_piece][x_piece] != '.' &&
			map[y_map + y_piece][x_map + x_piece] != '.')
				return (-1);
			x_piece++;
		}
		y_piece++;
	}
	return (1);
}

int			map_algorithm(char **map, t_tetromino *list)
{
	int	x_map;
	int	y_map;

	y_map = 0;
	if (!list)
		return (1);
	while (map[y_map])
	{
		x_map = 0;
		while (map[y_map][x_map])
		{
			if (is_available(map, list->piece, y_map, x_map) == 1)
			{
				map = insert(map, list, y_map, x_map);
				if (map_algorithm(map, list->next) == 0)
					map = clean(map, list, y_map, x_map);
				else
					return (1);
			}
			x_map++;
		}
		y_map++;
	}
	return (0);
}
