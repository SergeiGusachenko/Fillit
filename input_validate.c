/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:44:51 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/22 21:33:04 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino		*input_validate(char *file)
{
	int			fd;
	t_tetromino	*list;

	list = NULL;
	fd = open(file, O_RDWR);
	if (fd == -1)
		return (NULL);
	if ((list = input_validate_map(fd, list)) == NULL)
		return (NULL);
	if (input_validate_tetrominoes(list) == -1)
		return (NULL);
	close(fd);
	return (list);
}

t_tetromino		*finish_and_clean(t_tetromino *list)
{
	ft_list_clean(&list);
	return (NULL);
}
