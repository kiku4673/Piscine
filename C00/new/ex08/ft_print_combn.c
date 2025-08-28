/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:59:59 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/28 17:34:33 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	print_comb(int *comb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(comb[i] + '0');
		i++;
	}
	if (comb[0] != 10 - n)
		write(1, ", ", 2);
}

void	generate(int n, int index, int start, int *comb)
{
	int	digit;

	if (index == n)
	{
		print_comb(comb, n);
		return ;
	}
	digit = start;
	while (digit <= 9)
	{
		comb[index] = digit;
		generate(n, index + 1, digit + 1, comb);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];

	if (n > 0 && n < 10)
		generate(n, 0, 0, comb);
}
