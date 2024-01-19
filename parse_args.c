/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:06:42 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/10 17:50:40 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_stack	*parse_str(char *nbs)
{
	int		i;
	int		len;
	t_stack	*s;

	i = 0;
	s = NULL;
	len = ft_strlen(nbs);
	while (len > 0)
	{
		len--;
		while (nbs[len] == ' ')
			len--;
		if (len < 0)
			break ;
		while (nbs[len] >= '0' && nbs[len] <= '9')
			len--;
		if (nbs[len] != '-' && nbs[len] != '+')
			len++;
		if (nbs[len])
			push(&s, ft_atoi(&nbs[len]));
	}
	return (s);
}

static t_stack	*parse_nbs(char **nbs, int ac)
{
	int		i;
	t_stack	*s;
	char	**spl;
	int		j;

	i = 1;
	s = NULL;
	while (ac > 0)
	{
		j = 0;
		spl = ft_split(nbs[ac], ' ');
		while (spl[j])
			j++;
		while (--j >= 0)
			push(&s, ft_atoi(spl[j]));
		ft_free(spl);
		free(spl);
		ac--;
	}
	return (s);
}

t_stack	*parse_args(char **nbs, int ac)
{
	if (ac == 2)
		return (parse_str(nbs[1]));
	else
		return (parse_nbs(nbs, ac - 1));
}

int	repeated(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		if (!s->next)
			return (0);
		tmp = s->next;
		while (tmp)
		{
			if (s->val == tmp->val)
				return (1);
			tmp = tmp->next;
		}
		s = s->next;
	}
	return (0);
}
