/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:19:45 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/22 21:00:09 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_new_line(char **str_fd, char **line, int fd, int bytes)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str_fd[fd][len] != '\n' && str_fd[fd][len] != '\0')
		len++;
	if (str_fd[fd][len] == '\n')
	{
		*line = ft_strsub(str_fd[fd], 0, len);
		tmp = ft_strdup(str_fd[fd] + len + 1);
		free(str_fd[fd]);
		str_fd[fd] = tmp;
		if (str_fd[fd][0] == '\0')
			ft_strdel(&str_fd[fd]);
	}
	else if (str_fd[fd][len] == '\0')
	{
		if (bytes == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str_fd[fd]);
		ft_strdel(&str_fd[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str_fd[256];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			bytes;

	if (fd < 0 || fd > MAX_FD || line == NULL || BUFF_SIZE < 1)
		return (-1);
	while ((bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (str_fd[fd] == NULL)
			str_fd[fd] = ft_strnew(1);
		tmp = ft_strjoin(str_fd[fd], buf);
		free(str_fd[fd]);
		str_fd[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && (str_fd[fd] == NULL || str_fd[fd][0] == '\0'))
		return (0);
	return (ft_new_line(str_fd, line, fd, bytes));
}
