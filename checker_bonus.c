/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:26:12 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/16 11:50:58 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stddef.h>

int	is_nbs(char **nbs)
{
	int	i;

	i = 1;
	while (nbs[i])
	{
		if (!is_nb(nbs[i]))
			return (0);
		i++;
	}
	return (1);
}

void	execute(t_stack **a, t_stack **b, char *op)
{
	if (list_size(*a) < 1 && list_size(*b) < 1)
		return ;
	if (op[0] == 's')
		sx(a, b, op);
	if (op[0] == 'p')
		px(a, b, op);
	if (op[0] == 'r' && op[1] == 'r' && op[3])
		rotate_r(a, b, op);
	else
		rotate(a, b, op);
}

static	void	execute_ops(t_stack **a, t_stack **b)
{
	char	*line;

	if (!a)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	line = get_next_line(0);
	while (line)
	{
		if (!is_op(line))
		{
			write(2, "Error\n", 6);
			ft_lstclear(a);
			ft_lstclear(b);
			exit (0);
		}
		execute(a, b, line);
		free (line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (ac < 2)
		return (0);
	if (!check_args(av, ac) || !check_overflow(av, ac))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = parse_args(av, ac);
	if (repeated(a))
	{
		ft_lstclear(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	execute_ops(&a, &b);
	if (is_sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&a);
	return (0);
}
