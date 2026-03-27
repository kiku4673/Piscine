/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:40:35 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 15:04:22 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	handle_scale(t_dict *d, char *num, char *scale, int *need_sp)
{
	char	*head;
	char	*tail;
	int		ok;

	if (!split_head_tail(num, scale, &head, &tail))
		return (0);
	ok = say_head_and_scale(d, head, scale, need_sp);
	if (ok)
		ok = say_tail_if_needed(d, tail, need_sp);
	free(head);
	free(tail);
	return (ok);
}

int	number_to_words(t_dict *dict, char *num_str)
{
	int	need_sp;
	int	val;
	int	tmp;

	if (ft_strcmp(num_str, "0") == 0)
		return (put_word(dict, "0", &(int){0}));
	need_sp = 0;
	if (dict_find(dict, num_str))
		return (put_word(dict, num_str, &need_sp));
	if (cmp_numstr_len(num_str, (char *)"1000") >= 0)
	{
		if (handle_scale(dict, num_str, (char *)"1000000", &need_sp))
			return (1);
		if (handle_scale(dict, num_str, (char *)"1000", &need_sp))
			return (1);
	}
	if (ft_strlen(num_str) > 9)
		return (0);
	tmp = 0;
	if (!str_to_int_safe(num_str, &val))
		return (0);
	return (say_0_999(dict, val, &tmp));
}
