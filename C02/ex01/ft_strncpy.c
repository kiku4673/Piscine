/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:57:48 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/13 14:42:07 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;
	int	iPos = 0;

	i = 0;
// 	while (src[i] != '\0' && i < n)
	while (i < n)
	{
		if (src[i] == '\0') iPos = i;
		dest[i] = src[i];
		i++;
	}
	if (iPos != 0)
	{
		dest[i] = '\0';
	}
	return (dest);
}
