/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_square.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:19:16 by rjannet           #+#    #+#             */
/*   Updated: 2021/03/24 14:15:04 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int				ft_get_min(int l, int u, int lu)
{
	if (l <= u && l <= lu)
		return (l);
	else if (u <= l && u <= lu)
		return (u);
	else
		return (lu);
}

int				*ft_get_max(t_matrix_int *tmp)
{
	static int	res[3];
	int			max;
	int			i;
	int			j;

	j = 0;
	max = -1;
	while (j < tmp->height)
	{
		i = 0;
		while (i < tmp->width)
		{
			if (matrix_get_int(tmp, i, j) > max)
			{
				max = matrix_get_int(tmp, i, j);
				res[0] = i;
				res[1] = j;
				res[2] = max;
			}
			i++;
		}
		j++;
	}
	return (res);
}

t_matrix_int	*ft_init_matrix(t_matrix *tmp)
{
	t_matrix_int	*result;
	int				col;
	int				row;

	result = alloc_matrix_int(tmp->width, tmp->height);
	if (result)
	{
		row = 0;
		while (row < result->height)
		{
			col = 0;
			while (col < result->width)
			{
				if (matrix_get(tmp, col, row) == tmp->mark->empty)
					matrix_set_int(result, col, row, 1);
				else
					matrix_set_int(result, col, row, 0);
				col++;
			}
			row++;
		}
		return (result);
	}
	return (0);
}

t_matrix_int	*ft_biggest_square(t_matrix *tmp)
{
	t_matrix_int	*res;
	int				i;
	int				j;
	int				min;

	res = ft_init_matrix(tmp);
	if (res)
	{
		j = 1;
		while (j < res->height)
		{
			i = 1;
			while (i < res->width)
			{
				min = ft_get_min(matrix_get_int(res, i - 1, j),
				matrix_get_int(res, i, j - 1),
				matrix_get_int(res, i - 1, j - 1)) + 1;
				min = matrix_get(tmp, i, j) == tmp->mark->obstacle ? 0 : min;
				matrix_set_int(res, i, j, min);
				i++;
			}
			j++;
		}
	}
	return (res);
}

void			ft_fill_matrix(t_matrix **matrix, int col, int row, int max)
{
	t_matrix	*tmp;
	int			i;
	int			j;

	tmp = *matrix;
	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			matrix_set(tmp, col - j, row - i, tmp->mark->full);
			j++;
		}
		i++;
	}
}
