/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:57:31 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/16 11:49:32 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (list_size(a) <= 3)
	{
		sort_three(&a);
		ft_lstclear(&a);
	}
	else
		sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	if (!check_args(av, ac) || !check_overflow(av, ac))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	b = NULL;
	a = parse_args(av, ac);
	if (repeated(a))
	{
		write(2, "Error\n", 6);
		ft_lstclear(&a);
		return (1);
	}
	if (is_sorted(a) || list_size(a) <= 1)
	{
		ft_lstclear(&a);
		return (0);
	}
	push_swap(a, b);
}
