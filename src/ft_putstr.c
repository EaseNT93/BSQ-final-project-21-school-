/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:46:34 by rjannet           #+#    #+#             */
/*   Updated: 2021/03/24 12:51:39 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_strlen(char *str)
{
	int		result;

	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
