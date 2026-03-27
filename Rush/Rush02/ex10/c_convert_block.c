/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:24:52 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 23:22:42 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	block_value(const t_block *blk, int *out)
{
	int	k;
	int	val;

	k = 0;
	val = 0;
	while (k < blk->take)
	{
		val = val * 10 + (blk->tail[blk->pos + k] - '0');
		k++;
	}
	*out = val;
	return (1);
}

static int	append_scale_if_needed(t_block *blk)
{
	int			groups_left;
	const char	**scales;
	const char	*key;
	int			n;

	groups_left = (ft_strlen(blk->tail) - (blk->pos + blk->take)) / 3;
	if (groups_left <= 0)
		return (1);
	scales = get_scales();
	n = 0;
	while (scales[n])
		n++;
	if (groups_left > n)
		return (0);
	key = scales[n - groups_left];
	if (!key[0])
		return (1);
	return (put_word(blk->dict, (char *)key, blk->need_sp));
}

int	process_block(t_block *blk)
{
	int	val;

	if (!block_value(blk, &val))
		return (0);
	if (val == 0)
		return (1);
	if (!say_0_999(blk->dict, val, blk->need_sp))
		return (0);
	return (append_scale_if_needed(blk));
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
