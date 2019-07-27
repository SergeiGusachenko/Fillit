/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:02:27 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/22 21:05:57 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcon(char **arr, char *c)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	str = ft_strnew(1);
	while (arr[i])
	{
		tmp = ft_strjoin(str, arr[i]);
		free(str);
		str = tmp;
		tmp = ft_strjoin(str, c);
		free(str);
		str = tmp;
		++i;
	}
	return (str);
}
