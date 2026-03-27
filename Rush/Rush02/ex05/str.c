/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:46:06 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 14:41:14 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

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

char	*ft_strtrim_alloc(char *s, int l, int r)
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
	int		l;
	int		r;
	int		n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	l = 0;
	r = n - 1;
	while (l < n && ft_is_space(s[l]))
		l++;
	while (r >= l && ft_is_space(s[r]))
		r--;
	return (ft_strtrim_alloc(s, l, r));
}
