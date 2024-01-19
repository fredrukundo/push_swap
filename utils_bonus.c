/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:23:31 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/14 22:59:36 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			s;
	int			result;

	i = 0;
	result = 0;
	res = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((long long)result * 10 + (str[i] - '0')) * (long long)s;
		if (res > 2147483647 || res < -2147483648)
			return (write(2, "Error\n", 6), exit(5), 5);
		result = result * 10 + (str[i++] - '0');
	}
	return (result * s);
}

int	is_nb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *s)
{
	t_stack	*tmp;

	tmp = s;
	while (tmp->next)
	{
		if (tmp->val >= tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
