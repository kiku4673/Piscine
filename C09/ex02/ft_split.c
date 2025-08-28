/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:55:49 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/28 14:57:37 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
			str++;
		if (*str)
		{
			count++;
			while (*str && !is_sep(*str, charset))
				str++;
		}
	}
	return (count);
}

int	get_next_word(char **str_ptr, char *charset, char **res_ptr)
{
	int	len;
	int	i;

	while (**str_ptr && is_sep(**str_ptr, charset))
		(*str_ptr)++;
	if (**str_ptr == 0)
		return (0);
	len = 0;
	while ((*str_ptr)[len] && !is_sep((*str_ptr)[len], charset))
		len++;
	*res_ptr = malloc(len + 1);
	if (!*res_ptr)
		return (-1);
	i = 0;
	while (i < len)
	{
		(*res_ptr)[i] = (*str_ptr)[i];
		i++;
	}
	(*res_ptr)[len] = '\0';
	*str_ptr += len;
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words;
	int		i;
	int		ret;

	words = count_words(str, charset);
	res = malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		ret = get_next_word(&str, charset, &res[i]);
		if (ret < 0)
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = 0;
	return (res);
}
