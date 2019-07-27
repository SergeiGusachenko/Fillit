/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgusache <sgusache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:34:00 by sgusache          #+#    #+#             */
/*   Updated: 2019/01/29 20:27:20 by sgusache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct			s_tetromino
{
	char				**piece;
	char				symbol;
	struct s_tetromino	*next;
}						t_tetromino;

t_tetromino				*finish_and_clean(t_tetromino *list);
t_tetromino				*input_clean(t_tetromino *list);
t_tetromino				*input_clean_row(t_tetromino *list);
t_tetromino				*input_clean_column_left(t_tetromino *list);
t_tetromino				*input_clean_column_right(t_tetromino *list);
t_tetromino				*input_validate(char *file);
t_tetromino				*input_validate_map(const int fd, t_tetromino *list);
int						input_validate_tetrominoes(t_tetromino *list);
void					map_erorr(void);
char					**map_create(int size);
void					map_display(char **map);
int						map_size(t_tetromino *root);
t_tetromino				*map_add(t_tetromino *list, char *str);
int						map_algorithm(char **map, t_tetromino *list);
void					ft_clean_arr(char ***argv);
void					ft_list_clean(t_tetromino **list);

#endif
