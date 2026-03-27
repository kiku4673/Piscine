/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:33:20 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 04:17:53 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rush02.h"


static char *substr_dup(char *src, int start, int len)
{
char *res;
int i;


res = (char *)malloc(len + 1);
if (!res)
return (NULL);
i = 0;
while (i < len)
{
res[i] = src[start + i];
i++;
}
res[i] = '\0';
return (res);
}


char *number_divide_by_1000(char *number)
{
int len;
int new_len;


len = ft_strlen(number);
if (len <= 3)
return (ft_strdup("0"));
new_len = len - 3;
return (substr_dup(number, 0, new_len));
}


char *number_modulo_1000(char *number)
{
int len;
int start;


len = ft_strlen(number);
if (len <= 3)
return (ft_strdup(number));
start = len - 3;
while (start < len && number[start] == '0')
start++;
if (start == len)
return (ft_strdup("0"));
return (substr_dup(number, start, len - start));
}
#include "rush02.h"

char	*number_divide_by_1000(char *number)
{
	int		len = ft_strlen(number);
	int		new_len;
	char	*result;
	int		i;

	if (len <= 3)
	{
		result = malloc(2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	new_len = len - 3;
	result = malloc(new_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		result[i] = number[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*number_modulo_1000(char *number)
{
	int		len = ft_strlen(number);
	int		start;
	int		result_len;
	char	*result;
	int		i;
	
	if (len <= 3)
		return (ft_strdup(number));
	start = len - 3;
	while (start < len && number[start] == '0')
		start++;
	if (start == len)
	{
		result = malloc(2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	result_len = len - start;
	result = malloc(result_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (start < len)
	{
		result[i] = number[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}