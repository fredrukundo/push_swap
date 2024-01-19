/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:11:41 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/09 17:38:07 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*current;
	t_stack	*next;

	current = *lst;
	if (lst == NULL || *lst == NULL)
		return ;
	while (current)
	{
		next = current->next;
		if (current)
			free(current);
		current = next;
	}
	*lst = NULL;
}

int	ft_strcmp(char *str1, char *str2)
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

int	is_op(char *op)
{
	return (!ft_strcmp(op, "pa\n") || !ft_strcmp(op, "pb\n")
		|| !ft_strcmp(op, "sa\n") || !ft_strcmp(op, "sb\n")
		|| !ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rb\n")
		|| !ft_strcmp(op, "rr\n") || !ft_strcmp(op, "rra\n")
		|| !ft_strcmp(op, "rrb\n") || !ft_strcmp(op, "rrr\n")
		|| !ft_strcmp(op, "ss\n"));
}
