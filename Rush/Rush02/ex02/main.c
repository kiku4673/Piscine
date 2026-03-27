/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:09:42 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:53:15 by kyamanak         ###   ########.fr       */
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

static int	parse_cli(int argc, char **argv, char **dict_path, char **num)
{
	if (argc == 2)
	{
		*dict_path = (char *)"numbers.dict";
		if (!normalize_number(argv[1], num))
			return (0);
		return (1);
	}
	if (argc == 3)
	{
		*dict_path = argv[1];
		if (!normalize_number(argv[2], num))
			return (0);
		return (1);
	}
	return (0);
}

static int	run_convert(char *dict_path, char *num)
{
	t_dict	dict;
	int		ok;

	ok = load_dict(dict_path, &dict);
	if (!ok)
		return (print_dict_error(), 0);
	ok = number_to_words(&dict, num);
	if (!ok)
	{
		print_dict_error();
		free_dict(&dict);
		return (0);
	}
	ft_putchar('\n');
	free_dict(&dict);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*num;
	char	*dict_path;

	num = NULL;
	dict_path = NULL;
	if (!parse_cli(argc, argv, &dict_path, &num))
		return (print_error(), 0);
	if (!run_convert(dict_path, num))
		return (free(num), 0);
	free(num);
	return (0);
}
