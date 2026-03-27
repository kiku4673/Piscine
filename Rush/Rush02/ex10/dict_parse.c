/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:16:13 by hikari            #+#    #+#             */
/*   Updated: 2025/08/24 23:24:51 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

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

static char	*trim_spaces(char *s)
{
	int		start;
	int		end;
	char	*res;

	start = 0;
	if (!s)
		return (NULL);
	while (s[start] == ' ' || s[start] == '\t')
		start++;
	end = ft_strlen(s) - 1;
	while (end >= start && (s[end] == ' ' || s[end] == '\t'))
		end--;
	res = (char *)malloc(end - start + 2);
	if (!res)
		return (NULL);
	ft_strncpy(res, s + start, end - start + 1);
	res[end - start + 1] = '\0';
	return (res);
}

static char	*extract_value(char *line, int i)
{
	int		start;
	int		end;
	char	*raw;
	char	*val;

	i = skip_space(line, i);
	if (line[i] != ':')
		return (NULL);
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	start = i;
	end = ft_strlen(line);
	raw = copy_substring(line, start, end);
	if (!raw)
		return (NULL);
	val = trim_spaces(raw);
	free(raw);
	return (val);
}

int	parse_line(char *line, t_pair *out)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	key = extract_key(line, &i);
	if (!key)
		return (0);
	value = extract_value(line, i);
	if (!value)
		return (free(key), 0);
	out->key = key;
	out->value = value;
	return (1);
}
