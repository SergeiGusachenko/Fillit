/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:44:43 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/22 21:32:04 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					is_valid_lines(int *count_lines,
					int *count_hashtags, char *line)
{
	if (*count_lines != 4)
	{
		if (ft_strlen(line) != 4)
			return (-1);
	}
	if (*count_lines == 4)
	{
		*count_lines = -1;
		*count_hashtags = 0;
		if (ft_strcmp(line, "") != 0)
			return (-1);
	}
	*count_lines = *count_lines + 1;
	return (0);
}

int					is_valid_hashtags(int *count_hashtags, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '#' && line[i] != '.' && line[i] != '\n')
			return (-1);
		if (line[i] == '#')
			++*count_hashtags;
		if (*count_hashtags > 4)
			return (-1);
		i++;
	}
	return (0);
}

char				*add_to_list(char *input, char **line, int count_lines,
	t_tetromino **list)
{
	char			*tmp;

	tmp = ft_strjoin(input, *line);
	input = tmp;
	if (ft_strcmp(*line, "") != 0)
	{
		tmp = ft_strjoin(input, "\n");
		free(input);
		input = tmp;
	}
	if (count_lines == 4)
	{
		*list = map_add(*list, input);
		ft_strdel(&input);
		input = ft_strnew(1);
	}
	ft_strdel(line);
	return (input);
}

void				init_input_map(t_tetromino **list, int *count_lines,
					int *count_hashtags, char **input)
{
	*list = NULL;
	*count_lines = 0;
	*count_hashtags = 0;
	*input = ft_strnew(1);
}

t_tetromino			*input_validate_map(const int fd, t_tetromino *list)
{
	char			*line;
	char			*input;
	int				count_lines;
	int				count_hashtags;
	char			*tmp;

	init_input_map(&list, &count_lines, &count_hashtags, &input);
	while (get_next_line(fd, &line) == 1)
	{
		if (is_valid_lines(&count_lines, &count_hashtags, line) == -1 ||\
						is_valid_hashtags(&count_hashtags, line) == -1)
		{
			free(line);
			free(input);
			ft_list_clean(&list);
			return (NULL);
		}
		tmp = add_to_list(input, &line, count_lines, &list);
		free(input);
		input = tmp;
	}
	free(input);
	if (count_lines != 4)
		return (finish_and_clean(list));
	return (list);
}
