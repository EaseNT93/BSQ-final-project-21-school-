/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:16:18 by rjannet           #+#    #+#             */
/*   Updated: 2021/03/24 14:18:06 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define MAP_ERROR "map error\n"
# define BUF_SIZE 1024
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_mark
{
	char	empty;
	char	obstacle;
	char	full;
}				t_mark;

typedef struct	s_matrix
{
	int		width;
	int		height;
	t_mark	*mark;
	char	*data;

}				t_matrix;

typedef struct	s_matrix_int
{
	int		width;
	int		height;
	int		*data;
}				t_matrix_int;

void			ft_putstr(char *str);
int				ft_atoi(char *str);
char			*ft_strcat(char *dest, char smb);
int				ft_isnbr(char *str);
t_mark			*ft_create_elem(char empty, char obstacle, char full);
t_matrix		*ft_read_file(char *file);
t_matrix		*ft_read_console(char *buffer);

t_matrix		*alloc_matrix(int width, int height, t_mark *mark);
void			dealloc_matrix(t_matrix *matrix);
char			matrix_get(t_matrix *matrix, size_t col, size_t row);
void			matrix_set(t_matrix *matrix, size_t col, size_t row, char smb);
void			ft_display_matrix(t_matrix *matrix);

t_matrix_int	*alloc_matrix_int(int width, int height);
void			dealloc_matrix_int(t_matrix_int *matrix);
int				matrix_get_int(t_matrix_int *matrix, size_t col, size_t row);
void			matrix_set_int(t_matrix_int *tmp, size_t i, size_t j, int nbr);

t_matrix_int	*ft_biggest_square(t_matrix *tmp);
void			ft_fill_matrix(t_matrix **matrix, int col, int row, int max);
int				*ft_get_max(t_matrix_int *tmp);

#endif
