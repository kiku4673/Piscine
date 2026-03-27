/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:33:48 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 04:18:36 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rush02.h"


static void print_with_space(char *text, int *first)
{
if (!*first)
write(1, " ", 1);
ft_putstr(text);
*first = 0;
}


static int convert_unit_char(char c, t_dict *d, int *first)
{
char u[2];
t_dict_entry *e;


u[0] = c;
u[1] = '\0';
e = find_entry(d, u);
if (!e)
return (0);
print_with_space(e->text, first);
return (1);
}


static int convert_len2(char *g, t_dict *d, int *first)
{
char tu[3];
t_dict_entry *e;


if (g[0] == '1' || g[1] == '0')
{
e = find_entry(d, g);
if (!e)
return (0);
print_with_space(e->text, first);
return (1);
}
tu[0] = g[0];
tu[1] = '0';
tu[2] = '\0';
e = find_entry(d, tu);
if (!e)
return (0);
print_with_space(e->text, first);
return (convert_unit_char(g[1], d, first));
}


static int convert_len3(char *g, t_dict *d, int *first)
{
t_dict_entry *e;


if (g[0] != '0')
{
if (!convert_unit_char(g[0], d, first))
return (0);
e = find_entry(d, "100");
if (!e)
return (0);
print_with_space(e->text, first);
}
if (g[1] != '0' || g[2] != '0')
return (convert_len2(g + 1, d, first));
return (1);
}


int process_group_for_conversion(char *group, t_dict *dict, int *first)
{
int len;


if (is_number_zero(group))
return (1);
len = ft_strlen(group);
if (len == 1)
return (convert_unit_char(group[0], dict, first));
if (len == 2)
return (convert_len2(group, dict, first));
return (convert_len3(group, dict, first));
}
