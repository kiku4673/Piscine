/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:31:36 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 04:17:33 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rush02.h"


int ft_strlen(char *str)
{
int len;


len = 0;
while (str[len])
len++;
return (len);
}


int ft_strcmp(char *s1, char *s2)
{
int i;


i = 0;
while (s1[i] && s2[i] && s1[i] == s2[i])
i++;
return (s1[i] - s2[i]);
}


char *ft_strdup(char *src)
{
char *dup;
int len;
int i;


len = ft_strlen(src);
dup = (char *)malloc(len + 1);
if (!dup)
return (NULL);
i = 0;
while (i < len)
{
dup[i] = src[i];
i++;
}
dup[i] = '\0';
return (dup);
}


char *ft_strcpy(char *dest, char *src)
{
int i;


i = 0;
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}


void ft_putstr(char *str)
{
write(1, str, ft_strlen(str));
}