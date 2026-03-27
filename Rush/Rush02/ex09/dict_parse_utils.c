/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 07:10:14 by hikari            #+#    #+#             */
/*   Updated: 2025/08/24 14:26:22 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_pairs(t_pair *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i].key);
		free(arr[i].value);
		i++;
	}
	free(arr);
}

char	*dup_slice(const char *s, int start, int end)
{
	int		len;
	char	*out;
	int		i;

	len = end - start;
	out = (char *)malloc((size_t)len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	out[len] = '\0';
	return (out);
}

int	process_nonempty_line(char *line, t_pair *slot)
{
	if (!parse_line(line, slot))
		return (0);
	return (1);
}

int	handle_segment(t_seginfo info, t_pair *arr, int *idx)
{
	int		len;
	char	*one;

	len = info.end - info.start;
	one = dup_slice(info.blob, info.start, info.end);
	if (!one)
		return (0);
	if (len > 0)
	{
		if (!process_nonempty_line(one, &arr[*idx]))
			return (free(one), 0);
		(*idx)++;
	}
	free (one);
	return (1);
}
