/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:23:44 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 23:26:54 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	split_head_tail(char *num_str, char *scale,
	char **head, char **tail)
{
	int	head_len;
	int	tail_len;
	int	i;

	head_len = ft_strlen(num_str) - (ft_strlen(scale) - 1);
	tail_len = ft_strlen(scale) - 1;
	*head = (char *)malloc(head_len + 1);
	*tail = (char *)malloc(tail_len + 1);
	if (!*head || !*tail)
		return (0);
	i = 0;
	while (i < head_len)
	{
		(*head)[i] = num_str[i];
		i++;
	}
	(*head)[i] = '\0';
	i = 0;
	while (i < tail_len)
	{
		(*tail)[i] = num_str[head_len + i];
		i++;
	}
	(*tail)[i] = '\0';
	return (1);
}

int	process_tail_if_needed(t_dict *dict, char *tail, int *need_sp)
{
	int	allzero;
	int	i;

	allzero = 1;
	i = 0;
	while (i < ft_strlen(tail))
	{
		if (tail[i] != '0')
			allzero = 0;
		i++;
	}
	if (!allzero)
	{
		if (!process_tail_blocks(dict, tail, need_sp))
			return (0);
	}
	return (1);
}

int	process_scale(t_dict *dict, char *num_str, char *scale, int *need_sp)
{
	char	*head;
	char	*tail;
	int		h;
	int		head_len;

	head_len = ft_strlen(num_str) - (ft_strlen(scale) - 1);
	if (head_len > 3)
		return (0);
	if (ft_strlen(num_str) <= ft_strlen(scale) - 1)
		return (0);
	if (!split_head_tail(num_str, scale, &head, &tail))
		return (0);
	if (!str_to_int_safe(head, &h))
		return (free(head), free(tail), 0);
	if (h > 999)
		return (free(head), free(tail), 0);
	if (!say_0_999(dict, h, need_sp))
		return (free(head), free(tail), 0);
	if (!put_word(dict, (char *)scale, need_sp))
		return (free(head), free(tail), 0);
	if (!process_tail_if_needed(dict, tail, need_sp))
		return (free(head), free(tail), 0);
	free(head);
	free(tail);
	return (1);
}
