/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:40:08 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:11:11 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*read_all(const char *path, int *out_len)
{
	int		fd;
	int		n;
	int		total;
	char	buf[4096];
	char	*acc;
	char	*tmp;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	acc = NULL;
	total = 0;
	n = read(fd, buf, 4096);
	while (n > 0)
	{
		tmp = (char *)malloc((size_t)(total + n));
		if (!tmp)
		{
			free(acc);
			close(fd);
			return (NULL);
		}
		i = 0;
		while (i < total)
		{
			if (acc)
				tmp[i] = acc[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			tmp[total + i] = buf[i];
			i++;
		}
		free(acc);
		acc = tmp;
		total += n;
		n = read(fd, buf, 4096);
	}
	close(fd);
	*out_len = total;
	return (acc);
}

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

static int	parse_line(char *line, t_pair *out)
{
	int		i;
	int		k0;
	int		s;
	int		j;
	char	*key;
	char	*val_raw;
	char	*val;

	i = 0;
	while (ft_is_space(line[i]))
		i++;
	k0 = i;
	if (!line[i])
		return (0);
	while (line[i] && ft_is_digit(line[i]))
		i++;
	if (i == k0)
		return (0);
	s = k0;
	while (s < i - 1 && line[s] == '0')
		s++;
	key = (char *)malloc((size_t)(i - s + 1));
	if (!key)
		return (0);
	j = 0;
	while (j < i - s)
	{
		key[j] = line[s + j];
		j++;
	}
	key[i - s] = '\0';
	while (ft_is_space(line[i]))
		i++;
	if (line[i] != ':')
		return (free(key), 0);
	i++;
	while (ft_is_space(line[i]))
		i++;
	val_raw = ft_strdup(&line[i]);
	if (!val_raw)
		return (free(key), 0);
	val = ft_strtrim(val_raw);
	free(val_raw);
	if (!val)
		return (free(key), 0);
	out->key = key;
	out->value = val;
	return (1);
}

int	load_dict(const char *path, t_dict *dict)
{
	int		len;
	char	*blob;
	int		lines;
	t_pair	*arr;
	int		idx;
	int		start;
	int		i;
	int		L;
	char	*one;
	int		j;

	len = 0;
	blob = read_all(path, &len);
	if (!blob)
		return (0);
	lines = count_lines(blob, len);
	arr = (t_pair *)malloc(sizeof(t_pair) * (size_t)lines);
	if (!arr)
		return (free(blob), 0);
	idx = 0;
	start = 0;
	i = 0;
	while (i <= len)
	{
		if (i == len || blob[i] == '\n')
		{
			L = i - start;
			one = (char *)malloc((size_t)L + 1);
			if (!one)
				return (free(blob), free(arr), 0);
			j = 0;
			while (j < L)
			{
				one[j] = blob[start + j];
				j++;
			}
			one[L] = '\0';
			if (L > 0)
			{
				if (!parse_line(one, &arr[idx]))
				{
					free(one);
					free(blob);
					j = 0;
					while (j < idx)
					{
						free(arr[j].key);
						free(arr[j].value);
						j++;
					}
					free(arr);
					return (0);
				}
				idx++;
			}
			free(one);
			start = i + 1;
		}
		i++;
	}
	free(blob);
	dict->items = arr;
	dict->size = idx;
	return (1);
}

void	free_dict(t_dict *dict)
{
	int	i;

	if (!dict || !dict->items)
		return ;
	i = 0;
	while (i < dict->size)
	{
		free(dict->items[i].key);
		free(dict->items[i].value);
		i++;
	}
	free(dict->items);
	dict->items = NULL;
	dict->size = 0;
}