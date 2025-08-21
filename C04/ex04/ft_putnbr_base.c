/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 19:35:59 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/19 21:33:56 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	putnbr_recursive(long nbr, char *base, int base_len)
{
	char	c;

	if (nbr >= base_len)
		putnbr_recursive(nbr / base_len, base, base_len);
	c = base[nbr % base_len];
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	n;

	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	putnbr_recursive(n, base, base_len);
}
