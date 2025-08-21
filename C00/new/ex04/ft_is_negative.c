/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:27:29 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/10 10:04:15 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
}

// int	main(void)
// {
// 	ft_is_negative(-5);
// 	write(1, "\n", 1);
// 	ft_is_negative(0);
// 	write(1, "\n", 1);
// 	ft_is_negative(7);
// 	write(1, "\n", 1);
// }
