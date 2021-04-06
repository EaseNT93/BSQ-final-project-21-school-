/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 19:08:22 by rjannet           #+#    #+#             */
/*   Updated: 2021/03/25 12:02:05 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		ft_draw_square(t_matrix *matrix)
{
	t_matrix_int	*tmp;
	int				*elem;

	if (matrix)
	{
		tmp = ft_biggest_square(matrix);
		elem = ft_get_max(tmp);
		ft_fill_matrix(&matrix, elem[0], elem[1], elem[2]);
		ft_display_matrix(matrix);
		dealloc_matrix(matrix);
		dealloc_matrix_int(tmp);
	}
}

int			main(int argc, char **argv)
{
	t_matrix	*matrix;
	int			iter;
	char		*buffer;
	char		smb;

	iter = 1;
	if (argc == 1)
	{
		buffer = (char *)malloc(0);
		buffer[0] = '\0';
		while (read(0, &smb, 1))
			buffer = ft_strcat(buffer, smb);
		matrix = ft_read_console(buffer);
		ft_draw_square(matrix);
	}
	else
	{
		while (iter < argc)
		{
			ft_draw_square(ft_read_file(argv[iter]));
			iter++;
			if (iter < argc)
				write(1, "\n", 1);
		}
	}
}
