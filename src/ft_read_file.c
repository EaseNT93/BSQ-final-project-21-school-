/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 22:23:19 by rjannet           #+#    #+#             */
/*   Updated: 2021/03/24 13:47:49 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>

int			ft_isnbr(char *str)
{
	char	*tmp;

	tmp = str;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (ft_atoi(tmp));
}

int			get_instrf(int fd, t_mark **mark)
{
	char	c;
	char	rule[BUF_SIZE];
	int		iter;

	iter = 0;
	while (read(fd, &c, 1) && c != '\n')
		rule[iter++] = c;
	*mark = ft_create_elem(rule[iter - 3], rule[iter - 2], rule[iter - 1]);
	rule[iter - 3] = '\0';
	return (ft_isnbr(rule));
}

int			check_validf(int fd, t_mark *mark, int height)
{
	char	smb;
	int		length;
	int		iter;
	int		count;

	iter = 0;
	count = 0;
	while (read(fd, &smb, 1))
	{
		if (!(smb == mark->empty || smb == mark->obstacle || smb == '\n'))
			return (0);
		if (smb == '\n')
		{
			if (count++ == 0)
				length = iter;
			else if (iter != length)
				return (0);
			iter = -1;
		}
		iter++;
	}
	return (count == height ? length : 0);
}

t_matrix	*get_matrixf(int fd, int width, int height, t_mark *mark)
{
	t_matrix	*result;
	char		smb;
	int			col;
	int			row;

	row = 0;
	col = 0;
	result = alloc_matrix(width, height, mark);
	if (result)
	{
		while (read(fd, &smb, 1))
		{
			if (smb == '\n')
			{
				col = 0;
				row++;
			}
			else
				matrix_set(result, col++, row, smb);
		}
		matrix_set(result, col, row, smb);
	}
	return (result);
}

t_matrix	*ft_read_file(char *file)
{
	t_mark	*mark;
	int		height;
	int		width;
	int		fd;

	fd = open(basename(file), O_RDONLY);
	if (fd == -1)
		ft_putstr(MAP_ERROR);
	{
		height = get_instrf(fd, &mark);
		width = check_validf(fd, mark, height);
		if (height == 0 || width == 0)
			ft_putstr(MAP_ERROR);
		else
		{
			close(fd);
			fd = open(basename(file), O_RDONLY);
			get_instrf(fd, &mark);
			return (get_matrixf(fd, width, height, mark));
		}
	}
	return (0);
}
