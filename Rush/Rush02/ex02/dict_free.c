/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dect_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:03:47 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 15:03:55 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dict(t_dict *dict)
{
	int	i;

	if (!dict || !dict->items)
		return ;
	i = 0;
	while (i < dict->size)
	{
		free(dict->items[i].key);
		free(dict->items[i].value);
		i++;
	}
	free(dict->items);
	dict->items = NULL;
	dict->size = 0;
}
