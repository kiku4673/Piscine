/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:09:45 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/21 19:59:39 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int	len;
	int	i;

	len = 0;
	while (src[len])
		len++;
	str = malloc(len + 1);
	i = 0;
	while (i != len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
