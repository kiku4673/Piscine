/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:39:48 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/20 18:39:17 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	is_prime;

	if (nb <= 2)
		return (2);
	while (1)
	{
		is_prime = 1;
		i = 2;
		while (i <= nb / i)
		{
			if (nb % i == 0)
			{
				is_prime = 0;
				break ;
			}
			i++;
		}
		if (is_prime)
			return (nb);
		nb++;
	}
}
