/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:07:00 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/09 17:38:25 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	list_max(t_stack *s)
{
	int	max;

	max = s->val;
	s = s->next;
	while (s)
	{
		if (s->val > max)
			max = s->val;
		s = s->next;
	}
	return (max);
}

int	list_min(t_stack *s)
{
	int	min;

	min = s->val;
	s = s->next;
	while (s)
	{
		if (s->val < min)
			min = s->val;
		s = s->next;
	}
	return (min);
}
