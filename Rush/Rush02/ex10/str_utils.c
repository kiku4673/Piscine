/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:39:39 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 22:32:12 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strcmp(const char *a, const char *b)
{
	int	i;

	i = 0;
	if (!a || !b)
		return (a != b);
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return ((int)((unsigned char)a[i] - (unsigned char)b[i]));
}

int	ft_strncmp(const char *a, const char *b, int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i < n - 1 && a[i] && b[i] && a[i] == b[i])
		i++;
	return ((int)((unsigned char)a[i] - (unsigned char)b[i]));
}
