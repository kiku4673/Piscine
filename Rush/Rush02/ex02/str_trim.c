/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_trim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:41:55 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:55:19 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	find_left(char *s)
{
	int	l;

	l = 0;
	while (s[l] && ft_is_space(s[l]))
		l++;
	return (l);
}

static int	find_right(char *s, int l)
{
	int	r;

	r = ft_strlen(s) - 1;
	while (r >= l && ft_is_space(s[r]))
		r--;
	return (r);
}

static char	*dup_range(char *s, int l, int r)
{
	int		n;
	char	*o;
	int		i;

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

char	*ft_strtrim(char *s)
{
	int	l;
	int	r;

	if (!s)
		return (NULL);
	l = find_left(s);
	r = find_right(s, l);
	return (dup_range(s, l, r));
}
