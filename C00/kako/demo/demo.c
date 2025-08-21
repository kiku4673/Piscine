/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <kyamanak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 09:53:32 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/07 13:02:54 by kyamanak         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

int function_1(int variable_1, int variable_2)
{
    int variable_3 = variable_1 + variable_2;
    return (variable_3);
}



/*
    THE PROGRAM ALWAYS STARTS WITH MAIN FUNCTION
*/
int main(void)
{
    int a;
    int b;

    b = 5;
    a = function_1(b,2);

    return (0);
}