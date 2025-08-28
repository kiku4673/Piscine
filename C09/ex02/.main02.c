/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:53:00 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/28 14:54:00 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *str, char *charset);

int main(void)
{
    char str[] = "Hello,,world!This,is,a,test";
    char charset[] = ",!";
    char **res;
    int i;

    res = ft_split(str, charset);
    if (!res)
    {
        printf("malloc failed\n");
        return (1);
    }

    i = 0;
    while (res[i])
    {
        printf("%s\n", res[i]);
        free(res[i]);
        i++;
    }
    free(res);
    return (0);
}
