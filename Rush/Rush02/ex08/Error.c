/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:23:25 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/24 21:10:36 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

/* 空白判定（必要なら既存の場所に置いてOK） */
int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

/* 先頭の空白だけを飛ばす */
char	*ltrim_spaces(char *s)
{
	while (ft_isspace((unsigned char)*s))
		s++;
	return (s);
}

/* 1文字以上の完全数字かどうか */
int	is_all_digits(const char *s)
{
	int	i;

	if (*s == '\0')
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*
 * 先頭の '0' を飛ばす。ただし「全てが 0」の場合は '0' を1つだけ残す。
 * 例: "000123" -> "123",  "0000" -> "0"
 * 戻り値は元の文字列内のポインタ（argv文字列でも安全）。
 */
char	*zero_trim(char *s)
{
	char	*p;

	p = s;
	while (*p == '0')
		p++;
	if (p != s && *p == '\0')
	{
		return (p - 1);
	}
	if (*s == '\0')
		return (s);
	return (p);
}
