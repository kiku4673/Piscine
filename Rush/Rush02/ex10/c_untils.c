/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_untils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:25:19 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 11:27:20 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	str_to_int_safe(char *s, int *out)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (ft_strlen(s) > 9)
		return (0);
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

int	cmp_numstr_len(char *a, char *b)
{
	int	la;
	int	lb;
	int	cmp;

	la = ft_strlen(a);
	lb = ft_strlen(b);
	if (la != lb)
		return ((la > lb) - (la < lb));
	cmp = ft_strcmp(a, b);
	return (cmp);
}

void	int_to_key(int n, char *dst)
{
	char	buf[12];
	int		b;
	int		i;

	b = 0;
	if (n == 0)
	{
		dst[0] = '0';
		dst[1] = '\0';
		return ;
	}
	while (n)
	{
		buf[b++] = (char)((n % 10) + '0');
		n /= 10;
	}
	i = 0;
	while (b > 0)
		dst[i++] = buf[--b];
	dst[i] = '\0';
}
