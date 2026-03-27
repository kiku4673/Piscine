/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:40:08 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 11:40:10 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// ざっくり手順：ファイル全部読み→行ごと解析→ key/value を trim → 保存
// エラーがあれば 0 を返して "Dict Error" に繋げる

static char *read_all(const char *path, int *out_len){
    int fd = open(path, O_RDONLY);
    char buf[4096];
    char *acc = NULL; int total=0; int n;
    if (fd<0) return NULL;
    while ((n = read(fd, buf, 4096)) > 0){
        char *tmp = malloc(total + n);
        if (!tmp){ free(acc); close(fd); return NULL; }
        for(int i=0;i<total;i++) tmp[i]=acc?acc[i]:0; // accがNULLのときの0コピーは無意味だが簡略
        for(int i=0;i<n;i++) tmp[total+i]=buf[i];
        free(acc); acc=tmp; total+=n;
    }
    close(fd);
    *out_len=total;
    return acc;
}

static int count_lines(char *s, int n){
    int c=0; for(int i=0;i<n;i++) if(s[i]=='\n') c++; return c+1;
}

static int parse_line(char *line, t_pair *out){
    // 形式: number [spaces] : [spaces] value
    int i=0;
    while (ft_is_space(line[i])) i++;      // 行頭空白許可
    int k0=i;
    if(!line[i]) return 0;
    // number (数字のみ)
    while(line[i] && ft_is_digit(line[i])) i++;
    if (i==k0) return 0; // 数字ゼロ文字はNG
    // number 抽出（先頭ゼロ正規化）
    int s=k0; while(s<i-1 && line[s]=='0') s++;
    char *key = malloc(i-s+1); if(!key) return 0;
    for(int j=0;j<i-s;j++) key[j]=line[s+j]; key[i-s]='\0';

    while(ft_is_space(line[i])) i++;
    if(line[i] != ':'){ free(key); return 0; }
    i++;
    while(ft_is_space(line[i])) i++;
    // value = 残りをtrim
    char *val_raw = ft_strdup(&line[i]);
    if(!val_raw){ free(key); return 0; }
    char *val = ft_strtrim(val_raw);
    free(val_raw);
    if(!val){ free(key); return 0; }
    out->key = key; out->value = val;
    return 1;
}

int load_dict(const char *path, t_dict *dict){
    int len=0; char *blob = read_all(path, &len);
    if(!blob){ return 0; }
    // 行ごとに分けてパース（簡易）
    int lines = count_lines(blob, len);
    t_pair *arr = malloc(sizeof(t_pair)*lines);
    if(!arr){ free(blob); return 0; }
    int idx=0, start=0;
    for(int i=0;i<=len;i++){
        if(i==len || blob[i]=='\n'){
            // 1行を作る
            int L = i-start;
            char *one = malloc(L+1);
            if(!one){ free(blob); free(arr); return 0; }
            for(int j=0;j<L;j++) one[j]=blob[start+j];
            one[L]='\0';
            if (L>0){ // 空行はスキップOK
                if(!parse_line(one, &arr[idx])){
                    // 行パース失敗は辞書エラー
                    free(one); free(blob);
                    // ここでこれまで確保した分を解放
                    for(int t=0;t<idx;t++){ free(arr[t].key); free(arr[t].value); }
                    free(arr);
                    return 0;
                }
                idx++;
            }
            free(one);
            start=i+1;
        }
    }
    free(blob);
    dict->items = arr;
    dict->size  = idx;
    return 1;
}

void free_dict(t_dict *dict){
    if(!dict || !dict->items) return;
    for(int i=0;i<dict->size;i++){
        free(dict->items[i].key);
        free(dict->items[i].value);
    }
    free(dict->items);
    dict->items=NULL; dict->size=0;
}
