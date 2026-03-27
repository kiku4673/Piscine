/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:47:29 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:47:39 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	put_word(t_dict *d, char *key, int *need_sp)
{
	char	*w;

	w = dict_find(d, key);
	if (!w)
		return (0);
	if (*need_sp)
		ft_putchar(' ');
	ft_putstr(w);
	*need_sp = 1;
	return (1);
}
