/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:29:14 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 03:31:18 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse_args(int argc, char **argv, char **dict_file, char **number_str)
{
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
	{
		*dict_file = "numbers.dict";
		*number_str = argv[1];
	}
	else
	{
		*dict_file = argv[1];
		*number_str = argv[2];
	}
	return (1);
}

int	validate_input(char *number_str)
{
	if (!is_valid_number(number_str))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	process_conversion(char *dict_file, char *number_str)
{
	t_dict	*dict;

	dict = load_dictionary(dict_file);
	if (!dict)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	if (!convert_number(number_str, dict))
	{
		write(1, "Dict Error\n", 11);
		free_dictionary(dict);
		return (0);
	}
	free_dictionary(dict);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*dict_file;
	char	*number_str;

	if (!parse_args(argc, argv, &dict_file, &number_str))
		return (1);
	if (!validate_input(number_str))
		return (1);
	if (!process_conversion(dict_file, number_str))
		return (1);
	return (0);
}