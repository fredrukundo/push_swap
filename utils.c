/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:17:06 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/09 17:39:07 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	list_size(t_stack *s)
{
	int	len;

	len = 0;
	while (s)
	{
		s = s->next;
		len++;
	}
	return (len);
}

int	list_average(t_stack *a)
{
	int	total;
	int	count;

	total = 0;
	count = 0;
	while (a)
	{
		total += a->val;
		count++;
		a = a->next;
	}
	if (!count)
		return (0);
	return (total / count);
}
