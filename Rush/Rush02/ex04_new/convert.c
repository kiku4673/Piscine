/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:02:49 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 20:21:33 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdlib.h>

/* ------------------------ 補助関数 ------------------------ */

static int	check_direct(t_dict *dict, char *num_str, int *need_sp)
{
	if (ft_strcmp(num_str, "0") == 0)
		return (put_word(dict, "0", &(int){0}));
	if (dict_find(dict, num_str))
		return (put_word(dict, num_str, need_sp));
	return (-1);
}

/* ------------------------ メイン関数 ------------------------ */
// 1
int	number_to_words(t_dict *dict, char *num_str)
{
	int			need_sp;
	int			i;
	int			h;
	int			dummy;
	const char	**scales;

	need_sp = 0;
	i = 0;
	dummy = 0;
	scales = get_scales();
	if (check_direct(dict, num_str, &need_sp) != -1)
		return (1);
	while (scales[i])
	{
		if (cmp_numstr_len(num_str, (char *)scales[i]) >= 0)
			return (process_scale(dict, num_str, (char *)scales[i], &need_sp));
		i++;
	}
	if (ft_strlen(num_str) > 9 || !str_to_int_safe(num_str, &h))
		return (0);
	return (say_0_999(dict, h, &dummy));
}
