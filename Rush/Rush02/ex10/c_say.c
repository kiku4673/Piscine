/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_say.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 11:17:03 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 16:09:05 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	say_0_99(t_dict *d, int n, int *need_sp)
{
	char	key[12];
	int		tens;
	int		ones;

	if (n < 0 || n > 99)
		return (0);
	int_to_key(n, key);
	if (dict_find(d, key))
		return (put_word(d, key, need_sp));
	tens = (n / 10) * 10;
	ones = n % 10;
	if (tens)
	{
		int_to_key(tens, key);
		if (!put_word(d, key, need_sp))
			return (0);
	}
	if (ones)
	{
		int_to_key(ones, key);
		if (!put_word(d, key, need_sp))
			return (0);
	}
	return (1);
}

int	say_0_999(t_dict *d, int n, int *need_sp)
{
	char	k[12];
	int		hundreds;
	int		rest;

	if (n < 100)
		return (say_0_99(d, n, need_sp));
	hundreds = n / 100;
	rest = n % 100;
	int_to_key(hundreds, k);
	if (!put_word(d, k, need_sp))
		return (0);
	if (!put_word(d, "100", need_sp))
		return (0);
	if (rest)
	{
		if (!say_0_99(d, rest, need_sp))
			return (0);
	}
	return (1);
}

int	put_word(t_dict *d, char *key, int *need_sp)
{
	char	*w;

	w = dict_find(d, key);
	if (!w)
		return (0);
	if (*need_sp)
		ft_putchar(' ');
	ft_putstr(w);
	*need_sp = 1;
	return (1);
}
