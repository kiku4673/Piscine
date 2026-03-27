/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_len_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:41:09 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:41:21 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	if (!a || !b)
		return (a != b);
	i = 0;
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
