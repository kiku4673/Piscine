/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:40:12 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:59:16 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	int_to_key(int n, char *dst)
{
	char	buf[12];
	int		b;
	int		i;

	if (n == 0)
	{
		dst[0] = '0';
		dst[1] = '\0';
		return ;
	}
	b = 0;
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

int	say_0_99(t_dict *d, int n, int *need_sp)
{
	char	k[12];
	int		tens;
	int		ones;

	if (n < 0 || n > 99)
		return (0);
	int_to_key(n, k);
	if (dict_find(d, k))
		return (put_word(d, k, need_sp));
	tens = (n / 10) * 10;
	ones = n % 10;
	if (tens)
	{
		int_to_key(tens, k);
		if (!put_word(d, k, need_sp))
			return (0);
	}
	if (ones)
	{
		int_to_key(ones, k);
		if (!put_word(d, k, need_sp))
			return (0);
	}
	return (1);
}

int	say_0_999(t_dict *d, int n, int *need_sp)
{
	char	k[12];
	int		h;
	int		r;

	if (n < 100)
		return (say_0_99(d, n, need_sp));
	h = n / 100;
	r = n % 100;
	int_to_key(h, k);
	if (!dict_find(d, k))
		return (0);
	if (!say_0_99(d, h, need_sp))
		return (0);
	if (!put_word(d, (char *)"100", need_sp))
		return (0);
	if (r)
		return (say_0_99(d, r, need_sp));
	return (1);
}
