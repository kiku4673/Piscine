/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:24:52 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 21:12:10 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static const char	*scale_key_from_groups(int groups_left)
{
	const char	**scales;
	int			n;

	if (groups_left <= 0)
		return ("");
	scales = get_scales();
	n = 0;
	while (scales[n])
		n++;
	if (groups_left > n)
		return ("");
	return (scales[n - groups_left]);
}

int	process_block(t_block *blk)
{
	int			val;
	int			k;
	int			groups_left;
	const char	*key;

	val = 0;
	k = 0;
	while (k < blk->take)
	{
		val = val * 10 + (blk->tail[blk->pos + k] - '0');
		k++;
	}
	if (val != 0)
	{
		if (!say_0_999(blk->dict, val, blk->need_sp))
			return (0);
		groups_left = (ft_strlen(blk->tail) - (blk->pos + blk->take)) / 3;
		if (groups_left > 0)
		{
			key = scale_key_from_groups(groups_left);
			if (key[0] && !put_word(blk->dict, (char *)key, blk->need_sp))
				return (0);
		}
	}
	return (1);
}

int	process_tail_blocks(t_dict *dict, char *tail, int *need_sp)
{
	int		tail_len;
	int		pos;
	t_block	blk;

	tail_len = ft_strlen(tail);
	pos = 0;
	blk.dict = dict;
	blk.tail = tail;
	blk.need_sp = need_sp;
	while (pos < tail_len)
	{
		blk.pos = pos;
		if (pos == 0 && (tail_len % 3) != 0)
			blk.take = tail_len % 3;
		else
			blk.take = 3;
		if (!process_block(&blk))
			return (0);
		pos += blk.take;
	}
	return (1);
}
