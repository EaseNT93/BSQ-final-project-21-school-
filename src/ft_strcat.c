/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:32:48 by dpants            #+#    #+#             */
/*   Updated: 2021/03/24 13:48:52 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_strlan(char *str)
{
	int		result;

	result = 0;
	while (*str)
	{
		str++;
		result++;
	}
	return (result);
}

char	*ft_strcat(char *dest, char smb)
{
	char	*result;
	int		iter;

	result = (char *)malloc(ft_strlan(dest) + 2);
	iter = 0;
	while (dest[iter] != '\0')
	{
		result[iter] = dest[iter];
		iter++;
	}
	result[iter] = smb;
	result[iter + 1] = '\0';
	free(dest);
	return (result);
}
