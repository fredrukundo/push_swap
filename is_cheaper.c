/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cheaper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:08:08 by frukundo          #+#    #+#             */
/*   Updated: 2024/01/09 17:38:17 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ops_count(t_c_ind *ind, int len1, int len2)
{
	int	count;

	count = 0;
	if (ind->a > len1 / 2)
		count += len1 - ind->a;
	else
		count += ind->a;
	if (ind->b > len2 / 2)
		count += len2 - ind->b;
	else
		count += ind->b;
	if (len1 - ind->a == len2 - ind->b)
		return (count / 2);
	return (count);
}

int	is_cheaper(t_c_ind *ind1, t_c_ind *ind2, int len1, int len2)
{
	if (ops_count(ind1, len1, len2) < ops_count(ind2, len1, len2))
		return (1);
	return (0);
}
