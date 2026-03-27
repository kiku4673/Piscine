/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:05:09 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/07 13:12:33 by kyamanak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

int calculus_and_return(int a, int b)
{
    return (a + b);
}

void    assignment(void)
{
    int     a;
    int     b;
    char    c;

    a = 44;
    b = -2;
    c = 'A';

    {
        a = calculus_and_return(a, b);
        b = (a - 2) * 2;
    }
}

void call_function(void)
{
    int      forty_two;

    forty_two = 42;
}