/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 19:53:12 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/29 20:06:34 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_clean_arr(char ***argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(*argv)[i])
		return ;
	while ((*argv)[i])
		i++;
	while (j < i)
	{
		free((*argv)[j]);
		j++;
	}
	free(*argv);
}

void		ft_list_clean(t_tetromino **list)
{
	t_tetromino *node;

	if (*list == NULL || list == NULL)
		return ;
	node = *list;
	if (node->next)
		ft_list_clean(&node->next);
	ft_clean_arr(&node->piece);
	ft_memdel((void**)list);
}
