/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_com2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:25:11 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/09 15:07:52 by kyamanak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include <unistd.h>

void	ft_print_comb(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnums(int a, int b)
{
	ft_putchar('0' + a / 10);
	ft_putchar('0' + a % 10);
	ft_putchar(' ');
	ft_putchar('0' + b / 10);
	ft_putchar('0' + b % 10);
}

void	ft_putcomma(void)
{
	ft_putchar(',');
	ft_putchar(' ');
}

void	ft_print_comb(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 99)
	{
		j = i;
		while (++j < 100)
		{
			ft_putnums(i, j);
			if (i != 98 || j != 99)
			{
				ft_putcomma();
			}
		}
	}
}

int	main(void)
{
	ft_print_comb();
}
