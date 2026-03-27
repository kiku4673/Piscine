/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:05:14 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 15:12:02 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	calc_lengths(char *num, char *scale, int *hl, int *tl)
{
	int	l_num;
	int	l_sc;

	l_num = ft_strlen(num);
	l_sc = ft_strlen(scale);
	if (l_num <= l_sc - 1)
		return (0);
	*hl = l_num - (l_sc - 1);
	*tl = l_sc - 1;
	return (1);
}

static int	alloc_buffers(char **head, char **tail, int hl, int tl)
{
	*head = (char *)malloc((size_t)hl + 1);
	*tail = (char *)malloc((size_t)tl + 1);
	if (!*head || !*tail)
		return (free(*head), free(*tail), 0);
	return (1);
}

static void	copy_head(char *num, char *head, int hl)
{
	int	i;

	i = 0;
	while (i < hl)
	{
		head[i] = num[i];
		i++;
	}
	head[hl] = '\0';
}

static void	copy_tail(char *num, int hl, char *tail, int tl)
{
	int	i;

	i = 0;
	while (i < tl)
	{
		tail[i] = num[hl + i];
		i++;
	}
	tail[tl] = '\0';
}

int	split_head_tail(char *num, char *scale, char **head, char **tail)
{
	int	hl;
	int	tl;

	if (!calc_lengths(num, scale, &hl, &tl))
		return (0);
	if (!alloc_buffers(head, tail, hl, tl))
		return (0);
	copy_head(num, *head, hl);
	copy_tail(num, hl, *tail, tl);
	return (1);
}
