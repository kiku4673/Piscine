/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:38:30 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/27 20:20:23 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void ft_show_tab(struct s_stock_str *par);

struct s_stock_str *ft_strs_to_tab(int ac, char **av);

int main(int argc, char **argv)
{
    t_stock_str *tab;
	
    tab = ft_strs_to_tab(argc - 1, argv + 1);

    if (!tab)
        return (1);

    ft_show_tab(tab);

    return (0);
}
