/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:40:18 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 23:24:57 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	skip_space(char *str, int i)
{
	while (str[i] != '\0' && ft_is_space(str[i]))
		i++;
	return (i);
}

void	free_dict(t_dict *dict)
{
	int	i;

	if (!dict || !dict->items)
		return ;
	i = 0;
	while (i < dict->size)
	{
		free(dict->items[i].key);
		free(dict->items[i].value);
		i++;
	}
	free(dict->items);
	dict->items = NULL;
	dict->size = 0;
}

static const char	*normalize_numkey(const char *s)
{
	if (*s == '+')
		s++;
	while (*s == '0' && s[1] != '\0')
		s++;
	return (s);
}

char	*dict_find(t_dict *dict, char *key)
{
	int			i;
	const char	*nkey;

	nkey = normalize_numkey(key);
	i = 0;
	while (i < dict->size)
	{
		if (ft_strcmp(normalize_numkey(dict->items[i].key), nkey) == 0)
			return (dict->items[i].value);
		i++;
	}
	return (NULL);
}

int	skip_leading_zero(char *line, int start, int end)
{
	while (start < end - 1 && line[start] == '0')
		start++;
	return (start);
}
