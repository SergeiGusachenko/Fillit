/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:44:39 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/29 20:28:49 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino		*input_clean(t_tetromino *list)
{
	int				count;
	t_tetromino		*new;

	count = 0;
	new = input_clean_row(list);
	ft_list_clean(&list);
	while (count != 3)
	{
		list = input_clean_column_right(new);
		ft_list_clean(&new);
		new = input_clean_column_left(list);
		ft_list_clean(&list);
		count++;
	}
	return (new);
}
