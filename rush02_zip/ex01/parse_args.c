/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:10:08 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:10:15 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/*
** 入力: "  +00042  " → 出力: "42"
** 負号, 小数点, 非数字 → 0 を返して Error 扱い
*/
int	normalize_number(char *in, char **out)
{
	int	i;
	int	has_digit;
	int	start;
	int	s;
	int	len;
	char	*buf;

	i = 0;
	has_digit = 0;
	if (!in)
		return (0);
	while (in[i] && ft_is_space(in[i]))
		i++;
	if (in[i] == '+')
		i++;
	start = i;
	while (in[i])
	{
		if (ft_is_space(in[i]))
			break ;
		if (!ft_is_digit(in[i]))
			return (0);
		has_digit = 1;
		i++;
	}
	while (in[i])
	{
		if (!ft_is_space(in[i]))
			return (0);
		i++;
	}
	if (!has_digit)
	{
		*out = ft_strdup("0");
		return (*out != NULL);
	}
	s = start;
	while (in[s] == '0')
		s++;
	if (!in[s])
	{
		*out = ft_strdup("0");
		return (*out != NULL);
	}
	len = 0;
	while (in[s + len] && ft_is_digit(in[s + len]))
		len++;
	buf = (char *)malloc((size_t)len + 1);
	if (!buf)
		return (0);
	i = 0;
	while (i < len)
	{
		buf[i] = in[s + i];
		i++;
	}
	buf[len] = '\0';
	*out = buf;
	return (1);
}
