/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:45:04 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/21 18:45:04 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**map_create(int size)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		map[i] = (char *)malloc(sizeof(char) * (size + 1));
		j = 0;
		while (j < size)
			map[i][j++] = '.';
		map[i++][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}
