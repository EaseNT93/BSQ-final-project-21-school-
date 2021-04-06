/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 23:30:44 by rjannet           #+#    #+#             */
/*   Updated: 2021/04/04 12:03:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_matrix_int	*alloc_matrix_int(int width, int height)
{
	void			*tmp;
	t_matrix_int	*result;

	tmp = (int*)malloc(sizeof(t_matrix_int) + sizeof(int) * width * height);
	if (tmp)
	{
		result = tmp;
		result->data = tmp + sizeof(t_matrix_int);
		result->width = width;
		result->height = height;
		return (result);
	}
	return (0);
}

void			dealloc_matrix_int(t_matrix_int *matrix)
{
	free(matrix);
}

int				matrix_get_int(t_matrix_int *matrix, size_t col, size_t row)
{
	return (matrix->data[matrix->width * row + col]);
}

void			matrix_set_int(t_matrix_int *tmp, size_t i, size_t j, int nbr)
{
	tmp->data[tmp->width * j + i] = nbr;
}

void			ft_display_matrix_int(t_matrix_int *matrix)
{
	int		col;
	int		row;

	row = 0;
	while (row < matrix->height)
	{
		col = 0;
		while (col < matrix->width)
		{
			matrix_get_int(matrix, col, row);
			col++;
		}
		row++;
	}
}
