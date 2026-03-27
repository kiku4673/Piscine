/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 04:19:05 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 04:19:14 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "rush02.h"


char *make_scale(int groups_from_right)
{
int zeros;
char *res;
int i;


zeros = groups_from_right * 3;
res = (char *)malloc(zeros + 2);
if (!res)
return (NULL);
res[0] = '1';
i = 0;
while (i < zeros)
{
res[i + 1] = '0';
i++;
}
res[zeros + 1] = '\0';
return (res);
}


char *extract_group(char *number, int group_pos)
{
int len;
int start;
int glen;
char *grp;
int i;


len = ft_strlen(number);
if (group_pos * 3 >= len)
return (NULL);
start = len - (group_pos + 1) * 3;
if (start < 0)
{
start = 0;
glen = len - group_pos * 3;
}
else
glen = 3;
grp = (char *)malloc(glen + 1);
if (!grp)
return (NULL);
i = 0;
while (i < glen)
{
grp[i] = number[start + i];
i++;
}
grp[i] = '\0';
return (grp);
}