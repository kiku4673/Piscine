/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:23:25 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 23:25:18 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

char	*ltrim_spaces(char *s)
{
	while (ft_isspace((unsigned char)*s))
		s++;
	return (s);
}

int	is_all_digits(const char *s)
{
	int	i;

	if (*s == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

char	*zero_trim(char *s)
{
	char	*p;

	p = s;
	while (*p == '0')
		p++;
	if (p != s && *p == '\0')
	{
		return (p - 1);
	}
	if (*s == '\0')
		return (s);
	return (p);
}
