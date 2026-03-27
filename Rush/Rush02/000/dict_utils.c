/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 03:34:52 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 04:22:58 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict_entry	*find_entry(t_dict *dict, char *number_str)
{
	t_dict_entry	*cur;

	cur = dict->entries;
	while (cur)
	{
		if (ft_strcmp(cur->number_str, number_str) == 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

int	add_entry(t_dict *dict, char *number_str, char *text)
{
	t_dict_entry	*new_e;
	t_dict_entry	*cur;

	new_e = (t_dict_entry *)malloc(sizeof(t_dict_entry));
	if (!new_e)
		return (0);
	new_e->number_str = ft_strdup(number_str);
	new_e->text = ft_strdup(text);
	new_e->next = NULL;
	if (!new_e->number_str || !new_e->text)
	{
		if (new_e->number_str)
			free(new_e->number_str);
		if (new_e->text)
			free(new_e->text);
		free(new_e);
		return (0);
	}
	if (!dict->entries)
	{
		dict->entries = new_e;
		return (1);
	}
	cur = dict->entries;
	while (cur->next)
		cur = cur->next;
	cur->next = new_e;
	return (1);
}

void	free_dictionary(t_dict *dict)
{
	t_dict_entry	*cur;
	t_dict_entry	*nxt;

	if (!dict)
		return ;
	cur = dict->entries;
	while (cur)
	{
		nxt = cur->next;
		if (cur->number_str)
			free(cur->number_str);
		if (cur->text)
			free(cur->text);
		free(cur);
		cur = nxt;
	}
	free(dict);
}

static char	*append_block(char *content, int *total, char *buf, int n)
{
	char	*newc;
	int		i;
	int		old;

	old = *total - 1;
	newc = (char *)malloc(old + n + 1);
	if (!newc)
		return (NULL);
	i = 0;
	while (i < old)
	{
		newc[i] = content[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		newc[old + i] = buf[i];
		i++;
	}
	newc[old + n] = '\0';
	*total = old + n + 1;
	free(content);
	return (newc);
}

char	*read_file(char *filename)
{
	int		fd;
	char	*buf;
	char	*content;
	int		bytes;
	int		total;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE);
	content = (char *)malloc(1);
	if (!buf || !content)
		return (close(fd), NULL);
	content[0] = '\0';
	total = 1;
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		content = append_block(content, &total, buf, bytes);
		if (!content)
			return (close(fd), free(buf), NULL), (char *)NULL;
	}
	close(fd);
	free(buf);
	return (content);
}