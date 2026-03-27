/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:10:08 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:53:37 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	skip_spaces_and_sign(char *in, int *i)
{
	while (in[*i] && ft_is_space(in[*i]))
		(*i)++;
	if (in[*i] == '+')
		(*i)++;
}

static int	validate_digits_and_tail(char *in, int *i, int *has_digit)
{
	while (in[*i] && !ft_is_space(in[*i]))
	{
		if (!ft_is_digit(in[*i]))
			return (0);
		*has_digit = 1;
		(*i)++;
	}
	while (in[*i])
	{
		if (!ft_is_space(in[*i]))
			return (0);
		(*i)++;
	}
	return (1);
}

static char	*dup_digits_trim_zero(char *in, int start)
{
	int		s;
	int		len;
	int		k;
	char	*buf;

	s = start;
	while (in[s] == '0')
		s++;
	if (!in[s])
		return (ft_strdup("0"));
	len = 0;
	while (ft_is_digit(in[s + len]))
		len++;
	buf = (char *)malloc((size_t)len + 1);
	if (!buf)
		return (NULL);
	k = 0;
	while (k < len)
	{
		buf[k] = in[s + k];
		k++;
	}
	buf[len] = '\0';
	return (buf);
}

int	normalize_number(char *in, char **out)
{
	int	i;
	int	start;
	int	has_digit;

	if (!in || !out)
		return (0);
	i = 0;
	has_digit = 0;
	skip_spaces_and_sign(in, &i);
	start = i;
	if (!validate_digits_and_tail(in, &i, &has_digit))
		return (0);
	if (!has_digit)
	{
		*out = ft_strdup("0");
		return (*out != NULL);
	}
	*out = dup_digits_trim_zero(in, start);
	return (*out != NULL);
}
