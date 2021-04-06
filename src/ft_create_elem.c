/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpants <dpants@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:30:14 by rjannet           #+#    #+#             */
/*   Updated: 2021/03/24 13:06:25 by dpants           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_mark		*ft_create_elem(char empty, char obstacle, char full)
{
	t_mark	*result;

	result = malloc(sizeof(result));
	if (result)
	{
		result->empty = empty;
		result->obstacle = obstacle;
		result->full = full;
	}
	return (result);
}
