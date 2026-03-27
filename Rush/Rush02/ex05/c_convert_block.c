/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:24:52 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 15:33:21 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

int	process_block(t_block *blk)
{
	int	val;
	int	k;

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
	}
	return (1);
}

int	process_tail_blocks(t_dict *dict, char *tail, int *need_sp)
{
	int		tail_len;
	int		pos;
	int		b;
	t_block	blk;

	tail_len = ft_strlen(tail);
	pos = 0;
	b = 0;
	while (b * 3 < tail_len)
	{
		blk.dict = dict;
		blk.tail = tail;
		blk.pos = pos;
		blk.need_sp = need_sp;
		if (b == 0 && tail_len % 3 != 0)
			blk.take = tail_len % 3;
		else
			blk.take = 3;
		if (!process_block(&blk))
			return (0);
		pos += blk.take;
		b++;
	}
	return (1);
}
