/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:34:06 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/27 20:19:00 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

struct s_stock_str *ft_strs_to_tab(int ac, char **av);

typedef struct s_stock_str
{
    int		size;
    char	*str;
    char	*copy;
} t_stock_str;

#endif
