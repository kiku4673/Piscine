/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:40:56 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/07 17:38:17 by kyamanak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <unistd.h>

void ft_print_number(void)
{
    char number;

    // '0' から '9'　までループを回す
    number = '0';
    while (number <= '9')
    {
        write(1, &number, 1);

        number++;
    }
}

int main(void)
{
    ft_print_number();
}