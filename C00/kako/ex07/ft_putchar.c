/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:03:06 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/10 12:14:36 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		(nb = nb * -);
	}
	ft_putchar('0' + nb / 10);
	ft_putchar('0' + nb % 10);
}

// int	main(void)
// {
// 	ft_putnbr(42);
// }
