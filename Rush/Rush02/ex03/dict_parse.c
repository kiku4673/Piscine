/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:16:13 by hikari            #+#    #+#             */
/*   Updated: 2025/08/24 13:53:18 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	skip_leading_zero(char *line, int start, int end)
{
	while (start < end - 1 && line[start] == '0')
		start++;
	return (start);
}

static char	*copy_substring(char *line, int start, int end)
{
	int		j;
	char	*str;

	j = 0;
	str = malloc(end - start + 1);
	if (!(str))
		return (NULL);
	while (j < end - start)
	{
		str[j] = line[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	*extract_key(char *line, int *i_ptr)
{
	int		i;
	int		start;
	char	*key;

	i = skip_space(line, 0);
	start = i;
	while (line[i] && ft_is_digit(line[i]))
		i++;
	if (i == start)
		return (NULL);
	start = skip_leading_zero(line, start, i);
	key = copy_substring(line, start, i);
	if (!(key))
		return (NULL);
	*i_ptr = i;
	return (key);
}

static char	*extract_value(char *line, int i)
{
	char	*val_raw;
	char	*val;

	i = skip_space(line, i);
	if (line[i] != ':')
		return (NULL);
	i++;
	i = skip_space(line, i);
	val_raw = ft_strdup(&line[i]);
	if (!val_raw)
		return (NULL);
	val = ft_strtrim(val_raw);
	free(val_raw);
	return (val);
}

int	parse_line(char *line, t_pair *out)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	key = extract_key(line, &i);
	if (!(key))
		return (0);
	value = extract_value(line, i);
	if (!(value))
		return (free(key), 0);
	out->key = key;
	out->value = value;
	return (1);
}
