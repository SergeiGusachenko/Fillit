/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_clean_column.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:04:49 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/29 20:29:09 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			clean_column(char **tmp, char **temp, char **temp2, int *x)
{
	*tmp = ft_strjoin(*temp, *temp2);
	free(*temp2);
	ft_strdel(temp);
	*temp = ft_strjoin(*tmp, "\n");
	ft_strdel(tmp);
	(*x)++;
}

void			remove_dotted_column_left(t_tetromino **new,
	t_tetromino **list, int dot_count, int y)
{
	char	*temp;
	char	*temp2;
	char	*tmp;
	int		x;

	temp = ft_strnew(1);
	if (dot_count == y)
	{
		x = 0;
		while (x < y)
		{
			temp2 = ft_strsub((*list)->piece[x], 1,
				(ft_strlen((*list)->piece[x]) - 1));
			clean_column(&tmp, &temp, &temp2, &x);
		}
		*new = map_add(*new, temp);
		ft_strdel(&temp);
	}
	else
	{
		ft_strdel(&temp);
		temp = ft_strcon((*list)->piece, "\n");
		*new = map_add(*new, temp);
		ft_strdel(&temp);
	}
}

void			remove_dotted_column_right(t_tetromino **new,
	t_tetromino **list, int dot_count, int y)
{
	char	*temp;
	char	*tmp;
	char	*temp2;
	int		x;

	temp = ft_strnew(1);
	if (dot_count == y)
	{
		x = 0;
		while (x < y)
		{
			temp2 = ft_strsub((*list)->piece[x], 0,
				(ft_strlen((*list)->piece[x]) - 1));
			clean_column(&tmp, &temp, &temp2, &x);
		}
		*new = map_add(*new, temp);
		ft_strdel(&temp);
	}
	else
	{
		ft_strdel(&temp);
		temp = ft_strcon((*list)->piece, "\n");
		*new = map_add(*new, temp);
		ft_strdel(&temp);
	}
}

t_tetromino		*input_clean_column_left(t_tetromino *list)
{
	int			x;
	int			y;
	int			dot_count;
	t_tetromino	*new;

	new = NULL;
	while (list)
	{
		y = 0;
		x = ft_strlen(list->piece[y]);
		dot_count = 0;
		while (list->piece[y])
		{
			if (list->piece[y][0] == '.')
				dot_count++;
			y++;
		}
		remove_dotted_column_left(&new, &list, dot_count, y);
		list = list->next;
	}
	return (new);
}

t_tetromino		*input_clean_column_right(t_tetromino *list)
{
	int			x;
	int			y;
	int			dot_count;
	t_tetromino	*new;

	new = NULL;
	while (list)
	{
		y = 0;
		x = ft_strlen(list->piece[y]);
		dot_count = 0;
		while (list->piece[y])
		{
			if (list->piece[y][x - 1] == '.')
				dot_count++;
			y++;
		}
		remove_dotted_column_right(&new, &list, dot_count, y);
		list = list->next;
	}
	return (new);
}
