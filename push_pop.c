/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:06:21 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/09 17:38:47 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_stack **s, int val)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	tmp->val = val;
	tmp->next = *s;
	*s = tmp;
}

int	pop(t_stack **s)
{
	t_stack	*top;
	int		val;

	if (!s)
		return (-1);
	top = *s;
	val = top->val;
	*s = top->next;
	free(top);
	top = NULL;
	return (val);
}
