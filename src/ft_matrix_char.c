/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:03:02 by rjannet           #+#    #+#             */
/*   Updated: 2021/03/24 13:07:09 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_matrix	*alloc_matrix(int width, int height, t_mark *mark)
{
	void		*tmp;
	t_matrix	*result;

	tmp = (char*)malloc(sizeof(t_matrix) + sizeof(char) * width * height);
	if (tmp)
	{
		result = tmp;
		result->data = tmp + sizeof(t_matrix);
		result->width = width;
		result->height = height;
		result->mark = mark;
		return (result);
	}
	return (0);
}

void		dealloc_matrix(t_matrix *matrix)
{
	free(matrix->mark);
	free(matrix);
}

char		matrix_get(t_matrix *matrix, size_t col, size_t row)
{
	return (matrix->data[matrix->width * row + col]);
}

void		matrix_set(t_matrix *matrix, size_t col, size_t row, char smb)
{
	matrix->data[matrix->width * row + col] = smb;
}

void		ft_display_matrix(t_matrix *matrix)
{
	int		col;
	int		row;
	char	smb;

	row = 0;
	while (row < matrix->height)
	{
		col = 0;
		while (col < matrix->width)
		{
			smb = matrix_get(matrix, col, row);
			write(1, &smb, 1);
			col++;
		}
		ft_putstr("\n");
		row++;
	}
}
