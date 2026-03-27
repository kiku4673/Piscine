/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:05:45 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 15:05:55 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	say_head_and_scale(t_dict *d, char *head, char *scale, int *need_sp)
{
	int	h;

	if (!str_to_int_safe(head, &h))
		return (0);
	if (!say_0_999(d, h, need_sp))
		return (0);
	if (!put_word(d, scale, need_sp))
		return (0);
	return (1);
}

int	say_tail_if_needed(t_dict *d, char *tail, int *need_sp)
{
	int	i;
	int	h;

	i = 0;
	while (tail[i] && tail[i] == '0')
		i++;
	if (!tail[i])
		return (1);
	if (!str_to_int_safe(tail, &h))
		return (0);
	return (say_0_999(d, h, need_sp));
}
