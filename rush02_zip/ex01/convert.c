/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:40:26 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:11:54 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	put_word(t_dict *d, char *key, int *need_sp)
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

static void	int_to_key(int n, char *dst)
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

static int	say_0_99(t_dict *d, int n, int *need_sp)
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

static int	say_0_999(t_dict *d, int n, int *need_sp)
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

static const char	*g_scales[] = {
	"1000000000000000000000000",
	"1000000000000000000000",
	"1000000000000000000",
	"1000000000000000",
	"1000000000000",
	"1000000000",
	"1000000",
	"1000",
	NULL
};

static int	cmp_numstr_len(char *a, char *b)
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

static int	str_to_int_safe(char *s, int *out)
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

int	number_to_words(t_dict *dict, char *num_str)
{
	int		need_sp;
	int		i;
	int		l_num;
	int		l_sc;
	int		k;
	int		head_len;
	int		tail_len;
	char	*head;
	char	*tail;
	int		h;
	int		allzero;
	int		pos;
	int		rem;
	int		first_block;
	int		blocks;
	int		b;
	int		take;
	int		val;

	if (ft_strcmp(num_str, "0") == 0)
		return (put_word(dict, "0", &(int){0}));
	need_sp = 0;
	if (dict_find(dict, num_str))
		return (put_word(dict, num_str, &need_sp));
	i = 0;
	while (g_scales[i])
	{
		if (cmp_numstr_len(num_str, (char *)g_scales[i]) >= 0)
		{
			l_num = ft_strlen(num_str);
			l_sc = ft_strlen((char *)g_scales[i]);
			k = l_sc - 1;
			if (l_num > k)
			{
				head_len = l_num - k;
				tail_len = k;
				head = (char *)malloc((size_t)head_len + 1);
				tail = (char *)malloc((size_t)tail_len + 1);
				if (!head || !tail)
					return (free(head), free(tail), 0);
				b = 0;
				while (b < head_len)
				{
					head[b] = num_str[b];
					b++;
				}
				head[head_len] = '\0';
				b = 0;
				while (b < tail_len)
				{
					tail[b] = num_str[head_len + b];
					b++;
				}
				tail[tail_len] = '\0';
				if (!str_to_int_safe(head, &h))
					return (free(head), free(tail), 0);
				if (!say_0_999(dict, h, &need_sp))
					return (free(head), free(tail), 0);
				if (!put_word(dict, (char *)g_scales[i], &need_sp))
					return (free(head), free(tail), 0);
				allzero = 1;
				b = 0;
				while (b < tail_len)
				{
					if (tail[b] != '0')
						allzero = 0;
					b++;
				}
				if (!allzero)
				{
					pos = 0;
					rem = tail_len % 3;
					first_block = (rem != 0) * rem + (rem == 0) * 3;
					blocks = (tail_len - rem) / 3 + (rem != 0);
					b = 0;
					while (b < blocks)
					{
						take = (b == 0) * first_block + (b != 0) * 3;
						val = 0;
						k = 0;
						while (k < take)
						{
							val = val * 10 + (tail[pos + k] - '0');
							k++;
						}
						pos += take;
						if (val != 0)
						{
							if (!say_0_999(dict, val, &need_sp))
								return (free(head), free(tail), 0);
						}
						b++;
					}
				}
				free(head);
				free(tail);
				return (1);
			}
		}
		i++;
	}
	if (ft_strlen(num_str) > 9)
		return (0);
	if (!str_to_int_safe(num_str, &h))
		return (0);
	i = 0;
	return (say_0_999(dict, h, &i));
}