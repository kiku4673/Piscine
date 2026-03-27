/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_convert_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:23:44 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 16:03:24 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// 1
// int	split_head_tail(char *num_str, char *scale,
// 	char **head, char **tail)
// {
// 	int	head_len;
// 	int	tail_len;
// 	int	i;

// 	head_len = ft_strlen(num_str) - (ft_strlen(scale) - 1);
// 	tail_len = ft_strlen(scale) - 1;
// 	*head = (char *)malloc(head_len + 1);
// 	*tail = (char *)malloc(tail_len + 1);
// 	if (!*head || !*tail)
// 		return (0);
// 	i = 0;
// 	while (i < head_len)
// 	{
// 		(*head)[i] = num_str[i];
// 		i++;
// 	}
// 	(*head)[i] = '\0';
// 	i = 0;
// 	while (i < tail_len)
// 	{
// 		(*tail)[i] = num_str[head_len + i];
// 		i++;
// 	}
// 	(*tail)[i] = '\0';
// 	return (1);
// }

// 2
// int	split_head_tail(char *num_str, char *scale,
// 	char **head, char **tail)
// {
// 	int	head_len;
// 	int	total_len;

// 	total_len = ft_strlen(num_str);
// 	// head_len は「num_str 全体」-「scale の桁数 - 1」
// 	head_len = total_len - (ft_strlen(scale) - 1);
// 	if (head_len < 0) // 不正ケースの防止
// 		head_len = 0;

// 	*head = malloc(head_len + 1);
// 	*tail = malloc(total_len - head_len + 1);
// 	if (!*head || !*tail)
// 		return (0);

// 	// head をコピー
// 	ft_strncpy(*head, num_str, head_len);
// 	(*head)[head_len] = '\0';

// 	// tail をコピー
// 	ft_strcpy(*tail, num_str + head_len);
// 	return (1);
// }

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

	// ★ デバッグ追加 ★
	printf("DEBUG split: scale=%s, num_str=%s, head=%s, tail=%s\n",
		scale, num_str, *head, *tail);

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
	printf("DEBUG: tail=\"%s\", allzero=%d\n", tail, allzero);
	if (!allzero)
	{
		if (!process_tail_blocks(dict, tail, need_sp))
			return (0);
	}
	return (1);
}

// int	process_tail_if_needed(t_dict *dict, char *tail, int *need_sp)
// {
// 	int	allzero;
// 	int	i;
// 	int	h;

// 	allzero = 1;
// 	i = 0;
// 	while (i < ft_strlen(tail))
// 	{
// 		if (tail[i] != '0')
// 			allzero = 0;
// 		i++;
// 	}
// 	if (allzero)
// 		return (1);
// 	// ✅ ここを追加：3桁以下なら直接 say_0_999 で処理
// 	if (ft_strlen(tail) <= 3)
// 	{
// 		if (!str_to_int_safe(tail, &h))
// 			return (0);
// 		return (say_0_999(dict, h, need_sp));
// 	}
// 	return (process_tail_blocks(dict, tail, need_sp));
// }


// int	process_tail_if_needed(t_dict *dict, char *tail, int *need_sp)
// {
// 	int	allzero;
// 	int	i;

// 	allzero = 1;
// 	i = 0;
// 	while (i < ft_strlen(tail))
// 	{
// 		if (tail[i] != '0')
// 			allzero = 0;
// 		i++;
// 	}
// 	if (!allzero)
// 	{
// 		if (!process_tail_blocks(dict, tail, need_sp))
// 			return (0);
// 	}
// 	return (1);
// }

// int	process_scale(t_dict *dict, char *num_str, char *scale, int *need_sp)
int	process_scale(t_dict *dict, char *num_str, char *scale, int *need_sp)
{
	char	*head;
	char	*tail;
	int		h;

	printf("DEBUG process_scale start: num_str=%s, scale=%s\n", num_str, scale);

	if (ft_strlen(num_str) <= ft_strlen(scale) - 1)
		return (0);

	if (!split_head_tail(num_str, scale, &head, &tail))
		return (0);

	printf("DEBUG process_scale split: head=%s, tail=%s\n", head, tail);

	if (!str_to_int_safe(head, &h))
		return (free(head), free(tail), 0);

	printf("DEBUG process_scale head-int=%d\n", h);

	if (!say_0_999(dict, h, need_sp)) {
		printf("DEBUG FAIL say_0_999 for head=%s\n", head);
		return (free(head), free(tail), 0);
	}

	if (!put_word(dict, (char *)scale, need_sp)) {
		printf("DEBUG FAIL put_word for scale=%s\n", scale);
		return (free(head), free(tail), 0);
	}

	if (!process_tail_if_needed(dict, tail, need_sp)) {
		printf("DEBUG FAIL process_tail_if_needed tail=%s\n", tail);
		return (free(head), free(tail), 0);
	}

	free(head);
	free(tail);
	return (1);
}

// int	process_scale(t_dict *dict, char *num_str, char *scale, int *need_sp)
// {
// 	char	*head;
// 	char	*tail;
// 	int		h;

// 	if (ft_strlen(num_str) <= ft_strlen(scale) - 1)
// 		return (0);
// 	if (!split_head_tail(num_str, scale, &head, &tail))
// 		return (0);
// 	if (!str_to_int_safe(head, &h))
// 		return (free(head), free(tail), 0);
// 	if (!say_0_999(dict, h, need_sp))
// 		return (free(head), free(tail), 0);
// 	if (!put_word(dict, (char *)scale, need_sp))
// 		return (free(head), free(tail), 0);
// 	if (!process_tail_if_needed(dict, tail, need_sp))
// 		return (free(head), free(tail), 0);
// 	free(head);
// 	free(tail);
// 	return (1);
// }
