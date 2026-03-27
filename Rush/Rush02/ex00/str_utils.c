/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:39:39 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 11:39:41 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int ft_strlen(char *s){ int i=0; if(!s) return 0; while(s[i]) i++; return i; }
int ft_is_space(char c){ return (c==' '||c=='\t'||c=='\n'||c=='\r'||c=='\v'||c=='\f'); }
int ft_is_digit(char c){ return (c>='0' && c<='9'); }

int ft_strcmp(char *a, char *b){
    int i=0;
    if (!a||!b) return (a!=b);
    while (a[i] && b[i] && a[i]==b[i]) i++;
    return ((unsigned char)a[i] - (unsigned char)b[i]);
}
int ft_strncmp(char *a, char *b, int n){
    int i=0;
    if (n<=0) return 0;
    while (i<n-1 && a[i] && b[i] && a[i]==b[i]) i++;
    return ((unsigned char)a[i] - (unsigned char)b[i]);
}

char *ft_strdup(char *s){
    int n=ft_strlen(s); char *p=malloc(n+1); int i=0;
    if(!p) return NULL; while(i<n){ p[i]=s[i]; i++; } p[i]='\0'; return p;
}

// 前後スペース削除（中は触らない）
char *ft_strtrim(char *s){
    int l=0, r, n;
    if(!s) return NULL;
    n=ft_strlen(s); r=n-1;
    while(l<n && ft_is_space(s[l])) l++;
    while(r>=l && ft_is_space(s[r])) r--;
    n = (r>=l)? (r-l+1) : 0;
    char *o = malloc(n+1);
    if(!o) return NULL;
    for(int i=0;i<n;i++) o[i]=s[l+i];
    o[n]='\0';
    return o;
}
