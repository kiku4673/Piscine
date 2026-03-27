/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:40:18 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:39:54 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*dict_find(t_dict *dict, char *key)
{
	int	i;

	i = 0;
	while (i < dict->size)
	{
		if (ft_strcmp(dict->items[i].key, key) == 0)
			return (dict->items[i].value);
		i++;
	}
	return (NULL);
}
