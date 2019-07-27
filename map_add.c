/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:44:58 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/21 18:44:58 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino		*map_add(t_tetromino *list, char *str)
{
	char		**data;
	t_tetromino	*new;
	t_tetromino	*temp;

	data = ft_strsplit(str, '\n');
	if (list == NULL)
	{
		list = malloc(sizeof(t_tetromino));
		list->piece = data;
		list->next = NULL;
		list->symbol = 'A';
		return (list);
	}
	temp = list;
	new = malloc(sizeof(t_tetromino));
	new->piece = data;
	new->next = NULL;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->symbol = temp->symbol + 1;
	return (list);
}
