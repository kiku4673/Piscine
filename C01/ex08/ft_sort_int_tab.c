/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:34:38 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/12 15:53:51 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// i : for order
// j : For size comparison
// temp : For holding [j]

void	ft_sort_int_tab(int	*tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;

	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
