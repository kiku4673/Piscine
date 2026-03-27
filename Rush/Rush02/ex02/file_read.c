/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 14:38:29 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 14:54:00 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	append_chunk(char **acc, int *total, char *src, int n)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc((size_t)(*total + n));
	if (!tmp)
		return (0);
	i = 0;
	while (i < *total)
	{
		if (*acc)
			tmp[i] = (*acc)[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp[*total + i] = src[i];
		i++;
	}
	free(*acc);
	*acc = tmp;
	*total = *total + n;
	return (1);
}

char	*read_all_file(const char *path, int *out_len)
{
	int		fd;
	char	buf[4096];
	char	*acc;
	int		n;
	int		total;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	acc = NULL;
	total = 0;
	n = read(fd, buf, 4096);
	while (n > 0)
	{
		if (!append_chunk(&acc, &total, buf, n))
			return (close(fd), free(acc), NULL);
		n = read(fd, buf, 4096);
	}
	close(fd);
	*out_len = total;
	return (acc);
}
