/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main08.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:32:21 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/28 17:32:43 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);

int	main(void)
{
	ft_print_combn(2);
	write(1, "\n", 1);
	ft_print_combn(3);
	write(1, "\n", 1);
	ft_print_combn(9);
	write(1, "\n", 1);
	return (0);
}
