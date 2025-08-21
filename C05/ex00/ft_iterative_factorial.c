/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:41:28 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/20 10:31:15 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	num;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	num = 1;
	while (nb > 1)
	{
		num *= nb;
		nb--;
	}
	return (num);
}
