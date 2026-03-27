/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 04:16:34 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 04:30:56 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>


# define BUFFER_SIZE 1024
# define IS_SPACE(c) ((c) == ' ' || (c) == '\t')


typedef struct s_dict_entry
{
char *number_str;
char *text;
struct s_dict_entry *next;
}t_dict_entry;


typedef struct s_dict
{
t_dict_entry *entries;
}t_dict;


/* Main */
int parse_args(int argc, char **argv, char **dict_file, char **number_str);
int validate_input(char *number_str);
int process_conversion(char *dict_file, char *number_str);


/* String utilities */
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
char *ft_strdup(char *src);
char *ft_strcpy(char *dest, char *src);
void ft_putstr(char *str);


/* Dictionary utilities */
t_dict *load_dictionary(char *filename);
void free_dictionary(t_dict *dict);
t_dict_entry *find_entry(t_dict *dict, char *number_str);
int add_entry(t_dict *dict, char *number_str, char *text);
char *read_file(char *filename);
int parse_dictionary_line(char *line, t_dict *dict);


/* Number utilities */
int is_valid_number(char *str);
int is_number_zero(char *number);
int number_compare(char *num1, char *num2);
int number_length(char *number);


/* Group utils */
char *make_scale(int groups_from_right);
char *extract_group(char *number, int group_pos);


/* Number math */
char *number_divide_by_1000(char *number);
char *number_modulo_1000(char *number);


/* Number converter */
int convert_number(char *number_str, t_dict *dict);


/* Number processing */
int process_group_for_conversion(char *group, t_dict *dict, int *first);


#endif