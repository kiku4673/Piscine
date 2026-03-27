/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:38:46 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:10:49 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_pair
{
	char	*key;
	char	*value;
}	t_pair;

typedef struct s_dict
{
	t_pair	*items;
	int		size;
}	t_dict

;

/* io_utils.c */
void	ft_putchar(char c);
void	ft_putstr(char *s);

/* str_utils.c */
int		ft_strlen(char *s);
int		ft_strcmp(char *a, char *b);
int		ft_strncmp(char *a, char *b, int n);
char	*ft_strdup(char *s);
char	*ft_strtrim(char *s);
int		ft_is_space(char c);
int		ft_is_digit(char c);

/* parse_args.c */
int		normalize_number(char *in, char **out);

/* dict_load.c */
int		load_dict(const char *path, t_dict *dict);
void	free_dict(t_dict *dict);

/* dict_query.c */
char	*dict_find(t_dict *dict, char *key);

/* convert.c */
int		number_to_words(t_dict *dict, char *num_str);

#endif