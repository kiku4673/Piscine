/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:27:47 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/25 17:27:52 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    char *arr[] = {"apple", "banana", "cherry"};
    char *res = ft_strjoin(3, arr, ", ");
    printf("%s\n", res); // apple, banana, cherry
    free(res);
}
