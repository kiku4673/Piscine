/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_kv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:02:02 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 15:11:31 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	adjust_bounds(char *line, int *l, int *r)
{
	while (*l <= *r && ft_is_space(line[*l]))
		(*l)++;
	while (*r >= *l && ft_is_space(line[*r]))
		(*r)--;
	if (*l > *r)
		return (0);
	return (1);
}

static int	find_copy_start(char *line, int l, int r)
{
	int	s;

	s = l;
	while (s < r && line[s] == '0')
		s++;
	return (s);
}

static char	*copy_range_or_zero(char *line, int s, int r)
{
	int		n;
	char	*k;
	int		i;

	n = r - s + 1;
	if (n <= 0)
		return (ft_strdup("0"));
	k = (char *)malloc((size_t)n + 1);
	if (!k)
		return (NULL);
	i = 0;
	while (i < n)
	{
		k[i] = line[s + i];
		i++;
	}
	k[n] = '\0';
	return (k);
}

char	*dup_key_trim_zero(char *line, int l, int r)
{
	int	s;

	if (!adjust_bounds(line, &l, &r))
		return (NULL);
	s = find_copy_start(line, l, r);
	return (copy_range_or_zero(line, s, r));
}

char	*dup_trim_right(char *line, int pos)
{
	char	*raw;
	char	*val;

	raw = ft_strdup(line + pos + 1);
	if (!raw)
		return (NULL);
	val = ft_strtrim(raw);
	free(raw);
	return (val);
}
