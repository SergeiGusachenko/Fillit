/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:44:54 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/29 20:19:18 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	t_tetromino		*list;
	t_tetromino		*tmp;
	int				size;
	char			**map;

	if (argc == 2)
	{
		if ((list = input_validate(argv[1])) == NULL)
			map_erorr();
		tmp = input_clean(list);
		size = map_size(tmp);
		map = map_create(size);
		while (map_algorithm(map, tmp) == 0)
		{
			ft_clean_arr(&map);
			map = map_create(size++);
		}
		map_display(map);
		ft_clean_arr(&map);
		ft_list_clean(&tmp);
	}
	else
		ft_putstr("usage: ./fillit [file]\n");
	return (0);
}
