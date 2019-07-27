/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:45:11 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/21 18:49:48 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		minimal_square(int n)
{
	int		size;

	n = n * 4;
	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int		map_size(t_tetromino *list)
{
	int			i;
	t_tetromino	*temp;

	i = 0;
	temp = list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (minimal_square(i));
}
