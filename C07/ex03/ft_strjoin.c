/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:59:20 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/26 17:13:03 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	clac_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	return (len + ft_strlen(sep) * (size - 1));
}

static void	fill_str(char *dest, int size, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i++ < size - 1)
			ft_strcat(dest, sep);
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		len;

	if (size == 0)
	{
		s = malloc(1);
		if (s == NULL)
			return (NULL);
		s[0] = '\0';
		return (s);
	}
	len = clac_len(size, strs, sep);
	s = malloc(len + 1);
	if (s == NULL)
		return (NULL);
	s[0] = '\0';
	fill_str(s, size, strs, sep);
	return (s);
}
