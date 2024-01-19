/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rest_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:08:59 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/09 17:38:55 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	norm_helper(t_stack **s)
{
	t_stack	*a;

	a = *s;
	if (a->val > a->next->val && a->next->val < a->next->next->val)
	{
		if (a->val < a->next->next->val)
			apply_op(s, "sa");
		else
			apply_op(s, "ra");
	}
	else if (a->val > a->next->val && a->next->val > a->next->next->val)
	{
		apply_op(s, "sa");
		apply_op(s, "rra");
	}
}

void	sort_three(t_stack **s)
{
	t_stack	*a;

	a = *s;
	if (list_size(a) == 2 && a->val > a->next->val)
	{
		apply_op(s, "sa");
		return ;
	}
	if (a->val < a->next->val && a->next->val > a->next->next->val)
	{
		if (a->val < a->next->next->val)
		{
			apply_op(s, "rra");
			apply_op(s, "sa");
		}
		else
			apply_op(s, "rra");
	}
	else
		norm_helper(s);
}

void	sort_rest(t_stack **s, int size)
{
	t_stack	*a;
	int		ind;

	a = *s;
	ind = -1 ;
	while (a->next)
	{
		ind++;
		if (a->val > a->next->val)
			break ;
		a = a->next;
	}
	if (ind >= 0 && ind < size / 2)
	{
		while (ind-- >= 0)
			apply_op(s, "ra");
	}
	else if (ind >= 0 && ind >= size / 2)
	{
		while (ind++ < size - 1)
			apply_op(s, "rra");
	}
}

void	to_a(t_stack **a, t_stack **b)
{
	sort_three(a);
	send_to_a(a, b);
	if (!is_sorted(*a))
		sort_rest(a, list_size(*a));
	ft_lstclear(a);
}
