/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:11:13 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/09 17:39:10 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		sb;
	int		sa;

	tmp = *b;
	sb = list_size(*b);
	sa = list_size(*a);
	while (tmp)
	{
		tmp->cb = tmp->ind;
		if (tmp->ind > sb / 2)
			tmp->cb = tmp->ind - sb;
		tmp->ca = tmp->tg;
		if (tmp->tg > sa / 2)
			tmp->ca = tmp->tg - sa;
		tmp = tmp->next;
	}
}

void	reset_inds(t_stack **s)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *s;
	while (tmp)
	{
		tmp->ind = i++;
		tmp = tmp->next;
	}
}
