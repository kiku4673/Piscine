/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:09:42 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:09:45 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rush02.h"

static void	print_error(void)
{
	ft_putstr("Error\n");
}

static void	print_dict_error(void)
{
	ft_putstr("Dict Error\n");
}

int	main(int argc, char **argv)
{
	char	*num;
	char	*dict_path;
	t_dict	dict;

	num = NULL;
	dict_path = "numbers.dict";
	if (argc == 2)
	{
		if (!normalize_number(argv[1], &num))
			return (print_error(), 0);
	}
	else if (argc == 3)
	{
		dict_path = argv[1];
		if (!normalize_number(argv[2], &num))
			return (print_error(), 0);
	}
	else
		return (print_error(), 0);
	if (!load_dict(dict_path, &dict))
		return (print_dict_error(), free(num), 0);
	if (!number_to_words(&dict, num))
		return (print_dict_error(), free_dict(&dict), free(num), 0);
	ft_putchar('\n');
	free_dict(&dict);
	free(num);
	return (0);
}