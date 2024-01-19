/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:08:31 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/10 17:40:55 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] || str2[i]))
	{
		if ((unsigned char) str1[i] != (unsigned char) str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i++;
	}
	return (0);
}

void	apply_op(t_stack	**s, char *op)
{
	if (!ft_strcmp(op, "ra"))
	{
		write (1, "ra\n", 3);
		rotate(s, NULL, op);
	}
	else if (!ft_strcmp(op, "rra"))
	{
		write (1, "rra\n", 4);
		rotate_r(s, NULL, op);
	}
	else if (!ft_strcmp(op, "sa"))
	{
		write (1, "sa\n", 3);
		sx(s, NULL, op);
	}
}
