/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiraku <hiraku@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:10:08 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 09:27:34 by hiraku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	skip_leading_spaces_and_sign(char *in, int *start)
{
	int	i;

	i = 0;
	while (in[i] && ft_is_space(in[i]))
		i++;
	if (in[i] == '+')
		i++;
	*start = i;
	return (i);
}

static int	validate_digits(char *in, int *i)
{
	int	has_digit;

	has_digit = 0;
	while (in[*i])
	{
		if (ft_is_space(in[*i]))
			break ;
		if (!ft_is_digit(in[*i]))
			return (-1);
		has_digit = 1;
		(*i)++;
	}
	while (in[*i])
	{
		if (!ft_is_space(in[*i]))
			return (-1);
		(*i)++;
	}
	return (has_digit);
}

static int	handle_zero_case(char *in, int s, char **out)
{
	while (in[s] == '0')
		s++;
	if (!in[s])
	{
		*out = ft_strdup("0");
		return (1);
	}
	return (0);
}

static char	*alloc_number(char *in, int s, int len)
{
	char	*buf;
	int		i;

	buf = (char *)malloc((size_t)len + 1);
	if (!buf)
		return (NULL);
	i = 0;
	while (i < len)
	{
		buf[i] = in[s + i];
		i++;
	}
	buf[len] = '\0';
	return (buf);
}

/*
** 入力: "  +00042  " → 出力: "42"
** 負号, 小数点, 非数字 → 0 を返して Error 扱い
*/
int	normalize_number(char *in, char **out)
{
	int	i;
	int	start;
	int	s;
	int	len;
	int	has_digit;

	if (!in)
		return (0);
	i = skip_leading_spaces_and_sign(in, &start);
	has_digit = validate_digits(in, &i);
	if (has_digit == -1)
		return (0);
	if (!has_digit)
	{
		*out = ft_strdup("0");
		return (*out != NULL);
	}
	s = start;
	if (handle_zero_case(in, s, out))
		return (*out != NULL);
	len = 0;
	while (in[s + len] && ft_is_digit(in[s + len]))
		len++;
	*out = alloc_number(in, s, len);
	return (*out != NULL);
}
