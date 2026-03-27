/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:34:09 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 04:19:38 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rush02.h"


static int print_scale(char *scale, t_dict *dict, int *first)
{
t_dict_entry *e;


e = find_entry(dict, scale);
if (!e)
return (0);
if (!*first)
write(1, " ", 1);
ft_putstr(e->text);
*first = 0;
return (1);
}


static int convert_zero(t_dict *dict)
{
t_dict_entry *e;


e = find_entry(dict, "0");
if (!e)
return (0);
ft_putstr(e->text);
write(1, "\n", 1);
return (1);
}


static int process_one_group(char *num, t_dict *dict, int i, int *first)
{
char *group;
char *scale;


group = extract_group(num, i);
if (!group)
return (0);
if (!is_number_zero(group))
{
if (!process_group_for_conversion(group, dict, first))
return (free(group), 0);
if (i > 0)
{
scale = make_scale(i);
if (!scale || !print_scale(scale, dict, first))
return (free(group), free(scale), 0);
free(scale);
}
}
free(group);
return (1);
}


int convert_number(char *number_str, t_dict *dict)
{
int first;
int num_groups;
int i;


if (is_number_zero(number_str))
return (convert_zero(dict));
first = 1;
num_groups = (ft_strlen(number_str) + 2) / 3;
i = num_groups - 1;
while (i >= 0)
{
if (!process_one_group(number_str, dict, i, &first))
return (0);
i--;
}
write(1, "\n", 1);
return (1);
}