/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:38:46 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 15:07:49 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* dict types */
typedef struct s_pair
{
	char	*key;
	char	*value;
}	t_pair;

typedef struct s_dict
{
	t_pair	*items;
	int		size;
}	t_dict;

/* io_utils.c */
void	ft_putchar(char c);
void	ft_putstr(char *s);

/* str_len_cmp.c */
int		ft_strlen(char *s);
int		ft_strcmp(char *a, char *b);
int		ft_strncmp(char *a, char *b, int n);

/* str_mem.c */
char	*ft_strdup(char *s);

/* str_trim.c */
char	*ft_strtrim(char *s);

/* char_utils.c */
int		ft_is_space(char c);
int		ft_is_digit(char c);

/* parse_args.c */
int		normalize_number(char *in, char **out);

/* file_read.c */
char	*read_all_file(const char *path, int *out_len);

/* dict_parse.c */
int		parse_dict_line(char *line, t_pair *out);

/* dict_load.c */
int		load_dict(const char *path, t_dict *dict);
void	free_dict(t_dict *dict);

/* dict_query.c */
char	*dict_find(t_dict *dict, char *key);

/* convert_small.c */
int		say_0_99(t_dict *d, int n, int *need_sp);
int		say_0_999(t_dict *d, int n, int *need_sp);
void	int_to_key(int n, char *dst);

/* print_word.c */
int		put_word(t_dict *d, char *key, int *need_sp);

/* dict_kv.c */
char	*dup_key_trim_zero(char *line, int l, int r);
char	*dup_trim_right(char *line, int pos);

/* num_utils.c */
int		cmp_numstr_len(char *a, char *b);
int		str_to_int_safe(char *s, int *out);

/* convert_split.c */
int		split_head_tail(char *num, char *scale, char **head, char **tail);

/* convert_tail.c */
int		say_head_and_scale(t_dict *d, char *head, char *scale, int *need_sp);
int		say_tail_if_needed(t_dict *d, char *tail, int *need_sp);

/* dict_free.c */
void	free_dict(t_dict *dict);

/* convert_big.c */
int		number_to_words(t_dict *dict, char *num_str);

#endif
