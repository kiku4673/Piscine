/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:27:03 by hikari            #+#    #+#             */
/*   Updated: 2025/08/24 13:55:29 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*append_buffer(char *acc, int total, char *buf, int n)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(total + n);
	if (!(tmp))
		return (NULL);
	i = 0;
	while (i < total)
	{
		tmp[i] = acc[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		tmp[total + i] = buf[i];
		i++;
	}
	free (acc);
	return (tmp);
}

static int	append_chunk(char **pacc, int *ptotal, char *buf, int n)
{
	char	*tmp;

	tmp = append_buffer(*pacc, *ptotal, buf, n);
	if (!tmp)
		return (0);
	*pacc = tmp;
	*ptotal += n;
	return (1);
}

static int	accumulate_buffer(t_readctx *ctx)
{
	ctx->n = read(ctx->fd, ctx->buf, sizeof(ctx->buf));
	while (ctx->n > 0)
	{
		if (!append_chunk(&ctx->acc, &ctx->total, ctx->buf, ctx->n))
			return (0);
		ctx->n = read(ctx->fd, ctx->buf, sizeof(ctx->buf));
	}
	return (ctx->n >= 0);
}

char	*read_all_text(const char *path, int *out_len)
{
	t_readctx	ctx;

	ctx.fd = open(path, O_RDONLY);
	if (ctx.fd < 0)
		return (NULL);
	ctx.acc = NULL;
	ctx.total = 0;
	if (!accumulate_buffer(&ctx))
		return (free(ctx.acc), close(ctx.fd), NULL);
	close(ctx.fd);
	if (ctx.total == 0)
		return (NULL);
	ctx.z = '\0';
	ctx.acc = append_buffer(ctx.acc, ctx.total, &ctx.z, 1);
	if (!ctx.acc)
		return (NULL);
	*out_len = ctx.total;
	return (ctx.acc);
}

int	count_lines(char *s, int n)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < n)
	{
		if (s[i] == '\n')
			c++;
		i++;
	}
	return (c + 1);
}
