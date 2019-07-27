/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_clean_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:25:17 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/29 20:27:52 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			clean_row(char **str, char **tmp)
{
	ft_strdel(str);
	*str = ft_strjoin(*tmp, "\n");
	ft_strdel(tmp);
}

t_tetromino		*input_clean_row(t_tetromino *list)
{
	int			i;
	char		*str;
	char		*tmp;
	t_tetromino	*new;

	new = NULL;
	while (list)
	{
		i = 0;
		str = ft_strnew(1);
		while (list->piece[i])
		{
			if (ft_strcmp(list->piece[i], "....") != 0)
			{
				tmp = ft_strjoin(str, list->piece[i]);
				clean_row(&str, &tmp);
			}
			i++;
		}
		new = map_add(new, str);
		ft_strdel(&str);
		list = list->next;
	}
	return (new);
}
