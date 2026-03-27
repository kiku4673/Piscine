/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:32:02 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 03:32:16 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (str[0] == '0' && str[1])
		return (0);
	return (1);
}

int	is_number_zero(char *number)
{
	int	i;

	if (!number || !number[0])
		return (0);
	i = 0;
	while (number[i] == '0' && number[i])
		i++;
	return (number[i] == '\0');
}

int	number_length(char *number)
{
	return (ft_strlen(number));
}

int	number_compare(char *num1, char *num2)
{
	int	len1;
	int	len2;

	len1 = number_length(num1);
	len2 = number_length(num2);
	if (len1 < len2)
		return (-1);
	if (len1 > len2)
		return (1);
	return (ft_strcmp(num1, num2));
}
