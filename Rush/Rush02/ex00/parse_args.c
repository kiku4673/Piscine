/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:39:51 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 11:39:54 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// 入力: "  +00042  " → 出力: "42"
// 負号, 小数点, 非数字 → 0 を返して Error 扱い
int normalize_number(char *in, char **out){
    int i=0, has_digit=0;
    if(!in) return 0;
    // 前スペーススキップ
    while(in[i] && ft_is_space(in[i])) i++;
    // optional '+'
    if(in[i]=='+') i++;
    // 先頭ゼロ飛ばしつつ、数字以外チェック／小数点や'-'はアウト
    int start=i;
    while(in[i]){
        if (ft_is_space(in[i])) break;
        if (!ft_is_digit(in[i])) return 0;
        has_digit=1; i++;
    }
    // 後ろに空白があればOK（その後に文字があればNGにしたければ追加チェック）
    while(in[i]){
        if (!ft_is_space(in[i])) return 0;
        i++;
    }
    if(!has_digit){ *out = ft_strdup("0"); return (*out!=NULL); }

    // 先頭ゼロを削る
    int s=start; while(in[s]=='0') s++;
    if (!in[s]){ *out = ft_strdup("0"); return (*out!=NULL); }
    int len=0; while(in[s+len] && ft_is_digit(in[s+len])) len++;
    char *buf = malloc(len+1); if(!buf) return 0;
    for(int k=0;k<len;k++) buf[k]=in[s+k];
    buf[len]='\0';
    *out = buf;
    return 1;
}
