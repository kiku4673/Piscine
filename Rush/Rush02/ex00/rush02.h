/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:38:46 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 11:38:49 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// rush02.h
#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pair {
    char *key;    // "0", "1", "20", "1000" など数値の文字列（先頭ゼロなし）
    char *value;  // "zero", "one", "twenty", "thousand" など
} t_pair;

typedef struct s_dict {
    t_pair *items;
    int     size;   // 有効件数
} t_dict;

/* io_utils.c */
void    ft_putchar(char c);
void    ft_putstr(char *s);

/* str_utils.c */
int     ft_strlen(char *s);
int     ft_strcmp(char *a, char *b);
int     ft_strncmp(char *a, char *b, int n);
char    *ft_strdup(char *s);
char    *ft_strtrim(char *s);             // 前後スペース削除（中は触らない）
int     ft_is_space(char c);
int     ft_is_digit(char c);

/* parse_args.c */
int     normalize_number(char *in, char **out); 
// OK: *out に正規化済み数字（先頭ゼロ整理、空なら"0"）/ NG: 0

/* dict_load.c */
int     load_dict(const char *path, t_dict *dict); // OK:1 NG:0
void    free_dict(t_dict *dict);

/* dict_query.c */
char    *dict_find(t_dict *dict, char *key); // 値(借用) or NULL

/* convert.c */
int     number_to_words(t_dict *dict, char *num_str); // OK:1 NG:0 （書き出しまでやる）

#endif
