/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:38:58 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 15:01:44 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	find_first_colon(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ':')
			return (i);
		i++;
	}
	return (-1);
}

static char	*get_key_from_line(char *line, int colon)
{
	return (dup_key_trim_zero(line, 0, colon - 1));
}

static char	*get_value_from_line(char *line, int colon)
{
	return (dup_trim_right(line, colon));
}

int	parse_dict_line(char *line, t_pair *out)
{
	int		colon;
	char	*key;
	char	*val;

	colon = find_first_colon(line);
	if (colon < 0)
		return (0);
	key = get_key_from_line(line, colon);
	if (!key)
		return (0);
	val = get_value_from_line(line, colon);
	if (!val)
		return (free(key), 0);
	out->key = key;
	out->value = val;
	return (1);
}
