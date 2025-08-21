/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:57:23 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/20 11:45:11 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;
	int	count;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	num = nb;
	count = 1;
	while (count != power)
	{
		num *= nb;
		count++;
	}
	return (num);
}
