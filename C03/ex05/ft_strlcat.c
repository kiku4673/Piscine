/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:43:47 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/18 17:24:25 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

unsigned int	ft_strlen(char *s)
{
	unsigned int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	max_copy;
	unsigned int	i;

	d_len = ft_strlen(dest);
	if (src == NULL)
		return (d_len);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (size + s_len);
	max_copy = size - d_len - 1;
	i = 0;
	while (i < max_copy && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[i + d_len] = '\0';
	return (s_len + d_len);
}
