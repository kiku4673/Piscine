/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:04:46 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 15:04:52 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	cmp_numstr_len(char *a, char *b)
{
	int	la;
	int	lb;

	la = ft_strlen(a);
	lb = ft_strlen(b);
	if (la != lb)
		return ((la > lb) - (la < lb));
	return (ft_strcmp(a, b));
}

int	str_to_int_safe(char *s, int *out)
{
	int	i;
	int	n;

	if (ft_strlen(s) > 9)
		return (0);
	i = 0;
	n = 0;
	while (s[i])
	{
		if (!ft_is_digit(s[i]))
			return (0);
		n = n * 10 + (s[i] - '0');
		i++;
	}
	*out = n;
	return (1);
}
