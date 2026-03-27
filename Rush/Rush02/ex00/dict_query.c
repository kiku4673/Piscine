/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_query.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamanak <yamanak@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:40:18 by kyamanak          #+#    #+#             */
/*   Updated: 2025/08/23 11:40:20 by kyamanak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

// 線形探索（サイズは大きくないはず）
char *dict_find(t_dict *dict, char *key){
    for(int i=0;i<dict->size;i++){
        if (ft_strcmp(dict->items[i].key, key)==0)
            return dict->items[i].value;
    }
    return NULL;
}
