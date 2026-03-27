/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 12:02:49 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 23:24:40 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	check_direct(t_dict *dict, char *num_str, int *need_sp)
{
	if (ft_strcmp(num_str, "0") == 0)
		return (put_word(dict, "0", &(int){0}));
	if (dict_find(dict, num_str))
		return (put_word(dict, num_str, need_sp));
	return (-1);
}

static int	is_exact_scale_or_100(char *s)
{
	const char	**sc;
	int			i;

	if (ft_strcmp(s, "100") == 0)
		return (1);
	sc = get_scales();
	i = 0;
	while (sc[i])
	{
		if (ft_strcmp(s, sc[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int	precheck_and_normalize(char **pnum)
{
	*pnum = ltrim_spaces(*pnum);
	if (**pnum == '\0' || !is_all_digits(*pnum))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	*pnum = zero_trim(*pnum);
	if (**pnum == '\0')
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

static int	try_scales(t_dict *dict, char *num_str, int *need_sp)
{
	const char	**scales;
	int			i;

	scales = get_scales();
	i = 0;
	while (scales[i])
	{
		if (cmp_numstr_len(num_str, (char *)scales[i]) >= 0)
			return (process_scale(dict, num_str, (char *)scales[i], need_sp));
		i++;
	}
	return (-1);
}

int	number_to_words(t_dict *dict, char *num_str)
{
	int		need_sp;
	int		h;
	int		dummy;
	int		sret;

	if (!precheck_and_normalize(&num_str))
		return (0);
	need_sp = 0;
	dummy = 0;
	if (!is_exact_scale_or_100(num_str)
		&& check_direct(dict, num_str, &need_sp) != -1)
		return (1);
	sret = try_scales(dict, num_str, &need_sp);
	if (sret == 0)
		return (0);
	if (sret == 1)
		return (1);
	if (ft_strlen(num_str) > 9 || !str_to_int_safe(num_str, &h))
		return (0);
	return (say_0_999(dict, h, &dummy));
}
