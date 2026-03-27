/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:41:41 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:41:45 by kyamanak         ###   ########.fr       */
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
