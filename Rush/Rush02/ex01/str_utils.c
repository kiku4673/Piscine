/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:39:39 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:12:17 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *s)
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

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	if (!a || !b)
		return (a != b);
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return ((int)((unsigned char)a[i] - (unsigned char)b[i]));
}

int	ft_strncmp(char *a, char *b, int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (i < n - 1 && a[i] && b[i] && a[i] == b[i])
		i++;
	return ((int)((unsigned char)a[i] - (unsigned char)b[i]));
}

char	*ft_strdup(char *s)
{
	int		n;
	char	*p;
	int		i;

	n = ft_strlen(s);
	p = (char *)malloc((size_t)n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[n] = '\0';
	return (p);
}

char	*ft_strtrim(char *s)
{
	int		l;
	int		r;
	int		n;
	char	*o;
	int		i;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	l = 0;
	r = n - 1;
	while (l < n && ft_is_space(s[l]))
		l++;
	while (r >= l && ft_is_space(s[r]))
		r--;
	n = 0;
	if (r >= l)
		n = r - l + 1;
	o = (char *)malloc((size_t)n + 1);
	if (!o)
		return (NULL);
	i = 0;
	while (i < n)
	{
		o[i] = s[l + i];
		i++;
	}
	o[n] = '\0';
	return (o);
}