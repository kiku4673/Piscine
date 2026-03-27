/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:45:17 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/10 15:04:19 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

// void main(void)
// {
// 	ft_putchar('9');
// }

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnums(int a, int b, int c)
{
	ft_putchar('0' + a);
	ft_putchar('0' + b);
	ft_putchar('0' + c);
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
	int	k;

	i = -1;
	while (++i < 10)
	{
		j = i;
		while (++j < 10)
		{
			k = j;
			while (++k < 10)
			{
				ft_putnums(i, j, k);
				if (i != 7 || j != 8 || k != 9)
				{
					ft_putcomma();
				}
			}
		}
	}
}

int	main(void)
{
	ft_print_comb();
}
