/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_console.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:40:10 by rjannet           #+#    #+#             */
/*   Updated: 2021/03/24 13:32:03 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			get_instr(char **buffer, t_mark **mark)
{
	char	rule[BUF_SIZE];
	int		iter;
	char	*tmp;

	iter = 0;
	tmp = *buffer;
	while (tmp[iter] && tmp[iter] != '\n')
	{
		rule[iter] = tmp[iter];
		iter++;
	}
	*buffer = &tmp[iter + 1];
	*mark = ft_create_elem(rule[iter - 3], rule[iter - 2], rule[iter - 1]);
	rule[iter - 3] = '\0';
	return (ft_isnbr(rule));
}

int			check_valid(char *b, t_mark *mark, int height)
{
	int		length;
	int		iter;
	int		i;
	int		count;

	iter = 0;
	count = 0;
	i = 0;
	length = 0;
	while (b[i])
	{
		if (!(b[i] == mark->empty || b[i] == mark->obstacle || b[i] == '\n'))
			return (0);
		if (b[i] == '\n')
		{
			if (count++ == 0)
				length = iter;
			else if (iter != length)
				return (0);
			iter = -1;
		}
		iter++;
		i++;
	}
	return (count == height ? length : 0);
}

t_matrix	*get_matrix(char *buffer, int width, int height, t_mark *mark)
{
	t_matrix	*result;
	int			col;
	int			row;
	int			iter;

	row = 0;
	col = 0;
	iter = 0;
	result = alloc_matrix(width, height, mark);
	if (result)
	{
		while (buffer[iter])
		{
			if (buffer[iter] == '\n')
			{
				col = 0;
				row++;
			}
			else
				matrix_set(result, col++, row, buffer[iter]);
			iter++;
		}
	}
	return (result);
}

t_matrix	*ft_read_console(char *buffer)
{
	t_mark	*mark;
	int		height;
	int		width;

	height = get_instr(&buffer, &mark);
	width = check_valid(buffer, mark, height);
	if (height == 0 || width == 0)
	{
		ft_putstr(MAP_ERROR);
	}
	else
		return (get_matrix(buffer, width, height, mark));
	return (0);
}
