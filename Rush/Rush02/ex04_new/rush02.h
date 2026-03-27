/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:38:46 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 16:16:16 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_seginfo
{
	char	*blob;
	int		start;
	int		end;
}	t_seginfo;

typedef struct s_pair
{
	char	*key;
	char	*value;
}	t_pair;

typedef struct s_readctx
{
	int		fd;
	int		n;
	int		total;
	char	buf[4096];
	char	*acc;
	char	z;
}	t_readctx;

typedef struct s_dict
{
	t_pair	*items;
	int		size;
}	t_dict;

typedef struct s_block
{
	t_dict	*dict;
	char	*tail;
	int		pos;
	int		take;
	int		*need_sp;
}	t_block;

/* convert.c */
int			number_to_words(t_dict *dict, char *num_str);

int			process_block(t_block *blk);
int			process_tail_blocks(t_dict *dict, char *tail, int *need_sp);

int			split_head_tail(char *num_str, char *scale,
				char **head, char **tail);
int			process_tail_if_needed(t_dict *dict, char *tail, int *need_sp);
int			process_scale(t_dict *dict, char *num_str,
				char *scale, int *need_sp);

int			str_to_int_safe(char *s, int *out);
int			cmp_numstr_len(char *a, char *b);
void		int_to_key(int n, char *dst);

int			say_0_99(t_dict *d, int n, int *need_sp);
int			say_0_999(t_dict *d, int n, int *need_sp);
int			put_word(t_dict *d, char *key, int *need_sp);

const char	**get_scales(void);

/* io_utils.c */
void		ft_putchar(char c);
void		ft_putstr(char *s);
char		*ft_strncpy(char *dest, const char *src, unsigned int n);
char		*ft_strcpy(char *dest, const char *src);

/* str_utils.c */
int			ft_strlen(char *s);
int			ft_strcmp(char *a, char *b);
int			ft_strncmp(char *a, char *b, int n);
char		*ft_strdup(char *s);
char		*ft_strtrim_alloc(char *s, int l, int r);
char		*ft_strtrim(char *s);
int			ft_is_space(char c);
int			ft_is_digit(char c);

/* parse_args.c */
int			normalize_number(char *in, char **out);

/* dict_load.c */
int			load_dict(const char *path, t_dict *dict);

void		free_pairs(t_pair *arr, int n);
char		*dup_slice(const char *s, int start, int end);
int			process_nonempty_line(char *line, t_pair *slot);
int			handle_segment(t_seginfo info, t_pair *arr, int *idx);

int			parse_line(char *line, t_pair *out);

/* dict_query.c */
int			skip_space(char *str, int i);
void		free_dict(t_dict *dict);
char		*dict_find(t_dict *dict, char *key);

char		*read_all_text(const char *path, int *out_len);
int			count_lines(char *s, int n);

#endif