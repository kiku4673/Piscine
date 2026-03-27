/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:40:37 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 11:40:39 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void print_error(void){ ft_putstr("Error\n"); }
static void print_dict_error(void){ ft_putstr("Dict Error\n"); }

int main(int argc, char **argv){
    char  *num = NULL;
    char  *dict_path = "numbers.dict"; // デフォルト（評価環境のパスに合わせて調整可）
    t_dict dict;

    if (argc==2){
        if (!normalize_number(argv[1], &num)){ print_error(); return 0; }
    } else if (argc==3){
        dict_path = argv[1];
        if (!normalize_number(argv[2], &num)){ print_error(); return 0; }
    } else {
        print_error(); return 0;
    }

    if (!load_dict(dict_path, &dict)){ print_dict_error(); free(num); return 0; }

    if (!number_to_words(&dict, num)){ print_dict_error(); free_dict(&dict); free(num); return 0; }

    ft_putchar('\n');
    free_dict(&dict);
    free(num);
    return 0;
}
