/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:40:08 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 15:03:08 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	count_lines(char *s, int n)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < n)
	{
		if (s[i] == '\n')
			c++;
		i++;
	}
	return (c + 1);
}

static int	copy_line(char *dst, char *src, int off, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[off + i];
		i++;
	}
	dst[n] = '\0';
	return (1);
}

static int	push_line(t_dict *dict, char *one)
{
	if (!one[0])
		return (1);
	if (!parse_dict_line(one, &dict->items[dict->size]))
		return (0);
	dict->size++;
	return (1);
}

static int	fill_from_blob(t_dict *dict, char *b, int len)
{
	int		i;
	int		st;
	int		n;
	char	*one;

	dict->size = 0;
	i = 0;
	st = 0;
	while (i <= len)
	{
		if (i == len || b[i] == '\n')
		{
			n = i - st;
			one = (char *)malloc((size_t)n + 1);
			if (!one)
				return (0);
			copy_line(one, b, st, n);
			if (!push_line(dict, one))
				return (free(one), 0);
			free(one);
			st = i + 1;
		}
		i++;
	}
	return (1);
}

int	load_dict(const char *path, t_dict *dict)
{
	int		len;
	char	*blob;
	int		lines;

	blob = read_all_file(path, &len);
	if (!blob)
		return (0);
	lines = count_lines(blob, len);
	dict->items = (t_pair *)malloc(sizeof(t_pair) * (size_t)lines);
	if (!dict->items)
		return (free(blob), 0);
	if (!fill_from_blob(dict, blob, len))
	{
		free(blob);
		free_dict(dict);
		return (0);
	}
	free(blob);
	return (1);
}
