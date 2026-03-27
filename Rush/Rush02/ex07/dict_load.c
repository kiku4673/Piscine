/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 06:25:18 by hikari            #+#    #+#             */
/*   Updated: 2025/08/24 14:51:25 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	walk_blob(char *blob, int len, t_pair *arr, int *out_cnt)
{
	int			i;
	int			start;
	int			idx;
	t_seginfo	seg;

	i = 0;
	start = 0;
	idx = 0;
	while (i <= len)
	{
		if (i == len || blob[i] == '\n')
		{
			seg.blob = blob;
			seg.start = start;
			seg.end = i;
			if (!handle_segment(seg, arr, &idx))
				return (*out_cnt = idx, 0);
			start = i + 1;
		}
		i++;
	}
	*out_cnt = idx;
	return (1);
}

static int	parse_blob_to_pairs(char *blob, int len,
	t_pair **out_arr, int *out_cnt)
{
	int		lines;
	t_pair	*arr;
	int		cnt;

	lines = count_lines(blob, len);
	arr = (t_pair *)malloc(sizeof(t_pair) * (size_t)lines);
	if (!arr)
		return (0);
	if (!walk_blob(blob, len, arr, &cnt))
		return (free_pairs(arr, cnt), 0);
	*out_arr = arr;
	*out_cnt = cnt;
	return (1);
}

int	load_dict(const char *path, t_dict *dict)
{
	char	*blob;
	int		len;
	t_pair	*arr;
	int		cnt;

	len = 0;
	blob = read_all_text(path, &len);
	if (!blob)
		return (0);
	if (!parse_blob_to_pairs(blob, len, &arr, &cnt))
		return (free(blob), 0);
	free(blob);
	dict->items = arr;
	dict->size = cnt;
	return (1);
}
